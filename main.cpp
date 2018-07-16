#include "createBombs.hpp"
#include "show.hpp"
#include "keyPressed.hpp"
#include "kbhit.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char c;
  int x = 4, y = 6;
  char tabHidden[10][10];
  char tabVisible[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tabVisible[i][j] = '#';
      tabHidden[i][j] = '0';
    }
  }
  createBombs(tabHidden);
  while (c != 'q') {
    system("clear");
    show(tabVisible, x, y, 1);
    std::cout << std::endl;
    show(tabHidden, x, y, 1);
    usleep(70000);
    if (kbhit()) {
      std::cin >> c;
      keyPressed(c, x, y, tabVisible, tabHidden);
    }
  }
  return 0;
}
