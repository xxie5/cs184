#include "IK.h"
#pragma once
#include <vector>
#include "Point.h"
#include <math.h> 
using namespace std;

double px,pz;
double l1,l2;

IK::IK(void)
{
}

IK(const Point& a_point, double a, double b) 
{
  px = a_point.getX();
  pz = a_point.getY();
  l1 = a;
  l2 = b;
}

IK::~IK(void)
{
}

vector<double> getAngles() const {
  vector<double> ret(2,0);
  ret[1] = acos((pz * pz + px * px - l1 * l1 - l2 * l2)/(2 * l1 * l2));
  ret[0] = (-pz * l2 * sin(ret[1]) + px * (l1 + l2 * cos(ret[1])))/(px * l2 * sin(ret[1]) + pz * (l1 + l2 * cos(ret[1])));
  return ret;
  
}
