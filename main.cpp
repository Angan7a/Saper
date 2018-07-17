#include "bombsCheck.hpp"
#include "createBombs.hpp"
#include "kbhit.hpp"
#include "keyPressed.hpp"
#include "show.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char c;
  int x = 4, y = 6, bombs = 5;
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
    show(tabVisible, x, y, 1, bombs);
    std::cout << std::endl;
    show(tabHidden, x, y, 1, bombs);
    usleep(70000);
    if (kbhit()) {
      std::cin >> c;
      keyPressed(c, x, y, bombs, tabVisible, tabHidden);
    }
    if (bombs == 0) {
      system("clear");
      show(tabVisible, x, y, 1, bombs);
      bombsCheck(tabVisible, tabHidden, c);
    }
  }
  return 0;
}
