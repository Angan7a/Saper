#include "findNoEmptyLeft.hpp"

void findNoEmptyLeft(int& x, int& y, char tab[10][10]) {
    if(x<0) {
        y--;
        x = 9;
    }
    if(y<0) {
        x = 9;
        y = 9;
    }
    while(tab[y][x] == ' ') {
        x--;
        if(x<0) {
            y--;
            x = 9;
        }
        if(y<0) {
            x = 9;
            y = 9;
        }
    }
}
