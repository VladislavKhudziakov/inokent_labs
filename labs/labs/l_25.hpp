// Created by Vladislav Khudiakov on 10/22/19.
//

#pragma once

namespace l_25
{
  template <typename T, size_t rows, size_t cols>
  class Matrix
  {
  public:
    explicit Matrix(T(& m)[rows][cols])
    {
      for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
          m_arr[i][j] = m[i][j];
        }
      }
    }

    virtual ~Matrix() = default;

    virtual T get_sum()
    {
      T res = T();

      for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
          res += m_arr[i][j];
        }
      }

      return res;
    }

    T m_arr[rows][cols];
  };


  template <typename T, size_t rows, size_t cols>
  class Matrix1 : public Matrix<T, rows, cols>
  {
  public:
    explicit Matrix1(T(& m)[rows][cols]) : Matrix<T, rows, cols>(m)
    {
    }

    ~Matrix1() override = default;

    T get_sum() override
    {
      T sum = T();

      for (size_t i = 0; i < rows; ++i) {
        sum += this->m_arr[i][0];
      }

      return sum;
    }
  };


template <typename T, size_t rows, size_t cols>
class Matrix2 : public Matrix<T, rows, cols>
{
public:
  explicit Matrix2(T(& m)[rows][cols]) : Matrix<T, rows, cols>(m)
  {
  }

  ~Matrix2() override = default;

  T get_sum() override
  {
    T sum = T();

    for (size_t i = 0; i < rows; ++i) {
      sum += this->m_arr[i][cols - 1];
    }

    return sum;
  }
};
}

