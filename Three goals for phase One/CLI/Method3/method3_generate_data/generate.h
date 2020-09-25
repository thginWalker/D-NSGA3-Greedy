#ifndef GENERATE_
#define CENERATE_

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include<string>
#include<fstream>
#include <iostream>

#define M 800
#define N 3000

struct Agent	//定义智能体 
{
	double x;//location x
	double y;//location y
	double res;//resources
	int tsks[N];
	int tskn;
	int id;//方便操作
	int islandid;//island序号,方便操作
};
struct Task		
{
	double x;//location_x;
	double y;//location_y;
	double start_t;//earliest start time
	double end_t;//lastest start time
	double time_cost;
	double res_cost;
	double gain;
	int agtn;
	int agts[M];
	int id;
};




void init();


int randInt(int a, int b);

double randDouble(double a, double b);



void selectTasks(int id, int n, int idx[], int start);


void randPermutation(int p[], int m);

void divTasks(int p);

void genAgent();

bool genTask();

void dynamicAgent(int number);

void dynamicTask(int number);

#endif

