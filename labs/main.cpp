#include "labs/task_1.hpp"
#include "labs/matrix.hpp"

#include <iostream>

int main() {
  std::cout << "Hello, World!" << std::endl;

  int arr[] { 1, 2, 3, 4, 5};

  t_1::replace_on_indices(arr);
  std::copy(arr, arr + 5, std::ostream_iterator<int>(std::cout, " ")); // {0,
  // 1, 2, 3, 4, 5}
  std::cout << std::endl;

  float matrix[4][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}
  };

  std::cout <<  t_1::average(matrix) << std::endl;// 26
  return 0;
}