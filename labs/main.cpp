#include <l_11.hpp>
#include <l_14.hpp>
#include <l_25.hpp>
#include <l_7.hpp>
#include <l_5.hpp>
#include <l_17.hpp>

#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>

#define LOG(val) std::cout << val << std::endl;

int main() {
  std::cout << "Hello, World!" << std::endl;

  int arr[] { 1, 2, 3, 4, 5};

  l_14::replace_on_indices(arr);
  std::copy(arr, arr + 5, std::ostream_iterator<int>(std::cout, " ")); // {0,
  // 1, 2, 3, 4, 5}
  std::cout << std::endl;

  float matrix[4][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}
  };

  LOG(l_14::average(matrix))

  std::unique_ptr<l_25::Matrix<float, 4, 4>> m;
  m = std::make_unique<l_25::Matrix<float, 4, 4>>(matrix);
  LOG(m->get_sum())
  m = std::make_unique<l_25::Matrix1<float, 4, 4>>(matrix);
  LOG(m->get_sum())
  m = std::make_unique<l_25::Matrix2<float, 4, 4>>(matrix);
  LOG(m->get_sum())

  auto all_words = l_7::split(std::string("asdsa asdasd asdasd adsadas"), std::string(" "));
  LOG(all_words.size())

  auto words = l_7::greater_then_average(std::string("asdsa asdasd asdasd adsadas"), std::string(" "));
  std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

  auto words_with_vowels_count = l_7::vowels_count(std::string("asdsa asdasd asdauuusd adsadas"), std::string(" "));
  for(auto& [word, count] : words_with_vowels_count) {
    std::cout << word << ": " << count << std::endl;
  }

  std::vector<int> v {95, 45, 48, 98, 1, 485, 65, 478, 1, 2325};
  l_11::quick_sort(v, 0, v.size());
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  int matrix2[4][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}
  };

  LOG(l_5::average(matrix2))
  auto now = std::chrono::system_clock::now();

  l_17::student s { 0, 1, "asd", "sad", std::chrono::system_clock::to_time_t(
      now - std::chrono::hours(24)), MALE};

  std::ofstream fout;
  fout.open("file.txt");
  fout << s;
  fout.close();
  LOG(s)
  return 0;
}