#include "findNoEmptyUp.hpp"

void findNoEmptyUp(int& x, int& y, char tab[10][10]) {
    if(y<0) {
        x--;
        y = 9;
    }
    while(tab[y][x] == ' ') {
        y--;
        if(y<0) {
            x--;
            y = 9;
        }
        if(x<0) {
            x = 9;
            y = 9;
        }
    }

}
