#include "Board.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int main() {
  Board board;
  board.fillHashsZeros();
  board.showTabVisible();
/*  createBombs(tabHidden);
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
  }*/
  return 0;
}
