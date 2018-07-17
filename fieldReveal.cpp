#include "fieldReveal.hpp"

void fieldReveal(int x, int y, int &bombs, char tabVisible[10][10],
                 char tabHidden[10][10]) {
  if (tabHidden[y][x] == '9')
    bombs = 0;
  tabVisible[y][x] = tabHidden[y][x];
  if (tabHidden[y][x] == '0') {
    tabVisible[y][x] = ' ';
    if (x > 0 && tabVisible[y][x - 1] == '#')
      fieldReveal(x - 1, y, bombs, tabVisible, tabHidden);
    if (x < 9 && tabVisible[y][x + 1] == '#')
      fieldReveal(x + 1, y, bombs, tabVisible, tabHidden);
    if (y > 0 && tabVisible[y - 1][x] == '#')
      fieldReveal(x, y - 1, bombs, tabVisible, tabHidden);
    if (y < 9 && tabVisible[y + 1][x] == '#')
      fieldReveal(x, y + 1, bombs, tabVisible, tabHidden);
  }
}
