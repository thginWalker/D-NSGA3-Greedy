
#ifndef EXPERIMENT__
#define EXPERIMENT__

#include <fstream>

class CNSGAIII;
class CProblemSelf;
//开始实验
void SetupExperiment(CNSGAIII &algo, CProblemSelf **prob, std::ifstream &ifile);

#endif