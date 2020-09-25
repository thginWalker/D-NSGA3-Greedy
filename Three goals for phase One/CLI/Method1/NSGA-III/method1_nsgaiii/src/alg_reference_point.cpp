#include "alg_reference_point.h"
#include "alg_population.h"
#include "aux_math.h"

#include <limits>
using namespace std;



void CReferencePoint::clear()
{
	member_size_ = 0;
	potential_members_.clear();
}
// ----------------------------------------------------------------------
void CReferencePoint::AddMember()
{
	member_size_ += 1;
}
// ----------------------------------------------------------------------
void CReferencePoint::AddPotentialMember(std::size_t member_ind, double distance) //添加潜在的成员
{
	potential_members_.push_back(make_pair(member_ind, distance));
}
// ----------------------------------------------------------------------
int CReferencePoint::FindClosestMember() const
{
	double min_dist = numeric_limits<double>::max();
	int min_indv = -1;
	for (size_t i = 0; i < potential_members_.size(); i += 1)
	{
		if (potential_members_[i].second < min_dist)
		{
			min_dist = potential_members_[i].second;
			min_indv = potential_members_[i].first;
		}
	}

	return min_indv;
}
// ----------------------------------------------------------------------
int CReferencePoint::RandomMember() const
{
	if (potential_members_.size() > 0)
	{
		return potential_members_[rand() % potential_members_.size()].first;
	}
	else
	{
		return -1;
	}
}
// ----------------------------------------------------------------------
void CReferencePoint::RemovePotentialMember(std::size_t member_ind)
{
	for (size_t i = 0; i < potential_members_.size(); i += 1)
	{
		if (potential_members_[i].first == member_ind)
		{
			potential_members_.erase(potential_members_.begin() + i);
			return;
		}
	}
}


// ----------------------------------------------------------------------
// Other utility functions 其他实用功能
// ----------------------------------------------------------------------
//生成递归 //////////////???????????????????????????????????????暂时还没看懂
void generate_recursive(vector<CReferencePoint>* rps, CReferencePoint* pt, size_t num_objs,
	size_t left, size_t total, size_t element)
{
	if (element == num_objs - 1)//从上一层可以看到element为递归的次数,由于递归从0开始,
	{
		pt->pos()[element] = static_cast<double>(left) / total;
		rps->push_back(*pt);
	}
	else
	{
		for (size_t i = 0; i <= left; i += 1)
		{
			pt->pos()[element] = static_cast<double>(i) / total;
			generate_recursive(rps, pt, num_objs, left - i, total, element + 1);
		}
	}
}
// ----------------------------------------------------------------------
//产生参考点
/*
rps 存储参考点
M 参考点的M个目标
p 是涉及等分数的p
*/
void GenerateReferencePoints(vector<CReferencePoint>* rps, size_t M, const std::vector<std::size_t>& p)
{
	CReferencePoint pt(M);//类的初始化(position_ = M)

	generate_recursive(rps, &pt, M, p[0], p[0], 0);//递归

	if (p.size() > 1) // two layers of reference points (Check Fig. 4 in NSGA-III paper)两层参考点
	{
		vector<CReferencePoint> inside_rps;//inside_rps(猜测:内部参考点)
		generate_recursive(&inside_rps, &pt, M, p[1], p[1], 0);

		double center = 1.0 / M;

		for (size_t i = 0; i < inside_rps.size(); i += 1)
		{
			for (size_t j = 0; j < inside_rps[i].pos().size(); j += 1)
			{
				inside_rps[i].pos()[j] = (center + inside_rps[i].pos()[j]) / 2; // (k=num_divisions/M, k, k, ..., k) is the center point
			}
			rps->push_back(inside_rps[i]);//添加内部"点"
		}
	}
}
// ----------------------------------------------------------------------
void Associate(std::vector<CReferencePoint>* prps, const CPopulation& pop, const CNondominatedSort::TFronts& fronts)
{
	std::vector<CReferencePoint>& rps = *prps;

	for (size_t t = 0; t < fronts.size(); t += 1)
	{
		for (size_t i = 0; i < fronts[t].size(); i += 1)
		{
			size_t min_rp = rps.size();
			double min_dist = numeric_limits<double>::max();
			for (size_t r = 0; r < rps.size(); r += 1)
			{
				double d = MathAux::PerpendicularDistance(rps[r].pos(), pop[fronts[t][i]].conv_objs());
				if (d < min_dist)
				{
					min_dist = d;
					min_rp = r;
				}
			}

			if (t + 1 != fronts.size()) // associating members in St/Fl (only counting)
			{
				rps[min_rp].AddMember();
			}
			else
			{
				rps[min_rp].AddPotentialMember(fronts[t][i], min_dist);
			}

		}// for - members in front
	}// for - fronts
}
// ----------------------------------------------------------------------