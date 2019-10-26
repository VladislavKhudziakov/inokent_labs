//
// Created by movleaxedx on 27.10.19.
//

#pragma once

namespace l_5
{
  template <typename T, size_t r, size_t c>
  T average(T (&m)[r][c]) {
    T res = T();
    T all = T();

    for (size_t i = 0; i < r; ++i) {
      for (size_t j = 0; j < c; ++j) {
        if (m[i][j] % 2 == 0) {
          res += m[i][j];
          ++all;
        }
      }
    }

    return res / all;
  }
}
