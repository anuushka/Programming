#ifndef H_FUNC
#define H_FUNC
#include <bits/stdc++.h>
using namespace std;

class Equation
{
	public:
		double a, b, c, x;
		Equation();	
		Equation(const Equation& eq);
		
	
		void findRoots();
		double findPoint(double x);
		double extremePoint();
		void numRoots();
};

void write_interface();

#endif
