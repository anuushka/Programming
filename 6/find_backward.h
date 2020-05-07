#pragma once
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

