#include <iostream>
#include <fstream>
#include <cmath>
#include "interface.h"
using namespace std;

CVector2D::CVector2D(): x(0), y(0)
{
	double x = 0;
	double y = 0;
}

std::istream& operator>>(std::istream& stream, CVector2D& point)
{
	stream >> point.x >> point.y;
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const CVector2D& point)
{
	stream << "Coordinates: (" << point.x << ", " << point.y << ")";
	return stream;
}
