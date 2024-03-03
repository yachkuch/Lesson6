#include <iostream>
#include "Matrix.h"

int main(int, char**){
    std::cout << "Hello, from Matrix!\n";
    Matrix<int ,-1> matr;
    matr[0][0] = 0;
    matr[1][1] = 1;
    matr[2][2] = 2;
    matr[3][3] = 3;
    matr[4][4] = 4;
    matr[5][5] = 5;
    matr[6][6] = 6;
    matr[7][7] = 7;
    matr[8][9] = 8;
    matr[9][9] = 9;
    matr[0][9] = 9;
    matr[1][8] = 8;
    matr[2][7] = 7;
    matr[3][6] = 6;
    matr[4][5] = 5;
    matr[5][4] = 4;
    matr[6][3] = 3;
    matr[7][2] = 3;
    matr[8][1] = 1;
    matr[9][0] = 0;
    std::cout <<  matr [0][0] << '\n';
    std::cout <<  matr.size() << '\n';
    return 0;
}
