#include "alg_nsgaiii.h"
#include "problem_base.h"
#include "alg_individual.h"
#include "alg_reference_point.h"
#include "alg_population.h"

#include "alg_initialization.h"
#include "alg_crossover.h"
#include "alg_mutation.h"
#include "alg_environmental_selection.h"


#include "log.h"
#include "problem_self.h"
#include "aux_math.h"
#include <vector>
#include <fstream>

//��������ļ�
#include "update_chromosome.h"


using namespace std;

CNSGAIII::CNSGAIII() :
	name_("NSGAIII"),
	gen_num_(1),
	pc_(1.0), // default setting in NSGA-III (IEEE tEC 2014) 
	eta_c_(30), // default setting
	eta_m_(20) // default setting
{
}
// ----------------------------------------------------------------------
void CNSGAIII::Setup(ifstream& ifile)
{
	if (!ifile) return;

	string dummy;
	ifile >> dummy >> dummy >> name_;

	size_t p1 = 0, p2 = 0;
	ifile >> dummy >> dummy >> p1 >> p2;

	obj_division_p_.push_back(p1);

	if (!ifile) ifile.clear();
	else obj_division_p_.push_back(p2);

	ifile >> dummy >> dummy >> gen_num_;
	ifile >> dummy >> dummy >> pc_; 
	ifile >> dummy >> dummy >> eta_c_;
	ifile >> dummy >> dummy >> eta_m_;
	ifile >> dummy >> dummy >> mg_m_;
}

// ----------------------------------------------------------------------
void CNSGAIII::Solve(CPopulation* solutions, CProblemSelf& problem)
{

	CIndividual::SetTargetProblem(problem);

	vector<CReferencePoint> rps;
	GenerateReferencePoints(&rps, problem.num_objectives(), obj_division_p_);
	size_t PopSize = rps.size();

	while (PopSize % 4) PopSize += 1; 

	//CPopulation pop[2] = { CPopulation(PopSize) };
	CPopulation pop[2];
	pop[0] = CPopulation(PopSize);
	pop[1] = CPopulation(PopSize);
	CCrossover CSR(pc_);
	CMutation Mut(1.0 / problem.num_variables());

	//���������ʽ��ʼ
	int cur = 0, next = 1;

	for (size_t t = 0; t < 50; t += 1)//�Ŵ�����gen_num_ = 1000
	{
		pop[cur].resize(PopSize * 2);
		for (size_t i = 0; i < PopSize; i += 2)
		{
			int father = rand() % PopSize,
				mother = rand() % PopSize;
			CSR(&pop[cur][PopSize + i], &pop[cur][PopSize + i + 1], pop[cur][father], pop[cur][mother], problem);//����
			//��������������ֱ���б���
			Mut(&pop[cur][PopSize + i], &problem);
			Mut(&pop[cur][PopSize + i + 1], &problem);

			problem.Evaluate(&pop[cur][PopSize + i]);
			problem.Evaluate(&pop[cur][PopSize + i + 1]);
		}
		EnvironmentalSelection(&pop[next], &pop[cur], rps, PopSize);
		std::swap(cur, next);
	}
	//������������ֵ
	for (size_t j = 0; j < PopSize; j++)
	{
		problem.Evaluate(&pop[cur][j]);
	}
	*solutions = pop[cur];
}



void CNSGAIII::Solve(CPopulation* solutions, CProblemSelf& problem, int number)
{

	CIndividual::SetTargetProblem(problem);
	problem.loadChange(problem.num_agent, problem.num_task);
	vector<CReferencePoint> rps;
	GenerateReferencePoints(&rps, problem.num_objectives(), obj_division_p_); 
	size_t PopSize = rps.size();
	cout << PopSize << endl;
	while (PopSize % 4) PopSize += 1;

	CPopulation pop[2] = { CPopulation(PopSize) };
	CCrossover CSR(pc_);
	CMutation Mut(1.0 / problem.num_variables());


	UpdateChromosome update;
	int cur = 0, next = 1;
	pop[cur] = *solutions;//��Ҫ���벿��
	//���޸�Ϊ5��  t < 50
	for (size_t t = 0; t < 50; t += 1)//�Ŵ�����gen_num_ = 1000
	{
		cout << "��" << t << "�ε���" << endl;
		pop[cur].resize(PopSize * 2);
		for (size_t i = 0; i < PopSize; i += 2)
		{
			int father = rand() % PopSize,
				mother = rand() % PopSize;
			CSR(&pop[cur][PopSize + i], &pop[cur][PopSize + i + 1], pop[cur][father], pop[cur][mother], problem);//����
	
			Mut(&pop[cur][PopSize + i], &problem);
			Mut(&pop[cur][PopSize + i + 1], &problem);

			problem.Evaluate(&pop[cur][PopSize + i]);
			problem.Evaluate(&pop[cur][PopSize + i + 1]);
		}

		EnvironmentalSelection(&pop[next], &pop[cur], rps, PopSize);
		std::swap(cur, next);
	}

	//50��֮��,���Ļ���������Ǩ��ѧϰ
	//�ȸ�����Ϣ,Ȼ����Ǩ��ѧϰ
	update.loadUpdateEnvironment(number);//�͵�2�μ���
	update.updateChromosome(&pop[cur], &problem);
	problem.loadChange(problem.num_agent, problem.num_task);
	//������������ֵ
	for (size_t j = 0; j < PopSize; j++)
	{
		problem.Evaluate(&pop[cur][j]);
	}
	//��Ϣ�Ѿ�����
	cout << problem.num_agent << " " << problem.num_task << endl;

	*solutions = pop[cur];

}

void CNSGAIII::Init(CPopulation* solutions, CProblemSelf& problem)
{
	CIndividual::SetTargetProblem(problem);

	vector<CReferencePoint> rps;
	GenerateReferencePoints(&rps, problem.num_objectives(), obj_division_p_); 
	size_t PopSize = rps.size();
	while (PopSize % 4) PopSize += 1; 

	CPopulation pop[2] = { CPopulation(PopSize) };
	CCrossover CSR(pc_);
	CMutation Mut(1.0 / problem.num_variables());

	//���������ʽ��ʼ
	UpdateChromosome update;
	int cur = 0, next = 1;
	RandomInitialization(&pop[cur], problem);
	for (size_t j = 0; j < PopSize; j++)
	{
		problem.Evaluate(&pop[cur][j]);
	}

	for (size_t t = 0; t < 50; t += 1)//�Ŵ�����gen_num_ = 1000
	{
		cout << "��" << t << "�ε���" << endl;
		pop[cur].resize(PopSize * 2);
		for (size_t i = 0; i < PopSize; i += 2)
		{
			int father = rand() % PopSize,
				mother = rand() % PopSize;
			CSR(&pop[cur][PopSize + i], &pop[cur][PopSize + i + 1], pop[cur][father], pop[cur][mother], problem);//����
			//��������������ֱ���б���
			Mut(&pop[cur][PopSize + i], &problem);
			Mut(&pop[cur][PopSize + i + 1], &problem);
			problem.Evaluate(&pop[cur][PopSize + i]);
			problem.Evaluate(&pop[cur][PopSize + i + 1]);
		}
		EnvironmentalSelection(&pop[next], &pop[cur], rps, PopSize);
		std::swap(cur, next);
	}


	update.loadUpdateEnvironment(0);
	update.updateChromosome(&pop[cur], &problem);
	problem.loadChange(problem.num_agent, problem.num_task);//���¼���
	//��Ϣ�Ѿ�����
	cout << problem.num_agent << " " << problem.num_task << endl;

	for (size_t j = 0; j < PopSize; j++)
	{
		problem.Evaluate(&pop[cur][j]);
	}
	*solutions = pop[cur];

}


//�ж����������֧���ϵ
bool dominate(CIndividual& l, CIndividual& r)
{
	bool better = false;
	for (size_t f = 0; f < l.objs().size(); f += 1)
	{
		if (l.objs()[f] > r.objs()[f])
			return false;
		else if (l.objs()[f] < r.objs()[f])
			better = true;
	}
	return better;
}

//Ǩ��ѧϰ�⼯
void CNSGAIII::Pack(CPopulation* migrate, CPopulation* all, CProblemSelf& problem, int num)
{
	CIndividual::SetTargetProblem(problem);

	problem.loadChange(problem.num_agent, problem.num_task);

	vector<CReferencePoint> rps;
	size_t PopSize = (*all).size();
	GenerateReferencePoints(&rps, problem.num_objectives(), obj_division_p_); 
	EnvironmentalSelection(migrate, all, rps, num);


}



/////////////////////////////////////
//�˴˽����⼯
void CNSGAIII::Exchange(CPopulation* all, CPopulation* migrate, CProblemSelf& problem)
{
	CIndividual::SetTargetProblem(problem);
	problem.loadChange(problem.num_agent, problem.num_task);
	vector<CReferencePoint> rps;
	GenerateReferencePoints(&rps, problem.num_objectives(), obj_division_p_); 

	size_t PopSize = (*all).size();

	CPopulation pop[2] = { CPopulation(PopSize) };
	CCrossover CSR(pc_);
	CMutation Mut(1.0 / problem.num_variables());

	for (unsigned int i = 0; i < (*migrate).size(); i++)
	{
		for (unsigned int j = 0; j < (*all).size(); j++)
		{//�жϷ�֧���ϵ
			//< true 1  (֧��)
			//> false 0
			if (dominate((*migrate)[i], (*all)[j]))//֧��
			{
				int cur = 0, next = 1;
				///////////////////
				pop[cur] = *all;
				//////////////////////////////////////10Ϊ����/////////
				for (size_t t = 0; t < 10; t += 1)//�Ŵ�����gen_num_ = 1000
				{

					pop[cur].resize(PopSize * 2 + 1);
					for (size_t i = 0; i < PopSize; i += 2)
					{
						int father = rand() % PopSize,
							mother = rand() % PopSize;
						CSR(&pop[cur][PopSize + i], &pop[cur][PopSize + i + 1], pop[cur][father], pop[cur][mother], problem);//����

						Mut(&pop[cur][PopSize + i], &problem);
						Mut(&pop[cur][PopSize + i + 1], &problem);

						problem.Evaluate(&pop[cur][PopSize + i]);
						problem.Evaluate(&pop[cur][PopSize + i + 1]);
					}
					pop[cur].pop_back();
					EnvironmentalExchange(&pop[next], &pop[cur], migrate, rps, PopSize);
	
					std::swap(cur, next);
				}
				*all = pop[cur];
				break;
			}
			else {//��֧��
			   ///////////////////////////////////////////////
			   //��2���ֶ�̰���Ż�
				double w[4];
				for (int j = 0; j < 4; j++)
				{
					w[j] = (*migrate)[i].objs()[j];
				}
				
				localsearch(&(*migrate)[i], w, problem, problem.num_agent);
			}
		}
	}
}

//���Ӳ���
void CNSGAIII::swapij(CIndividual* indv, int i, int j)
{
	CIndividual::TDecVec& x = indv->vars();
	int w = x[i];
	x[i] = x[j];
	x[j] = w;
}

void CNSGAIII::getClosestRefPoint(CIndividual x, vector<CReferencePoint> rps, double w[])
{
	double mind = 1000;
	int mini = 0;
	for (int i = 0; i < rps.size(); i++)
	{
		double d = MathAux::PerpendicularDistance(rps[i].pos(), x.objs());
		if (d < mind)
		{
			mind = d;
			mini = i;
		}
	}
	double s = 0;
	for (int j = 0; j < 4; j++)
	{
		w[j] = fabs(x.objs()[j] - rps[mini].pos()[j]);
		s = s + w[j];
	}
	for (int j = 0; j < 4; j++)
		w[j] = w[j] / s;
}

void CNSGAIII::localsearch(CIndividual* indv, double w[4], CProblemSelf& problem, int num_agt)
{
	int i, j, k;
	CIndividual x;
	bool tag = true;
	int iter = 0;
	double Eps = 0.001;
	double fval = indv->getFvalue(w);
	while (tag == true)
	{
		double bf = fval;
		for (i = 0; i < num_agt; i++)
		{
			for (j = 0; j < problem.agt[i].tskn - 1; j++)
			{
				for (k = j + 1; k < problem.agt[i].tskn; k++)
				{
					swapij(indv, problem.atcnt[i] + j, problem.atcnt[i] + k);
					problem.Evaluate(indv);
					double gain = fval - indv->getFvalue(w);
					if (gain < Eps)
					{
						swapij(indv, problem.atcnt[i] + j, problem.atcnt[i] + k);
					}
					else
					{
						tag = true;
						fval = fval - gain;
					}
				}
			}
		}
		if (bf - fval < Eps) tag = false;
	}
}
