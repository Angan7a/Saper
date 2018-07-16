#include "createBombs.hpp"
#include <stdlib.h>
#include <time.h>

void createBombs(char tab[10][10]) {
  int tabInt[12][12];
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      tabInt[i][j] = 0;
    }
  }
  srand(time(NULL));
  int x, y;
  for (int k = 0; k < 5; k++) {
    x = 1 + rand() % 10;
    y = 1 + rand() % 10;
    tabInt[x][y] = 9;
    for (int i = x - 1; i <= x + 1; i++)
      for (int j = y - 1; j <= y + 1; j++)
        if (tabInt[i][j] != 9)
          tabInt[i][j]++;
  }
  for (int i = 1; i < 11; i++) {
    for (int j = 1; j < 11; j++) {
      tab[i-1][j-1] = (tabInt[i][j] % 10)+48;
    }
  }
}
