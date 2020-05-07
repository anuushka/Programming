#pragma once

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

