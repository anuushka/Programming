#include <iostream>
#include <iterator>
#include "find_backward.h"
#include "one_of.h"
#include "all_of.h"
#include "function.h"

using namespace std;


int main()
{
	int A[] = {2, 4, 6, 8, 10, 6, 7, 8};
	int N = sizeof(A) / sizeof(A[0]); 
	cout << all_of(A, A + N, isPositive) << '\n';
	cout << one_of(A, A + N, isOdd)  << '\n';
	int * p;
	p = find_backward(A, A+N, 9);
	if (p != A+N)
   		cout << "Element found in array: " << *p << '\n';
	else
   		cout << "Element not found in array\n";
}
