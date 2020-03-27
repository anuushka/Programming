#ifndef H_FUNC
#define H_FUNC
#include <bits/stdc++.h>
#define N 3

using namespace std;

void swap(int& a, int& b);
void swap(int* a, int* b);
void fract(double& a);
void fract(double* a);

struct Complex_N {
	double re;
	double im;
};

void Multiply(Complex_N& z, double& x);
void Multiply(Complex_N* z, double* x);
void transpose_ref(int(&A)[N][N]);
void transpose_ptr(int A[N][N]);
#endif  

