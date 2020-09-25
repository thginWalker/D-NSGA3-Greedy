
#include "alg_mutation.h"
#include "alg_individual.h"
#include "aux_math.h"
#include "problem_base.h"
#include "problem_self.h"
#include <cstddef>
#include <algorithm>
using std::size_t;


// ---------------------------------------------------------------------
bool CMutation::operator()(CIndividual *indv, double mr, CProblemSelf *cps) const
{
	bool mutated = false;
	int agtnum = cps->num_agent;
	int tsknum = cps->num_task;
	int t[1000];
	CIndividual::TDecVec &x = indv->vars();
	int n = 0;
    for (size_t i=0; i<agtnum; i+=1)
    {
		if (MathAux::random(0.0, 1.0) <= mr)
        {
			mutated = true;
			MathAux::randPermutation(t, cps->agt[i].tskn);			
			for (int j = n; j < n+cps->agt[i].tskn; j++)
			{
				x[j] = cps->agt[i].tsks[t[j - n]];
			}
        }
		n = n + cps->agt[i].tskn;
    }
	return mutated;
}// CPolynomialMutation

