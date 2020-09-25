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
void CNSGAIII::Solve(CPopulation* solutions, CProblemSelf& problem) {

	CIndividual::SetTargetProblem(problem);
	vector<CReferencePoint> rps;	
	GenerateReferencePoints(&rps, problem.num_objectives(), obj_division_p_); 	
	size_t PopSize = rps.size();
	while (PopSize % 4) PopSize += 1;


	CPopulation pop[2] = { CPopulation(PopSize) };	
	CCrossover CSR(pc_);	
	CMutation Mut(1.0 / problem.num_variables());
	int cur = 0, next = 1;

	for (size_t t = 0; t < 1000; t += 1)//更改成变量
	{
		pop[cur].resize(PopSize * 2);
		for (size_t i = 0; i < PopSize; i += 2)
		{
			int father = rand() % PopSize,
				mother = rand() % PopSize;
			CSR(&pop[cur][PopSize + i], &pop[cur][PopSize + i + 1], pop[cur][father], pop[cur][mother], problem);//交叉

			Mut(&pop[cur][PopSize + i], &problem);
			Mut(&pop[cur][PopSize + i + 1], &problem);

			problem.Evaluate(&pop[cur][PopSize + i]);
			problem.Evaluate(&pop[cur][PopSize + i + 1]);
		}
		EnvironmentalSelection(&pop[next], &pop[cur], rps, PopSize);
		std::swap(cur, next);
	}

	for (size_t j = 0; j < PopSize; j++)
	{
		problem.Evaluate(&pop[cur][j]);
	}
	*solutions = pop[cur];
}



void CNSGAIII::Solve(CPopulation* solutions, CProblemSelf& problem, int number) {

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
	pop[cur] = *solutions;	
	size_t itersize = gen_num_ / 5;
	for (size_t t = 0; t < itersize; t += 1) {
		cout << "第" << t << "次迭代" << endl;
		pop[cur].resize(PopSize * 2);		
		for (size_t i = 0; i < PopSize; i += 2)
		{
			int father = rand() % PopSize,
				mother = rand() % PopSize;
			CSR(&pop[cur][PopSize + i], &pop[cur][PopSize + i + 1], pop[cur][father], pop[cur][mother], problem);						
			Mut(&pop[cur][PopSize + i], &problem);
			Mut(&pop[cur][PopSize + i + 1], &problem);

			problem.Evaluate(&pop[cur][PopSize + i]);
			problem.Evaluate(&pop[cur][PopSize + i + 1]);
		}
		EnvironmentalSelection(&pop[next], &pop[cur], rps, PopSize);
		std::swap(cur, next);
	}


	//更新评估函数值
	for (size_t j = 0; j < PopSize; j++)
	{
		problem.Evaluate(&pop[cur][j]);
	}

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
	//下面才是正式开始
	UpdateChromosome update;
	int cur = 0, next = 1;
	RandomInitialization(&pop[cur], problem);
	for (size_t j = 0; j < PopSize; j++)
	{
		problem.Evaluate(&pop[cur][j]);
	}
	//cout<< gen_num_ << endl;
	size_t itersize = gen_num_ / 5;
	for (size_t t = 0; t < itersize; t += 1)//更改成变量
	{
		cout << "第" << t << "次迭代" << endl;
		pop[cur].resize(PopSize * 2);
		for (size_t i = 0; i < PopSize; i += 2)
		{
			int father = rand() % PopSize,
				mother = rand() % PopSize;
			CSR(&pop[cur][PopSize + i], &pop[cur][PopSize + i + 1], pop[cur][father], pop[cur][mother], problem);//交叉
		
			Mut(&pop[cur][PopSize + i], &problem);
			Mut(&pop[cur][PopSize + i + 1], &problem);
			problem.Evaluate(&pop[cur][PopSize + i]);
			problem.Evaluate(&pop[cur][PopSize + i + 1]);
		}
		EnvironmentalSelection(&pop[next], &pop[cur], rps, PopSize);
		std::swap(cur, next);
	}


	cout << problem.num_agent << " " << problem.num_task << endl;

	for (size_t j = 0; j < PopSize; j++)
	{
		problem.Evaluate(&pop[cur][j]);
	}
	*solutions = pop[cur];

}


//判断两个个体的支配关系
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

//迁移学习解集
void CNSGAIII::Pack(CPopulation* migrate, CPopulation* all, CProblemSelf& problem, int num)
{
	CIndividual::SetTargetProblem(problem);//设置目标问题(重点★★)

	problem.loadChange(problem.num_agent, problem.num_task);
	vector<CReferencePoint> rps;	
	size_t PopSize = (*all).size();
	GenerateReferencePoints(&rps, problem.num_objectives(), obj_division_p_); 	
	EnvironmentalSelection(migrate, all, rps, num);

}



/////////////////////////////////////
//彼此交换解集
void CNSGAIII::Exchange(CPopulation* all, CPopulation* migrate, CProblemSelf& problem)
{
	CIndividual::SetTargetProblem(problem);//设置目标问题(重点★★)
	problem.loadChange(problem.num_agent, problem.num_task);	
	vector<CReferencePoint> rps;	
	GenerateReferencePoints(&rps, problem.num_objectives(), obj_division_p_);
	size_t PopSize = (*all).size();
	CPopulation pop[2] = { CPopulation(PopSize) };	
	CCrossover CSR(pc_);	
	CMutation Mut(1.0 / problem.num_variables());
	for (unsigned int i = 0; i < (*migrate).size(); i++) {
		for (unsigned int j = 0; j < (*all).size(); j++) {
			if (dominate((*migrate)[i], (*all)[j])) {
				int cur = 0, next = 1;
				pop[cur] = *all;												
				for (size_t t = 0; t < 10; t += 1) {
					pop[cur].resize(PopSize * 2 + 1);					
					for (size_t i = 0; i < PopSize; i += 2) {
						int father = rand() % PopSize,
							mother = rand() % PopSize;
						CSR(&pop[cur][PopSize + i], &pop[cur][PopSize + i + 1], pop[cur][father], pop[cur][mother], problem);												Mut(&pop[cur][PopSize + i], &problem);
						Mut(&pop[cur][PopSize + i + 1], &problem);

						problem.Evaluate(&pop[cur][PopSize + i]);
						problem.Evaluate(&pop[cur][PopSize + i + 1]);
					}
					pop[cur].pop_back();					
					EnvironmentalExchange(&pop[next], &pop[cur], migrate, rps, PopSize); 													std::swap(cur, next);
				}
				*all = pop[cur];
				break;
			}
			else {
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
	double fval = indv->getFvalue(w);	while (tag == true)
	{
		double bf = fval;		
		for (i = 0; i < num_agt; i++) {
			for (j = 0; j < problem.agt[i].tskn - 1; j++) {
				for (k = j + 1; k < problem.agt[i].tskn; k++) {
					swapij(indv, problem.atcnt[i] + j, problem.atcnt[i] + k);					
					problem.Evaluate(indv);					
					double gain = fval - indv->getFvalue(w);					
					if (gain < Eps) {
						swapij(indv, problem.atcnt[i] + j, problem.atcnt[i] + k);
					}
					else {
						tag = true;						
						fval = fval - gain;
					}
				}
			}
		}
		if (bf - fval < Eps) tag = false;
	}
}
