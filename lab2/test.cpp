#include<bits/stdc++.h>
#include "func.h"
using namespace std;


int main(int argc, const char * argv[]) 
{
	write_interface();
	Equation eq;

	while(1)
	{
		int c = 0;
		cin >> c;
		switch(c)
		{
			case 1:
			{
				cout << "Enter a, b, c:" << '\n';
				cin >> eq.a >> eq.b >> eq.c;
				cout << "Roots: ";
				eq.findRoots();	
				break;
			}
			case 2:
			{
				cout << "Enter a, b, c:" << '\n';
				cin >> eq.a >> eq.b >> eq.c;
				cout << "x : " ;
				cin >> eq.x;
				cout << "y: " << eq.findPoint(eq.x);
				break;
			}
			case 3:
			{
				cout << "Enter a, b, c:" << '\n';
				cin >> eq.a >> eq.b >> eq.c;
				cout << "Number of roots: ";
				eq.numRoots();
				break;
			}
			
			case 4:
				cout << "Enter a, b, c:" << '\n';
				cin >> eq.a >> eq.b >> eq.c;
				cout << eq.extremePoint() << '\n';	
				break;
		}
		cout << '\n';
		write_interface();
	}
}
