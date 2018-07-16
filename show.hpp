#pragma once 

#include <iostream>

template<class T>
void show(T tab[10][10], int x, int y, int r) {
  for ( int i = 0; i < 10; i++ ) {

for ( int j = 0; j < 10; j++ ) {
    if (i == x && j == y && r == 1) {
        std::cout << "\033[1;41m"<<tab[i][j] << "\033[0m ";
    } else {
        std::cout << tab[i][j] << " ";
    }
}
std::cout << std::endl;
}


}
