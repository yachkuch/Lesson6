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
    std::cout << matr.size() << '\n';
    std::cout << "_____________________part of matr__________________\n";
    const int startColumn = 1;
    const int startLine = 1;
    const int finishLine = 8;
    const int finishColumn = 8;
    auto iter = matr.begin();
    auto iter2 = matr.end();
    for (int i = startLine; i <= finishLine; i++)
    {
        auto line = matr.getLine(i);
        auto lineEnd = line.end();
        if (line.begin() != lineEnd)
        {
            for (int j = 0; j <= finishColumn; j++)
            {
                auto val = line.find(j);
                if(val != lineEnd)
                {
                    std::cout<<val->second<<" ";
                }
                else 
                {
                    std::cout<<"0 ";
                }
            }
            std::cout<<std::endl;
        }
        else
        {
            for(int j =0; j<=finishColumn;j++)
            {
                std::cout<<"0 ";
            }
            std::cout<<std::endl;
        }
    }
    std::cout<<"elements with positions   \n";
    while (iter != iter2)
    {
        auto [a,b,c] = iter;
        std::cout<<"line "<<a<<"row "<<b<<"value "<<c<<std::endl;
        iter.operator++();
    }
    
    return 0;
}
