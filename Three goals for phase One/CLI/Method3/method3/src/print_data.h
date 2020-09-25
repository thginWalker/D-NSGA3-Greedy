#ifndef PRINT_DATA_
#define PRINT_DATA_//²âÊÔÍ·ÎÄ¼þ


#include<iostream>
#include"problem_self.h"
#include"alg_population.h"

class CProblemSelf;
class CPopulation;

class Print 
{
public:
	void PrintAgent(CProblemSelf** prob);
	void PrintTasks(CProblemSelf** prob);
	void PrintAgent(CProblemSelf& prob);
	void PrintTasks(CProblemSelf& prob);
	void PrintChromosome(CPopulation* prob);
	void PrintObject(CPopulation* prob);


};


#endif