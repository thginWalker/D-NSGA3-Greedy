
#include "alg_crossover.h"
#include "alg_individual.h"
#include "aux_math.h"
#include "problem_base.h"
#include "problem_self.h"
#include <cmath>
#include <algorithm>
#include <cstddef>

#include<iostream>
using namespace std;

using std::size_t;

// ----------------------------------------------------------------------
bool CCrossover::operator()(CIndividual *child1, 
										   CIndividual *child2, 
										   const CIndividual &parent1, 
										   const CIndividual &parent2, 
										   CProblemSelf &prob, double cr) const
{
	*child1 = parent1;
	*child2 = parent2;

	if (MathAux::random(0.0, 1.0) > cr) return false; // not crossovered

	CIndividual::TDecVec &c1 = child1->vars(), &c2 = child2->vars();
	const CIndividual::TDecVec &p1 = parent1.vars(), &p2 = parent2.vars();						
	int	split_idx = rand() % prob.num_agent;
	
	int n = 0;
	for (int i = 0; i < prob.num_agent; i++)
	{
		if (i < split_idx && prob.agt[i].exist)///
		{
			for (int j = n; j < n + prob.agt[i].tskn; j++)
			{
				c1[j] = p2[j];
				c2[j] = p1[j];
			}
		}
		else if(prob.agt[i].exist)////
		{
			for (int j = n; j < n + prob.agt[i].tskn; j++)
			{
				c1[j] = p1[j];
				c2[j] = p2[j];
			}
		}
		n = n + prob.agt[i].tskn;
	}
	return true;
}