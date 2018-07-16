#include "createBombs.hpp"
#include <stdlib.h>
#include <time.h>

void createBombs(char tab[10][10]) {
  srand(time(NULL));
  int x, y;
  for (int k = 0; k < 5; k++) {
    x = rand() % 10;
    y = rand() % 10;
    tab[x][y] = '9';
    for (int i = x - 1; i <= x + 1; i++)
      for (int j = y - 1; j <= y + 1; j++)
        if (tab[i][j] != '9')
          tab[i][j]++;
  }
}
