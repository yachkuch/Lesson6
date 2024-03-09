#ifndef MATRIX
#define MATRIX
#include <map>
#include <tuple>
#pragma region(MATRIX)
/// @brief Matrix
///
template <typename T, int size_m = -1>
class Matrix
{
    const int def_val = -1;
    class Iterator
    {
        using data = std::map<int, T>;
        using mainData = std::map<int, data>;
        using MainIter = typename mainData::iterator;
        using smallIter = typename data::iterator;

        MainIter maiinData;
        smallIter smallData;

        data *mainDat = nullptr;
        bool stopIteration = false;

    public:
        Iterator(MainIter mainData, smallIter mallData) : maiinData(mainData), smallData(mallData) {}
        explicit Iterator(MainIter mainData) : maiinData(mainData), smallData(maiinData.operator*().second.begin()) {}
        explicit Iterator(data *m) : mainDat(m) {}
        // Iterator() = default;
        T &operator[](int i)
        {
            return (*mainDat)[i];
        }

        bool operator!=(const Iterator &el)
        {
            auto a = std::make_tuple(this->maiinData, this->smallData);
            auto b = std::make_tuple(el.maiinData, el.smallData);
            return a != b;
        }

        Iterator operator++()
        {
            if(smallData != maiinData.operator*().second.end())
            {
            smallData++;
            }
            if (smallData == maiinData.operator*().second.end())
            {
                maiinData++;
                smallData = maiinData.operator*().second.begin();
            }
            return *this;
        }
        T operator*()
        {
            return smallData.operator*().second;
        }
    };

    using iterator = Iterator;
    using const_iterator = const Iterator;

public:
    Matrix() = default;
    Matrix(std::initializer_list<std::initializer_list<T>> list)
    {
        int i = 0, j = 0, main_count = 0;
        for (const auto &row : list)
        {
            j = 0;
            for (const auto &elem : row)
            {
                (*this)[i][j] = elem;
                j++;
                main_count++;
            }
            i++;
        }
        this->m_size = main_count;
    }
    int size()
    {
        this->m_size = 0;
        for (const auto &row : m_matrix)
        {
            this->m_size += row.second.size();
        }
        return this->m_size;
    };

    iterator operator[](int i)
    {

        iterator m_iterator(&this->m_matrix[i]);
        return m_iterator;
    }

    iterator begin()
    {
        iterator m_iterator(m_matrix.begin());
        return m_iterator;
    }

    iterator end()
    {
        iterator m_iterator(m_matrix.end(), m_matrix.end().operator*().second.end());
        return m_iterator;
    }

    const_iterator cbegin() const
    {
        const_iterator m_iterator(m_matrix.begin());
        return m_iterator;
    }

    const_iterator cend() const
    {
        const_iterator m_iterator(m_matrix.end(), m_matrix.end().operator*().second.end());
        return m_iterator;
    }

    bool contain(int line, int column)
    {
        bool found = false;
        if (m_matrix.contains(line))
        {
            if (m_matrix[line].contains(column))
            {
                found = true;
            }
        }
        return found;
    }

    bool contain(int line)
    {
        return m_matrix.contains(line);
    }

    iterator find(const int line, const int column = 0)
    {
        auto find = m_matrix.find(line);
        if (find != m_matrix.end())
        {
            auto find_col = find->second.find(column);
            if (find_col != find->second.end())
            {
                return iterator(find,find_col);
            }
        }
        return this->end();
    }

private:
    int m_size = 0;
    std::map<int, std::map<int, T>> m_matrix;
    friend class Iterator;
};
#pragma endregion
#pragma region(MATRIX_2)
// template<typename T>
// class Matrix2
// {
//     class Iterator
//     {
//         public:
//         T& operator[](int t)
//     };

//     using iterator = Iterator;
//     using const_iterator = const Iterator;

//     std::map<int,std::vector<int,T>> m_matrix;

//     public:

//     iterator& operator [](int i)
//     {
//         return m_matrix[i].second;
//     }

//     iterator begin()
//     {
//         return m_matrix.begin();
//     }

//     iterator end()
//     {
//         return m_matrix.end();
//     }

//     int size() const
//     {
//         return m_matrix.size();
//     }

// };
#pragma endregion
#endif // __MATRIX_H_IARA837CJS5Y__
