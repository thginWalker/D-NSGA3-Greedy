#include "problem_base.h" 
#include "problem_self.h"
#include "alg_nsgaiii.h"
#include "alg_population.h"
#include "exp_experiment.h"
#include "alg_environmental_selection.h"
#include <stdlib.h>

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>



#include "log.h"
#include "aux_misc.h"
#include "exp_indicator.h"


#include "print_data.h"
#define I 8
#define islandnum 4
using namespace std;


int main()
{
	CPopulation migrate_solutions[I];
	CPopulation all_solutions[I];
	CPopulation solutions;	
	CProblemSelf* problem[I] = { 0 };	
	CNSGAIII nsgaiii;
	for (int k = 0; k < islandnum; k++)
	{
		ifstream islandconfig("island.ini");
		if (!islandconfig)
		{
			cout << "We need the island.ini file." << endl;
			return 1;
		}
		SetupExperiment(nsgaiii, &problem[k], islandconfig);
		nsgaiii.Init(&all_solutions[k], *problem[k]);
	}


	size_t  migratenum = nsgaiii.getMigrateNum();	

	for (int i = 0; i < islandnum; i++) {
		for (int j = 0; j < islandnum; j++) {
			nsgaiii.Pack(&migrate_solutions[j], &all_solutions[j], *problem[j], migratenum);
		}

		for (int k = 0; k < islandnum; k++)
		{
			for (int m = 0; m < islandnum; m++)
			{
				if (k != m)
					nsgaiii.Exchange(&all_solutions[k], &migrate_solutions[m], *problem[k]);
			}
			for (int k = 0; k < islandnum; k++)
			{
				for (unsigned int i = 0; i < all_solutions[k].size(); i++)
				{

					cout << all_solutions[k][i] << ' ';
					cout << endl;
				}
			}
		}

		for (int k = 0; k < islandnum; k++)
		{
			for (unsigned int i = 0; i < all_solutions[k].size(); i++)
			{
				cout << all_solutions[k][i] << endl;
			}
		}

		for (int n = 0; n < islandnum; n++) {
			nsgaiii.Solve(&all_solutions[n], *problem[n], i + 1);
		}

		for (int k = 0; k < islandnum; k++)
		{
			for (unsigned int i = 0; i < all_solutions[k].size(); i++)
			{
				cout << all_solutions[k][i] << endl;
			}
		}
	}


	for (int k = 0; k < islandnum; k++)
	{
		nsgaiii.Pack(&solutions, &all_solutions[k], *problem[k], all_solutions[k].size());
	}

	for (unsigned int i = 0; i < solutions.size(); i++) {
		cout << solutions[i] << endl;
	}

	string logfname = "Results\\" + nsgaiii.name() + "-" + problem[0]->name() + "-Run.txt"; 	
	ofstream fout;
	fout.open(logfname);
	for (unsigned int i = 0; i < solutions.size(); i++) {
		for (size_t f = 0; f < 4; f += 1) {
			fout << solutions[i].objs()[f] << " ";
		}
		fout << endl;
	}
	fout.close();


	for (int k = 0; k < islandnum; k++)
	{
		string logfname = "Results\\" + nsgaiii.name() + "-" + problem[k]->name() + "-Run" + to_string(k) + ".txt"; 		
		ofstream fout;
		fout.open(logfname);
		for (unsigned int i = 0; i < all_solutions[k].size(); i++) {
			for (size_t f = 0; f < 4; f += 1) {
				fout << all_solutions[k][i].objs()[f] << " ";
			}
			fout << endl;
		}
		fout.close();
	}

	for (int k = 0; k < islandnum; k++)
	{
		for (unsigned int i = 0; i < all_solutions[k].size(); i++)
		{

			cout << all_solutions[k][i] << ' ';

			cout << endl;
		}
	}

	cout << "solution end" << endl;

	system("pause");
	return 0;


}
