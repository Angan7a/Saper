#include "Board.hpp"
#include "gameOptions.hpp"
#include "kbhit.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char c = '-';
  int size_x, size_y, bombs;
  gameOptions(size_x, size_y, bombs);
  Board board(size_x / 2, size_y / 2, bombs, size_x, size_y);
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
      board.showEndingBoard(board.bombsCheck(c));
    }
  }
  return 0;
}
