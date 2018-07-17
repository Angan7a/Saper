#include "findNoEmptyDown.hpp"

void findNoEmptyDown(int& x, int& y, char tab[10][10]) {
    if(y > 9) {
        x++;
        y = 0;
    }
    if(x>9) {
        x = 0;
        y = 0;
    }
    while(tab[y][x] == ' ') {
        y++;
        if(y>9) {
            x++;
            y = 0;
        }
        if(x>9) {
            x = 0;
            y = 0;
        }
    }

}
