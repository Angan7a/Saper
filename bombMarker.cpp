#include "bombMarker.hpp"

void bombMarker(int &x, int &y, int &bombs, char tabVisible[10][10]) {
  if (tabVisible[y][x] == '#') {
    bombs--;
    tabVisible[y][x] = '@';
  } else {
    tabVisible[y][x] = '#';
    bombs++;
  }
}
