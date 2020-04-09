#include<bits/stdc++.h>
#include "func.h"

Equation::Equation()
{
	a = b = c = 0;
}

Equation::Equation(const Equation& eq)
{
	a = eq.a;
	b = eq.b;
	c = eq.c;
}


double Equation::findPoint(double  x)  const
{
	//Task 1
	double y;
	y = a*x*x + b*x + c;
	return y;	
}

void Equation::findRoots() const
{
	//Task 2
	double D, x1, x2;
	D = b*b - 4*a*c;
	x1 = (-b + sqrt(D))/2;
	x2 = (-b - sqrt(D))/2;
	if(x1 == x2)
	{
		cout << x1 << '\n';
	} 
	else
	{
		cout << x1 << " " << x2 << '\n';
	}
}

	//Task 3
double Equation::extremePoint() const
{
	double max, min;
	if(a > 0)
	{
		cout << "Graph is upwards. Min: ";
		double x0 = -b/(2*a);
		min = (a*x0*x0 + b*x0 + c);
		return min;
	}
	else 
	{
		cout << "Graph is downwards. Max: " ;
		double x0 = -(b*b)/(2*a);
		 max = (a*x0*x0 + b*x0 + c);
		return max;
	}	
}

	//Task 4
void Equation::numRoots() const
{
	double D;
	D = b*b - 4*a*c;
	
	if(D > 0)
	{
		cout <<  "2 solutions"  << '\n';
	}
	else if(D == 0)
	{
		cout << "1 solution" << '\n';
	}
	else
	{
		cout << "No solutions" << '\n';
	}	

}

void write_interface() 
{
    cout << "               Press  1  for task 1" << endl;
    cout << "               Press  2  for task 2" << endl;
    cout << "               Press  3  for task 3" << endl;
    cout << "               Press  4  for task 4" << endl;
}

