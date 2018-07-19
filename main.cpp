#include "Board.hpp"
#include "kbhit.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char c = '-';
  Board board;
  board.fillHashsZeros();
  board.createBombs();
  while (c != 'q') {
    system("clear");
    board.showTabVisible();
    std::cout << std::endl;
    usleep(70000);
    if (kbhit()) {
      std::cin >> c;
      board.keyPressed(c);
    }
    if (board.getBombs() == 0) {
      system("clear");
      board.showTabVisible();
      board.bombsCheck(c);
    }
  }
  return 0;
}
