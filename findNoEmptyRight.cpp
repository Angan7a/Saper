#include "findNoEmptyRight.hpp"

void findNoEmptyRight(int& x, int& y, char tab[10][10]) {
    while(tab[y][x] == ' ') {
        x++;
        if(x>9) {
            y++;
            x = 0;
        }
        if(y>9) {
            x = 0;
            y = 0;
        }
    }
}
