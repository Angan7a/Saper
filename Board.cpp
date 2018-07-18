#include "Board.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>


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

void Board::showTabHidden() { 
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == x && i == y) {
        std::cout << "\033[1;41m" << tabHidden[i][j] << "\033[0m ";
      } else {
        std::cout << tabHidden[i][j] << " ";
      }
    }
    std::cout << std::endl;
  }
}

void Board::createBombs() {
  int tabInt[12][12];
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      tabInt[i][j] = 0;
    }
  }
  srand(time(NULL));
  int x, y;
  for (int k = 0; k < 5; k++) {
    x = 1 + rand() % 11;
    y = 1 + rand() % 11;
    tabInt[y][x] = 9;
    for (int i = y - 1; i <= y + 1; i++)
      for (int j = x - 1; j <= x + 1; j++)
        if (tabInt[i][j] != 9)
          tabInt[i][j]++;
  }
  for (int i = 1; i < 11; i++) {
    for (int j = 1; j < 11; j++) {
      tabHidden[i-1][j-1] = (tabInt[i][j] % 10)+48;
    }
  }
}

/*  void bombMarker();
  void bombsCheck();
  void fieldReveal();
  void findNoEmptyDown();
  void findNoEmptyLeft();
  void findNoEmptyRight();
  void findNoEmptyUp();
  void keyPressed();
};*/

