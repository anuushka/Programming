#include <cmath>
#include <iostream>
#include <fstream>
#pragma once

class CVector2D
{
	public:
	double x, y;
	CVector2D();
	friend std::istream& operator>>(std::istream&, CVector2D&);
	friend std::ostream& operator<<(std::ostream&, const CVector2D&);
};
