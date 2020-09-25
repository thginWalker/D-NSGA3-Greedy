#include "alg_initialization.h"
#include "problem_self.h"
#include "alg_individual.h"
#include "alg_population.h"
#include "aux_math.h"

#include <cstddef>
using std::size_t;

CRandomInitialization RandomInitialization;

void CRandomInitialization::operator()(CIndividual *indv, const CProblemSelf &prob) const
{
	int t[1000];
	CIndividual::TDecVec &x = indv->vars();
	x.resize(prob.num_variables());
	for (int i = 0; i < x.size(); i++)
		x[i] = 0;
	int n = 0;;
	for (int i = 0; i < prob.num_agent; i++)
	{
		MathAux::randPermutation(t, prob.agt[i].tskn);
		for (int j = n; j < n + prob.agt[i].tskn; j++)
			x[j] = prob.agt[i].tsks[t[j - n]];
		n = n + prob.agt[i].tskn;
	}
}
// ----------------------------------------------------------------------
void CRandomInitialization::operator()(CPopulation *pop, const CProblemSelf &prob) const
{
	for (size_t i=0; i<pop->size(); i+=1)
	{
		(*this)( &(*pop)[i], prob );
	}
}