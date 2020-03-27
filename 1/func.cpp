#include "func.h"
#include <bits/stdc++.h>
#define N 3

void swap(int& a, int& b) 
{
   int c = a;
   a = b;
   b = c;
}

void swap(int* a, int* b)
{
   int c = *a;
   *a= *b;
   *b = c;
}

void fract(double& a)
{
	double p, fract;
	fract = modf(a, &p); 
	a = fract;
}

void fract(double* a)
{
	double p, fract;
	fract = modf(*a, &p);
	*a = fract;
}

void Multiply(Complex_N& z, double& x)
{
	z.re *= x;
	z.im *= x;
}

void Multiply(Complex_N* z, double* x)
{
	z->re *= *x;
	z->im *= *x;
}

void transpose_ref(int(&A)[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
        for (int j = i+1; j < N; j++) 
            swap(A[i][j], A[j][i]); 
}

void transpose_ptr(int A[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
        for (int j = i+1; j < N; j++) 
            swap(A[i][j], A[j][i]);          		
}




 


