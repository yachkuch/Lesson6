#include <iostream>
#include "Matrix.h"
#include<map>
int main(int, char**){
    std::cout << "Hello, from Matrix!\n";
    Matrix<int ,-1> matr;
    for (int i = 0; i < 10; i++) {
    matr[i][i] = i;
    matr[i][9 - i] = 9 - i;
}
    std::cout <<  matr [1][1] << '\n';
    std::cout <<  matr.size() << '\n';
    std::cout<<"_____________________full matr__________________\n";
    for(const auto& row : matr)
    {

        std::cout << row << '\n';
    }
    return 0;
}
