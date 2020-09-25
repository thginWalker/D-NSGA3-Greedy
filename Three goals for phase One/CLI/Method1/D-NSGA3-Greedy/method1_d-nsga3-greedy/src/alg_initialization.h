#ifndef INITIALIZATION__
#define INITIALIZATION__


// ----------------------------------------------------------------------
//		CRandomInitialization
// ----------------------------------------------------------------------

class CIndividual;
class CPopulation;
class CProblemSelf;

class CRandomInitialization
{
public:
	void operator()(CPopulation *pop, const CProblemSelf &prob) const;
	void operator()(CIndividual *indv, const CProblemSelf &prob) const;
};

extern CRandomInitialization RandomInitialization;

#endif