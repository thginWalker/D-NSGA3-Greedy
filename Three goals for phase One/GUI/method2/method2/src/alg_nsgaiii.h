#ifndef NSGAIII__
#define NSGAIII__

#include <cstddef>
#include <string>
#include <fstream>
#include <vector>

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
class UpdateChromosome;
using namespace std;

class CNSGAIII
{
public:
	explicit CNSGAIII();
	void Setup(std::ifstream& ifile);
	void Solve(CPopulation* solutions, CProblemSelf& prob);
	void Solve(CPopulation* solutions, CProblemSelf& problem, int number);
	void Init(CPopulation* solutions, CProblemSelf& prob);
	void Pack(CPopulation* all, CPopulation* migrate, CProblemSelf& prob, int num);
	void Exchange(CPopulation* all, CPopulation* migrate, CProblemSelf& problem);
	void localsearch(CIndividual* ind, double w[4], CProblemSelf& problem, int num_agt);	void swapij(CIndividual* indv, int i, int j);	void getClosestRefPoint(CIndividual x, vector<CReferencePoint> rps, double w[]);
	const std::string& name() const { return name_; }
	int getMigrateNum() { return mg_m_; }
private:
	std::string name_;
	std::vector<std::size_t> obj_division_p_;	std::size_t gen_num_;
	double	pc_, // 交叉率
		pm_, // 突变率
		eta_c_, // eta in SBX
		eta_m_; // 多项式突变中的eta
	int mg_m_;//迁移数目
};


#endif