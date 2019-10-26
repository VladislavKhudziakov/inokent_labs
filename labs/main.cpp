#include <l_5.hpp>
#include <l_7.hpp>
#include <l_25.hpp>

#include <iterator>
#include <memory>
#include <iostream>

#define LOG(val) std::cout << val << std::endl;

int main() {
  std::cout << "Hello, World!" << std::endl;

  int arr[] { 1, 2, 3, 4, 5};

  l_5::replace_on_indices(arr);
  std::copy(arr, arr + 5, std::ostream_iterator<int>(std::cout, " ")); // {0,
  // 1, 2, 3, 4, 5}
  std::cout << std::endl;

  float matrix[4][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}
  };

  LOG(l_5::average(matrix))

  std::unique_ptr<l_25::Matrix<float, 4, 4>> m;
  m = std::make_unique<l_25::Matrix<float, 4, 4>>(matrix);
  LOG(m->get_sum())
  m = std::make_unique<l_25::Matrix1<float, 4, 4>>(matrix);
  LOG(m->get_sum())
  m = std::make_unique<l_25::Matrix2<float, 4, 4>>(matrix);
  LOG(m->get_sum())

  auto words = l_7::greater_then_average(std::string("asdsa asdasd asdasd adsadas"), std::string(" "));

  std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

  auto words_with_vowels_count = l_7::vowels_count(std::string("asdsa asdasd asdauuusd adsadas"), std::string(" "));

  for(auto& [word, count] : words_with_vowels_count) {
    std::cout << word << ": " << count << std::endl;
  }

  return 0;
}