#ifndef ENVIRONMENTAL_SELECTION__
#define ENVIRONMENTAL_SELECTION__
#include <vector>
#include<cmath>

// ----------------------------------------------------------------------
//	The environmental selection mechanism is the key innovation of 
//  the NSGA-III algorithm.
//
//  Check Algorithm I in the original paper of NSGA-III.
// ----------------------------------------------------------------------

class CPopulation;
class CReferencePoint;

void EnvironmentalSelection(CPopulation *pnext, // population in the next generation
							CPopulation *pcur,  // population in the current generation
							std::vector<CReferencePoint> rps, // the set of reference points
							std::size_t PopSize);

void EnvironmentalExchange(CPopulation* pnext, // population in the next generation
	CPopulation* pcur,  // population in the current generation
	CPopulation* migrate,
	std::vector<CReferencePoint> rps, // the set of reference points
	std::size_t PopSize);

void saveLearningSolution(CPopulation* pnext, // population in the next generation
	CPopulation* pcur,  // population in the current generation
	std::vector<CReferencePoint> rps, // the set of reference points
	std::size_t PopSize,
	int islandnum);



#endif
