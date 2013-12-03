#pragma once
#include <vector>
#include "Point.h"
using namespace std;
class IK
{
public:
	IK(void);
	IK(const Point& a_point);
	~IK(void);
	vector<double> getAngles() const;
private:
	Point m_point;
	vector<double> m_angles;
};

