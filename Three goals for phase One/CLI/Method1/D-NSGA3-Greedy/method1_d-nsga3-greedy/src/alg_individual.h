#ifndef INDIVIDUAL__
#define INDIVIDUAL__

#include <vector>
#include <ostream>

// ----------------------------------------------------------------------
//		CIndividual
// ----------------------------------------------------------------------

class BProblem;

class CIndividual
{
public:
	typedef int TGene;
	typedef std::vector<TGene> TDecVec;
	typedef std::vector<double> TObjVec;

	explicit CIndividual(std::size_t num_vars = 0, std::size_t num_objs = 0);

	TDecVec & vars() { return variables_; }
	const TDecVec & vars() const { return variables_; }

	TDecVec & svars() { return svariables_; }
	const TDecVec & svars() const { return svariables_; }

	TObjVec & objs() { return objectives_; }
	const TObjVec & objs() const { return objectives_; }

	TObjVec & sobjs() { return sobjectives_; }
	const TObjVec & sobjs() const { return sobjectives_; }

	TObjVec & conv_objs() { return converted_objectives_; }
	void clone(CIndividual x);
	double getFvalue(double w[]);
	const TObjVec & conv_objs() const { return converted_objectives_; }

	// if a target problem is set, memory will be allocated accordingly in the constructor
	static void SetTargetProblem(const BProblem &p) { target_problem_ = &p; }
	static void removedup(CIndividual * ind, int agtnum);
	static const BProblem & TargetProblem();
	//static const int agtnum = 10, tsknum = 50;//
private:
	TDecVec variables_;
	TDecVec svariables_;
	TObjVec objectives_;
	TObjVec sobjectives_;
	TObjVec converted_objectives_;

	static const BProblem *target_problem_;
};

std::ostream & operator << (std::ostream &os, const CIndividual &indv);

#endif
