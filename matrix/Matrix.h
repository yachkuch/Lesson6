#ifndef MATRIX
#define MATRIX
#include <map>
#include <tuple>

/// @brief Matrix
///
template <typename T, int size_m = -1>
class Matrix
{
    class Iterator
    {
        using data = std::map<int, T>;
        using mainData = std::map<int, data>;
        using currentDataMain = typename mainData::iterator;
        using currentData = typename data::iterator;
        friend class Matrix;

        data *datas = nullptr;
        currentDataMain currentDatasMain;
        currentDataMain currentDatasMainEnd;
        currentDataMain currentDatasMainState;
        currentData currentDatas;
        int stop = 0;

        void setData(mainData *MainData, data *dataVal, currentDataMain main, currentData cur)
        {
            if (dataVal == nullptr)
                return;
            if (MainData == nullptr)
                return;
            datas = dataVal;
            currentDatasMain = MainData->begin();
            currentDatas = cur;
            currentDatasMainEnd = MainData->end();
            currentDatasMainState = main;
        }

        void setDataEnd(currentDataMain main, currentData cur)
        {
            currentDatasMainState = main;
            currentDatas = cur;
        }

    public:
        T &operator[](int i)
        {
            return (*datas)[i];
        }
        // TODO: Переписать гребанный оператор не равно
        bool operator!=(const Iterator &it) const
        {
            if (stop == 1)
                return false;
            auto a1 = std::tie(currentDatasMain, currentDatas);
            auto a2 = std::tie(it.currentDatasMain, it.currentDatas);
            return a1 != a2;
        }
        Iterator &operator++()
        {
            currentDatas++;
            if ((currentDatasMain == currentDatasMainEnd) && (currentDatas == currentDatasMain.operator*().second.end()))
                return *this;
            if (currentDatas == currentDatasMain.operator*().second.end())
            {
                currentDatasMain++;
                if (currentDatasMain != currentDatasMainEnd)
                {
                    currentDatas = currentDatasMain.operator*().second.begin();
                }
                else
                {
                    stop = 1;
                }
            }
            return *this;
        }

        T &operator*()
        {
            if (datas == nullptr)
                throw std::out_of_range("Matrix is empty");
            return currentDatas->second;
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

    Iterator operator[](int i)
    {
        Iterator m_iterator;
        m_iterator.setData(&this->m_matrix, &this->m_matrix[i], this->m_matrix.begin(), this->m_matrix[i].begin());
        return m_iterator;
    }

    Iterator begin()
    {
        Iterator m_iterator;
        m_iterator.setData(&this->m_matrix, &m_matrix[0], this->m_matrix.begin(), m_matrix[0].begin());
        return m_iterator;
    }

    Iterator end()
    {
        Iterator m_iterator;
        m_iterator.setData(&this->m_matrix, &m_matrix[0], this->m_matrix.end(), m_matrix.end().operator*().second.end());
        return m_iterator;
    }

    const_iterator cbegin() const
    {
        const_iterator m_iterator;
        m_iterator.setData(&this->m_matrix, &m_matrix[0], this->m_matrix.cbegin(), m_matrix[0].cbegin());
        return m_iterator;
    }

    const_iterator cend() const
    {
        const_iterator m_iterator;
        m_iterator.setData(&this->m_matrix, &m_matrix[0], this->m_matrix.cend(), m_matrix.operator*().second.cend());
        return m_iterator;
    }

    bool contain( int line,  int column = 0) 
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

    Iterator find(const int line, const int column = 0) 
    {
        Iterator it;
        auto find = m_matrix.find(line);  
        if (find!= m_matrix.end())
        {
            auto find_col = find->second.find(column);
            if (find_col != find->second.end())
            {
                it.setData(&this->m_matrix, &m_matrix[0], find,find_col);
            }
        }
        return it;
    }

private:
    int m_size = 0;
    std::map<int, std::map<int, T>> m_matrix;
    friend class Iterator;
};

#endif // __MATRIX_H_IARA837CJS5Y__
