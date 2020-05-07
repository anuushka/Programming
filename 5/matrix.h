#pragma once

using namespace std;

class arrayException
{
	private:
		string error;
	public:
		arrayException(string error) : error(error) {}
		
		const string getError()
		{
			return error;
		}
};

template <int N, int M, class T>
class Array
{
	private:
	vector<vector <T> > matrix;
	public:
		Array()
		{
			matrix.resize(N, vector<int>(M));

		}
   		
		T& operator()(int row, int col)
		{
			if((row >= N) || (col >= M))			
			{
				throw arrayException("Index out of range");
			}
			return matrix[row][col];
		}
		
		const T& operator()(int row, int col) const
		{
		    if((row >= N) || (col >= M))
			{
				throw arrayException("Index out of range");
			}
			return matrix[row][col];
		}
};

