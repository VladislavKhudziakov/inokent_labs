
#pragma once
#include <stdexcept>

namespace t_1
{
  template <typename T, unsigned size>
  void replace_on_indices(T(& arr)[size])
  {
    for (unsigned i = 0; i < size; ++i) {
      arr[i] = i;
    }
  }


  template <typename T, unsigned rows, unsigned columns>
  T average(T(& arr)[rows][columns])
  {
    if (rows != columns) {
      throw std::logic_error("ERROR: MATRIX IS NOT SQUARE");
    }

    T res = T();

    for (unsigned i = 0; i < rows; ++i) {
      for (unsigned j = 0; j < rows - (i + 1); j++) {
        T val = arr[i][j];
        res += arr[i][j];
      }
    }

    return res;
  }
}
