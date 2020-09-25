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
	CNondominatedSort& operator= (const CNondominatedSort&);
	typedef std::vector<std::size_t> TFrontMembers; 		typedef std::vector<TFrontMembers> TFronts;
	TFronts operator()(const CPopulation& pop) const;

private:
	const BComparator& dominate;
};

extern CNondominatedSort NondominatedSort;






#endif