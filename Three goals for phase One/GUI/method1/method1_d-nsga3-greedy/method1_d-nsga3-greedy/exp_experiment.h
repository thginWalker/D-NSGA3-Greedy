
#ifndef EXPERIMENT__
#define EXPERIMENT__

#include <fstream>

class CNSGAIII;
class CProblemSelf;

void SetupExperiment(CNSGAIII &algo, CProblemSelf **prob, std::ifstream &ifile);

#endif