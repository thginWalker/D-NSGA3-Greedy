#ifndef NSGAIII__
#define NSGAIII__
//#include "alg_reference_point.h"
#include <cstddef>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
// ----------------------------------------------------------------------------------
//		NSGAIII
//
// Deb and Jain, "An Evolutionary Many-Objective Optimization Algorithm Using 
// Reference-point Based Non-dominated Sorting Approach, Part I: Solving Problems with 
// Box Constraints," IEEE Transactions on Evolutionary Computation, to appear.
//
// http://dx.doi.org/10.1109/TEVC.2013.2281535
// ----------------------------------------------------------------------------------

class CProblemSelf;
class CPopulation;
class CIndividual;
class CReferencePoint;

class CNSGAIII
{
public:
	explicit CNSGAIII();
	void Setup(std::ifstream &ifile);
	void Solve(CPopulation *solutions, CProblemSelf &prob, int num_agt);
	void clearInvalid(CIndividual *ind, CProblemSelf &problem);
	void localsearch(CIndividual *ind, double w[4], CProblemSelf &problem, int num_agt);
	void swapij(CIndividual *indv, int i, int j);
	void getClosestRefPoint(CIndividual x, vector<CReferencePoint> rps, double w[]);
	const std::string & name() const { return name_; }
private:
	std::string name_;
	std::vector<std::size_t> obj_division_p_;
	std::size_t gen_num_;
	double	pc_, // crossover rate
			pm_, // mutation rate
			eta_c_, // eta in SBX
			eta_m_; // eta in Polynomial Mutation
};


#endif