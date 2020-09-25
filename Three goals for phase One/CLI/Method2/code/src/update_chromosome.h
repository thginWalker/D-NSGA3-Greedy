#ifndef UPDATE_CHROMOSOME__
#define UPDATE_CHROMOSOME__
#include<fstream>
#include "print_data.h"
#define MU 60
#define NU 100

class CPopulation;
class CProblemSelf;


class UpdateChromosome
{
public :

	void loadUpdateEnvironment(int number);
	void updateChromosome(CPopulation* prob, CProblemSelf* problem);
protected:
	int addagentnum;
	Agent adagt[MU];
	int addtasknum;
	Task adtsk[NU];
	int cutagentnum;
	int ctagt[MU];
	int cutasknum;
	int ctskn[NU];
};



#endif
