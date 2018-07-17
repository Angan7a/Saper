#include "fieldReveal.hpp"

void fieldReveal(int x, int y, char tabVisible[10][10],
                 char tabHidden[10][10]) {
  tabVisible[y][x] = tabHidden[y][x];
  if (tabHidden[y][x] == '0') {
    tabVisible[y][x] = ' ';
    if (x > 0 && tabVisible[y][x - 1] == '#')
      fieldReveal(x - 1, y, tabVisible, tabHidden);
    if (x < 9 && tabVisible[y][x + 1] == '#')
      fieldReveal(x + 1, y, tabVisible, tabHidden);
    if (y > 0 && tabVisible[y - 1][x] == '#')
      fieldReveal(x, y - 1, tabVisible, tabHidden);
    if (y < 9 && tabVisible[y + 1][x] == '#')
      fieldReveal(x, y + 1, tabVisible, tabHidden);
  }
}
