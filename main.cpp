#include <iostream>
#include "Matrix.h"
#include <map>
int main(int, char **)
{
    std::cout << "Hello, from Matrix!\n";
    Matrix<int, -1> matr;
    for (int i = 0; i < 10; i++)
    {
        matr[i][i] = i;
        matr[i][9 - i] = 9 - i;
    }
    std::cout << matr[3][3] << '\n';
    std::cout << matr.size() << '\n';
    std::cout << "_____________________full matr__________________\n";
    // for (const auto &row : matr)
    // {

    //     std::cout << row << '\n';
    // }
    std::cout << "_____________________find matr__________________\n";
    auto iter = matr.find(3, 3);
    auto iter2 = matr.find(8,8);
    while (iter != iter2)
    {
        std::cout << *iter << '\n';
        iter.operator++();
    }
    std::cout << "Cotain" << matr.contain(1, 1) << std::endl;
    return 0;
}
