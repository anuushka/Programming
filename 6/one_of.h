#pragma once

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
