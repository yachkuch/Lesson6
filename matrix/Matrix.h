#ifndef MATRIX
#define MATRIX
#include <map>
///////////////////////////////////////////////////////////
/// @brief Matrix
///
template <typename T, int size_m = -1> class Matrix {
  class Iterator : public std::iterator<std::input_iterator_tag, T> {
    using data = std::map<int, T>;
    using mainData = std::map<int, data>;
    using currentDataMain = decltype(mainData::begin());
    using currentData = decltype(mainData::begin());
    friend class Matrix;

    data *datas = nullptr;
    mainData *mainDatas = nullptr;
    currentDataMain *currentDatasMain = nullptr;
    currentData *currentDatas = nullptr;

    void setData(mainData *mainVal, data *dataVal) {
      datas = dataVal;
      mainDatas = mainVal;
      currentDatasMain = mainVal;
      currentDatas = dataVal;
    }

  public:
    T &operator[](int i) {
      if (datas == nullptr)
        throw std::out_of_range("Matrix is empty");
      return (*datas)[i];
    }

    bool operator!=(const Iterator &it) const { return datas != it.datas; }

    Iterator &operator++() {
      if (datas == *datas->end()) {

      } else {
      }
    }

    T &operator*() {
      if (datas == nullptr)
        throw std::out_of_range("Matrix is empty");
      return;
    }
  };

  using iterator = Iterator;
  using const_iterator = const Iterator;

public:
  Matrix(std::initializer_list<std::initializer_list<T>> list) {
    int i = 0, j = 0, main_count = 0;
    for (const auto &row : list) {
      j = 0;
      for (const auto &elem : row) {
        (*this)[i][j] = elem;
        j++;
        main_count++;
      }
      i++;
    }
    this->m_size = main_count;
  }
  Matrix() { m_iterator.setData(nullptr, nullptr); }
  int size() {
    this->m_size = 0;
    for (const auto &row : m_matrix) {
      this->m_size += row.second.size();
    }
    return this->m_size;
  };

  Iterator operator[](int i) {
    m_iterator.setData(&this->m_matrix, &this->m_matrix[i]);
    m_iterator.mainDatas = &this->m_matrix;
    return m_iterator;
  }

  Iterator begin() {
    m_iterator.setData(&this->m_matrix, &m_matrix[0]);
    return m_iterator;
  }

  Iterator end() {
    m_iterator.setData(nullptr, nullptr);
    return m_iterator;
  }

  const_iterator cbegin() const {
    m_iterator.setData(&this->m_matrix, &m_matrix[0]);
    return m_iterator;
  }

  const_iterator cend() const {
    m_iterator.setData(nullptr, nullptr);
    return m_iterator;
  }

private:
  int m_size = 0;
  std::map<int, std::map<int, T>> m_matrix;
  friend class Iterator;
  Iterator m_iterator;
};

#endif // __MATRIX_H_IARA837CJS5Y__
