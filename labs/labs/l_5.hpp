
#pragma once
#include <stdexcept>

namespace l_5
{
  template <typename T, unsigned size>
  constexpr void replace_on_indices(T(& arr)[size])
  {
    for (unsigned i = 0; i < size; ++i) {
      arr[i] = i;
    }
  }


  template <typename T, unsigned rows, unsigned columns>
  T average(T(& arr)[rows][columns])
  {
    static_assert(rows == columns && "ERROR: MATRIX IS NOT SQUARE");

    T res = T();

    for (unsigned i = 0; i < rows; ++i) {
      for (unsigned j = 0; j < rows - (i + 1); j++) {
        res += arr[i][j];
      }
    }

    return res;
  }
}
