
#ifndef MATH_AUX__
#define MATH_AUX__

#include <cstdlib>
#include <vector>

namespace MathAux
{
const double PI = 3.1415926;
const double EPS = 1.0e-14; // follow nsga-ii source code   ×ñÑ­NSGA IIÔ´´úÂë

inline double square(double n) { return n*n; }
inline double random(double lb, double ub) { return lb + (static_cast<double>(std::rand())/RAND_MAX)*(ub - lb); }
inline int randomInt(int lb, int ub) { return lb + rand() % (ub - lb + 1); }

// ASF(): achievement scalarization function 
double ASF(const std::vector<double> &objs, const std::vector<double> &weight);

// GuassianElimination(): used to calculate the hyperplane 
void GuassianElimination(std::vector<double> *px, std::vector< std::vector<double> > A, const std::vector<double> &b);

// PerpendicularDistance(): calculate the perpendicular distance from a point to a line 
double PerpendicularDistance(const std::vector<double> &direction, const std::vector<double> &point);
void randPermutation(int p[], int m);
}

#endif