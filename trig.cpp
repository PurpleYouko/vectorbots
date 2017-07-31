#include "trig.h"

float findHyp(float ValX, float ValY)
{
	return sqrt((ValX * ValX) + (ValY * ValY));
}

float findAngle(float ValX, float ValY)
{
	long double CosAngle;
	float Hyp = findHyp(ValX, ValY);
	//cos theta = adjacent / hypotenuse. Adjacent should be Y value for this 
	CosAngle = ValY / Hyp;
	if(ValX >= 0)
		return (float)acos(CosAngle) * 180/PI;
	else		// if X is negative it counts down from 180 so we subtract it from 360 to get a range of 0 to 360
		return (float)360 - (acos(CosAngle) * 180/PI);
}