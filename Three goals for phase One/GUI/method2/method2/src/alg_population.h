#ifndef POPULATION__
#define POPULATION__

#include "alg_individual.h"
#include"alg_population.h"

#include <vector>

class CPopulation
{
public:
	explicit CPopulation(std::size_t s = 0) :individuals_(s) {}

	CIndividual& operator[](std::size_t i) { return individuals_[i]; }
	const CIndividual& operator[](std::size_t i) const { return individuals_[i]; }

	std::size_t size() const { return individuals_.size(); }	void resize(size_t t) { individuals_.resize(t); }	void push_back(const CIndividual& indv) { individuals_.push_back(indv); }	void clear() { individuals_.clear(); }		void  pop_back() { individuals_.pop_back(); }
private:
	std::vector<CIndividual> individuals_;
};

#endif