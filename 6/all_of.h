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
