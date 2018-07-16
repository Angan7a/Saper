#include "fieldReveal.hpp"

void fieldReveal(int x, int y, char tabVisible[10][10],
                 char tabHidden[10][10]) {
  tabVisible[x][y] = tabHidden[x][y];
  if (tabHidden[x][y] == '0') {
    if (x > 0 && tabVisible[x - 1][y] == '#')
      fieldReveal(x - 1, y, tabVisible, tabHidden);
    if (x < 9 && tabVisible[x + 1][y] == '#')
      fieldReveal(x + 1, y, tabVisible, tabHidden);
    if (y > 0 && tabVisible[x][y - 1] == '#')
      fieldReveal(x, y - 1, tabVisible, tabHidden);
    if (y < 9 && tabVisible[x][y + 1] == '#')
      fieldReveal(x, y + 1, tabVisible, tabHidden);
  }
}
