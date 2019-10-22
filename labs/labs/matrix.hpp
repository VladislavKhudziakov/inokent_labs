// Created by Vladislav Khudiakov on 10/22/19.
//

#pragma once

namespace t_3
{
  template <typename T>
  class Matrix
  {
  public:
    template <unsigned rows, unsigned columns>
    explicit Matrix(T(& m)[rows][columns])
    : m_rows(rows)
    , m_columns(columns)
    , p_begin(nullptr)
    {
      if (m_rows != m_columns) {
        throw std::logic_error("rows must be equals columns");
      }

      p_begin = new T[rows][columns];

      for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < columns; ++j) {
          p_begin[i][j] = m[i][j];
        }
      }
    }

    virtual ~Matrix()
    {
      delete[] p_begin;
    };

    virtual T get_sum()
    {
      T res = T();

      for (unsigned i = 0; i < m_rows; ++i) {
        for (unsigned j = 0; j < m_columns; ++j) {
          res += p_begin[i][j];
        }
      }
    }

  protected:
    unsigned m_rows, m_columns;
    T* p_begin;
  };


  template <typename T>
  class Matrix1 : public Matrix<T>
  {
  public:
    template <unsigned rows, unsigned columns>
    explicit Matrix1(T(& m)[rows][columns]) : Matrix<T>(m)
    {
    }

    ~Matrix1() override = default;

    T get_sum() override
    {
      T sum = T();
//    todo
//      for (unsigned i = 0; i < m_rows; ++i) {
//        sum += p_begin[i][0];
//      }

      return T();

    }
  };
}

