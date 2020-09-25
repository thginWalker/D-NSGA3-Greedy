
#ifndef PROBLEM_FACTORY__
#define PROBLEM_FACTORY__

#include "problem_self.h"
#include <fstream>

CProblemSelf *GenerateProblem(std::ifstream &ifile);


#endif