#include "Board.hpp"
#include <iostream>

Board::Board(int x_, int y_, int bombs_) : x(x_), y(y_), bombs(bombs_) {}

void Board::fillHashsZeros() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tabVisible[i][j] = '#';
      tabHidden[i][j] = '0';
    }
  }
}


void Board::showTabVisible() { 
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == x && i == y) {
        std::cout << "\033[1;41m" << tabVisible[i][j] << "\033[0m ";
      } else {
        std::cout << tabVisible[i][j] << " ";
      }
    }
    std::cout << std::endl;
  }
  std::cout << "Pozostalo bomb: " << bombs << std::endl;
}
/* void createBombs();
  void bombMarker();
  void bombsCheck();
  void fieldReveal();
  void findNoEmptyDown();
  void findNoEmptyLeft();
  void findNoEmptyRight();
  void findNoEmptyUp();
  void keyPressed();
};*/

