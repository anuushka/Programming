#include <iostream>
#include <iterator>

using namespace std;

template<class InputIterator, class UnaryPredictor>
  bool all_of (InputIterator first, InputIterator last, UnaryPredictor pred)
{
  while (first!=last) {
    if (!pred(*first)) 
		return false;
    ++first;
  }
  return true;
}

template<class InputIterator, class UnaryPredictor>
  bool one_of (InputIterator first, InputIterator last, UnaryPredictor pred)
{
  while (first!=last) 
  {
    if (pred(*first)) 
		return true;
    ++first;
  }
  return false;
}

template<class InputIterator, class T>
  InputIterator find_backward(InputIterator first, InputIterator last, const T& val)
{
  while (first!=last) 
  {
    if (*first==val) 
		return first;
    ++first;
  }
  return last;
}

bool isOdd(int i)
{
	return i%2 == 1;
}

bool isPositive(int i)
{
	return  i > 0;
}

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
