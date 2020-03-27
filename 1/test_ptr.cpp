#include<bits/stdc++.h>
using namespace std;
#define N 3

void transpose(int A[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
        for (int j = i+1; j < N; j++) 
            swap((*(*(A + i) + j)), (*(*(A + j) + i)));
}

int main()
{
	int A[N][N] = { {1, 2, 3}, 
                    {4, 5, 6}, 
                    {7, 8, 9} }; 
    cout << "Original matrix: " << "\n";
    
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
    	{
    		cout << A[i][j] << " ";
		}
		cout << "\n";
	}
  
    int i, j; 
    
	transpose(A);
    cout << "Result matrix by reference: " << "\n";
	for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
           cout << A[i][j] << " "; 
           cout << "\n";
    } 
    
}
