#ifndef MATRIX
#define MATRIX

///////////////////////////////////////////////////////////
/// @brief Matrix
///
template <typename T, int size_m>
class Matrix {
public:
    int size ()
    {
        return this->m_size;
    };

private:
    int m_size = 0;

    class Iterator {
        friend class Matrix;
    };
};

#endif // __MATRIX_H_IARA837CJS5Y__
