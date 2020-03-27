#include <bits/stdc++.h>
#include "func.h"
using namespace std;

void first() {
   int m = 7, n = 6;
   cout << "Before Swap\n";
   cout << "m = " << m << " n = " << n << "\n";
   swap(m, n);
   cout << "After Swap by pass by reference\n";
   cout << "m = " << m << " n = " << n << "\n";
   swap(&m, &n);
   cout << "After Swap by pass by pointer\n";
   cout << "m = " << m << " n = " << n << "\n";
}

void second()
{
    double m = 3.1415;
    cout << "Before Fract\n";
    cout << "m = " << m << "\n";
  	fract(m);
  	cout << "After Fract by pass by reference\n";
   	cout << "m = " << m << "\n";
  	fract(&m);
  	cout << "After Fract by pass by pointer\n";
   	cout << "m = " << m <<  "\n";
}

void third()
{
	Complex_N z1;
	z1.im = 5, z1.re = 7;
	double c = 1.5;
	cout << "Before Complex_N N multiply Real number\n";
	cout << "Values: " << z1.re << "+" << z1.im << "i" << " * " << c << "\n";  
		
	Multiply(z1, c);
   	cout << "After mulitply by pass by reference\n";
	cout << "Values: " << z1.re << " " << z1.im << "i" <<  "\n";  	
	
	Multiply(&z1, &c);
	cout << "After mulitply by pass by pointer\n";
	cout << "Values: " << z1.re << " " << z1.im << "i" <<  "\n";  	
}

void last()
{
	int A[N][N] = { {1, 1, 1}, 
                    {2, 2, 2}, 
                    {3, 3, 3} };
                    
	int B[N][N] = { {1, 2, 3}, 
                    {4, 5, 6}, 
                    {7, 8, 9} }; 
					 
    cout << "Matrix ref: " << "\n";
    
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
    	{
    		cout << A[i][j] << " ";
		}
		cout << "\n";
	}
  
    int i, j; 
    
	transpose_ref(A);
    cout << "Trasnpose by reference: " << "\n";
	for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
           cout << A[i][j] << " "; 
           cout << "\n";
    } 
    
    cout << "Matrix pointer: " << "\n";
    
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
    	{
    		cout << B[i][j] << " ";
		}
		cout << "\n";
	}
	
    transpose_ptr(B);
    cout << "Transpose by pointer: " << "\n";    
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
           cout << B[i][j] << " "; 
           cout << "\n";
    } 
}

int main()
{
	first();
	second();
	third();
	last();
}
