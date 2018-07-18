#include "Board.hpp"
#include "kbhit.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char c;
  Board board;
  board.fillHashsZeros();
  board.showTabVisible();
  board.createBombs();
  while (c != 'q') {
    system("clear");
    board.showTabVisible();
    std::cout << std::endl;
    board.showTabHidden();
    usleep(70000);
    if (kbhit()) {
      std::cin >> c;
//      keyPressed(c, x, y, bombs, tabVisible, tabHidden);
    }
//    if (bombs == 0) {
//      system("clear");
//      show(tabVisible, x, y, 1, bombs);
//      bombsCheck(tabVisible, tabHidden, c);
//    }
  }
  return 0;
}
