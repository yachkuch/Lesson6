#ifndef MATRIX
#define MATRIX
#include <map>
///////////////////////////////////////////////////////////
/// @brief Matrix
///
template <typename T, int size_m = -1>
class Matrix
{
    class Iterator
    {
        using data = std::map<int, T>;
        data *datas;
        friend class Matrix;
        void setData(data *dataVal)
        {
            Iterator::datas = dataVal;
        }
    public:
        T & operator[](int i)
        {
            if(datas == nullptr) throw std::out_of_range("Matrix is empty");
            return (*datas)[i];
        }
    };

public:
    Matrix(std::initializer_list<std::initializer_list<T>> list)
    {
        int i = 0,j = 0,main_count = 0;
        for(const auto &row : list)
        {
            j = 0;
            for(const auto &elem : row)
            {
                (*this)[i][j] = elem;
                j++;
                main_count++;
            }
            i++;
        }
        this->m_size = main_count;
    }
    Matrix()
    {
        m_iterator.setData(nullptr);
    }
    int size()
    {
        this->m_size = 0;
        for(const auto &row : m_matrix)
        {
            this->m_size += row.second.size();
        }
        return this->m_size;
    };

    Iterator operator[](int i)
    {
        m_iterator.setData(&this->m_matrix[i]);
        return m_iterator;
    }

private:
    int m_size = 0;
    std::map<int, std::map<int, T>> m_matrix;
    friend class Iterator;
    Iterator m_iterator;
};

#endif // __MATRIX_H_IARA837CJS5Y__
