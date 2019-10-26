//
// Created by movleaxedx on 26.10.19.
//

#pragma once
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <map>

namespace l_7
{
  template <typename T>
  std::vector<T> split(const T& str, const T& delim)
  {
    std::vector<T> tokens;
    size_t prev = 0, pos = 0;
    do {
      pos = str.find(delim, prev);
      if (pos == T::npos) pos = str.length();
      T token = str.substr(prev, pos-prev);
      if (!token.empty()) tokens.push_back(token);
      prev = pos + delim.length();
    }

    while (pos < str.length() && prev < str.length());

    return tokens;
  }

  template <typename T>
  std::vector<T> greater_then_average(const T& str, const T& delim)
  {
    auto words = split(str, delim);
    std::vector<size_t> lengths;
    lengths.reserve(words.size());

    for (auto& word: words) {
      lengths.emplace_back(word.size());
    }

    auto average = std::accumulate(lengths.begin(), lengths.end(), size_t(0)) / lengths.size();

    std::vector<T> out;
    std::copy_if(words.begin(), words.end(), std::back_inserter(out), [&](const T& word) {
      return word.size() > average;
    });

    return out;
  }

  template <typename T, size_t size>
  constexpr size_t array_size(T (&arr)[size])
  {
    return size;
  }

  std::map<std::string, size_t> vowels_count(const std::string& str, const std::string& delim)
  {
    auto words = split(str, delim);

    constexpr char alphabet[] = {'a', 'e', 'i', 'o', 'u'};
    constexpr size_t alphabet_size = array_size(alphabet);

    std::map<std::string, size_t> out;

    for (auto& word: words) {
      std::vector<char> vals;

      std::copy_if(word.begin(), word.end(), std::back_inserter(vals), [&](char symbol) {
        auto it = std::find_if(alphabet, alphabet + alphabet_size, [&](char alphabet_symbol) {
          return alphabet_symbol == symbol;
        });

        return it != alphabet + alphabet_size;
      });

      out.emplace(word, vals.size());
    }

    return out;
  }
}

