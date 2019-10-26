//
// Created by movleaxedx on 27.10.19.
//

#pragma once
#include <cstddef>

namespace l_11
{
template <typename T>
  void quick_sort(T& container, size_t low, size_t high)
  {
    if (container.empty()) {
      return;
    }

    size_t i = low;
    size_t j = high;

    size_t pivot = container[(i + j) / 2];
    decltype(container[0]) temp = container[0];

    while (i <= j) {
      while (container[i] < pivot)
        i++;
      while (container[j] > pivot)
        j--;
      if (i <= j) {
        temp = container[i];
        container[i] = container[j];
        container[j] = temp;
        i++;
        j--;
      }
    }

    if (j > low)
      quick_sort(container, low, j);
    if (i < high)
      quick_sort(container, i, high);
  }
}
