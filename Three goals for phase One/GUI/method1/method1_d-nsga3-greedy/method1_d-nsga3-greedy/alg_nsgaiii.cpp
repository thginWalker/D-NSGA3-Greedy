#include "alg_nsgaiii.h"
#include "problem_base.h"
#include "alg_individual.h"
#include "alg_reference_point.h"
#include "alg_population.h"

#include "alg_initialization.h"
#include "alg_crossover.h"
#include "alg_mutation.h"
#include "alg_environmental_selection.h"

#include "gnuplot_interface.h"
#include "log.h"
#include "windows.h" // for Sleep()
#include "problem_self.h"
#include "aux_math.h"
#include<cmath>
#include <vector>
#include <fstream>

using namespace std;

CNSGAIII::CNSGAIII(): 
	name_("NSGAIII"),
	gen_num_(1),
	pc_(1.0), // default setting in NSGA-III (IEEE tEC 2014)
	eta_c_(30), // default setting
	eta_m_(20) // default setting
{
}
// ----------------------------------------------------------------------
void CNSGAIII::Setup(ifstream &ifile)
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
}
void CNSGAIII::swapij(CIndividual *indv, int i, int j)
{
	CIndividual::TDecVec &x = indv->vars();
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
	for (int j = 0; j < 4;j++)
		w[j] = w[j]/s;
}

void CNSGAIII::localsearch(CIndividual *indv, double w[4], CProblemSelf &problem, int num_agt)
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
		for (i = 0; i<num_agt; i++)
		{
			for (j = 0; j<problem.agt[i].tskn - 1; j++)
			{
				for (k = j + 1; k<problem.agt[i].tskn; k++)
				{
					swapij(indv, problem.atcnt[i]+j, problem.atcnt[i]+k);
					problem.Evaluate(indv);
					double gain = fval - indv->getFvalue(w);
					if (gain<Eps)
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
		if (bf-fval<Eps) tag = false;
	 
	}
}
// ----------------------------------------------------------------------
void CNSGAIII::Solve(CPopulation *solutions, CProblemSelf &problem,int num_agt)
{
	double w[4];
	int gen1iter = 50;
	int iter_num = gen_num_ / gen1iter;
	CIndividual::SetTargetProblem(problem);
	
	vector<CReferencePoint> rps;
	GenerateReferencePoints(&rps, problem.num_objectives(), obj_division_p_); 
	size_t PopSize = rps.size();
	while (PopSize%4) PopSize += 1;

//	CPopulation pop[2]={CPopulation(PopSize)};
    //C++ 11中用{}初始化，有等于号和没有等于号
    //tuple<int, string> s = {1, "1234"};
    //tuple<int, string> s{1, "1234"};
    //第一种叫copy-initialization, 第二种叫braced-initialization
    CPopulation pop[2];
    pop[0] = CPopulation(PopSize);
    pop[1] = CPopulation(PopSize);
    CCrossover CSR(pc_);
	CMutation Mut(1.0/problem.num_variables());

	Gnuplot gplot;

	int cur = 0, next = 1;
	RandomInitialization(&pop[cur], problem);
	for (size_t i=0; i<PopSize; i+=1)
	{
		problem.Evaluate(&pop[cur][i]);
	}
	//iter_num = 1;
	for (size_t t = 0; t < iter_num; t += 1)
	{
		printf("\n-----------> %d th iteration <------------\n ", t);
		for (int k = 0; k < gen1iter; k += 1)
		{
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
		
		for (int i = 0; i < PopSize; i++)
		{
 
			for (int j = 0; j < 4; j++)
			{
				w[j] = rps[i%rps.size()].pos()[j];
			}
			localsearch(&pop[cur][i],w, problem, num_agt);
		}
 
	}
	printf("\n");
 
	*solutions = pop[cur];
}
