#pragma once
#include <vector>
#include "Point.h"
using namespace std;
class IK
{
public:
	IK(void);
	IK(const Point& a_point, double a, double b);
	~IK(void);
	vector<double> getAngles() const;
private:
	double px,py,l1,l2;
	Point m_point;
	vector<double> m_angles;
};

