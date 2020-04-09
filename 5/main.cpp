#include "matrix.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

void first_task()
{
	cout << "2 ^ 5 = " ;
	cout << power(2, 5) << '\n';
}

void second_task()
{
	Array<9, 9, int> arr;
	try
	{
		arr(11,8) = 4;
		cout << arr(11,8);
	} 
	
	catch(arrayException &errors)
	{
		cerr << errors.getError() << '\n';
		exit(1);
	}
}

int main()
{
	first_task();
	second_task();	
	
	return 0;
}
