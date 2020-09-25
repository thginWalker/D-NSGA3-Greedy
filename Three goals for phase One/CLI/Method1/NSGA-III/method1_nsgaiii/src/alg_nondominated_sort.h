#ifndef NONDOMINATED_SORT__
#define NONDOMINATED_SORT__

#include <vector>

class BComparator;
class CPopulation;

class CNondominatedSort
{
public:
	explicit CNondominatedSort(const BComparator& d) :dominate(d) {}


	CNondominatedSort(const CNondominatedSort&);
	CNondominatedSort& operator= (const CNondominatedSort&); //‘ÀÀ„∑˚÷ÿ‘ÿ=


	typedef std::vector<std::size_t> TFrontMembers; // a set of indices of individuals in a certain front

	typedef std::vector<TFrontMembers> TFronts; // a set of fronts

	TFronts operator()(const CPopulation& pop) const;

private:
	const BComparator& dominate;
};

extern CNondominatedSort NondominatedSort;

#endif