#include "Board.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Board::Board(int x_, int y_, int bombs_, int size_x, int size_y)
    : x(x_), y(y_), bombs(bombs_), sizeX(size_x), sizeY(size_y) {
  keyGuide[0] = " ";
  keyGuide[1] = "q - quit";
  keyGuide[2] = "i - move up";
  keyGuide[3] = "k - move down";
  keyGuide[4] = "j - move left";
  keyGuide[5] = "l - move right";
  keyGuide[6] = "v - show visible field (number neighbour bombs, or bombs :-))";
  keyGuide[7] = "b - mark field as bomb";
  keyGuide[8] = "? - mark field as it can be bomb";
  keyGuide[9] = " ";
  tabHidden = new char *[sizeY];
  tabVisible = new char *[sizeY];
  for (int i = 0; i < sizeY; ++i) {
    tabHidden[i] = new char[sizeX];
    tabVisible[i] = new char[sizeX];
  }
}

void Board::fillHashsZeros() {
  for (int i = 0; i < sizeY; i++) {
    for (int j = 0; j < sizeX; j++) {
      tabVisible[i][j] = '#';
      tabHidden[i][j] = '0';
    }
  }
}

void Board::showTabVisible() {
  for (int i = 0; i < sizeY; i++) {
    for (int j = 0; j < sizeX; j++) {
      if (j == x && i == y) {
        std::cout << "\033[1;41m" << tabVisible[i][j] << "\033[0m ";
      } else {
        std::cout << tabVisible[i][j] << " ";
      }
    }
    if (i < 10)
      std::cout << '\t' << keyGuide[i];
    std::cout << std::endl;
  }
  std::cout << "Bombs left: " << bombs << std::endl;
}

void Board::showTabHidden() {
  for (int i = 0; i < sizeY; i++) {
    for (int j = 0; j < sizeX; j++) {
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
  int **tabInt = new int *[sizeY + 2];
  for (int i = 0; i < sizeY + 2; ++i) {
    tabInt[i] = new int[sizeX + 2];
  }
  for (int i = 0; i < sizeY + 2; i++) {
    for (int j = 0; j < sizeX + 2; j++) {
      tabInt[i][j] = 0;
    }
  }
  srand(time(NULL));
  int x, y;
  int k = bombs;
  while (k) {
    x = 1 + rand() % sizeX;
    y = 1 + rand() % sizeY;
    if (tabInt[y][x] != 9) {
      tabInt[y][x] = 9;
      k--;
      for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
          if (tabInt[i][j] != 9) {
            tabInt[i][j]++;
          }
        }
      }
    }
  }
  for (int i = 1; i < sizeY + 1; i++) {
    for (int j = 1; j < sizeX + 1; j++) {
      tabHidden[i - 1][j - 1] = (tabInt[i][j] % 10) + 48;
    }
  }
  for (int i = 0; i < sizeY + 2; ++i) {
    delete[] tabInt[i];
  }
  delete[] tabInt;
}

void Board::keyPressed(char &c) {
  if (c == 67) {
    findNoEmptyRight();
  }
  if (c == 68) {
    findNoEmptyLeft();
  }
  if (c == 66) {
    findNoEmptyDown();
  }
  if (c == 65) {
    findNoEmptyUp();
  }
  if (c == 'q') {
    return;
  }
  if (c == '?' && tabVisible[y][x] == '#') {
    tabVisible[y][x] = '?';
  }
  if (c == '?' && tabVisible[y][x] == '@') {
    tabVisible[y][x] = '?';
    bombs++;
  }
  if (c == 'v') {
    if (tabVisible[y][x] == '@') {
      bombs++;
    }
    fieldReveal(x, y);
    findNoEmptyRight();
  }
  if (c == 'b') {
    bombMarker();
  }
  c = 'a';
}

void Board::bombMarker() {
  if (tabVisible[y][x] == '#' || tabVisible[y][x] == '?') {
    bombs--;
    tabVisible[y][x] = '@';
  } else if (tabVisible[y][x] == '@') {
    tabVisible[y][x] = '#';
    bombs++;
  }
}

bool Board::bombsCheck(char &c) {
  bool win = true;
  for (int i = 0; i < sizeY; i++)
    for (int j = 0; j < sizeX; j++) {
      if (tabHidden[i][j] == '0')
        tabHidden[i][j] = ' ';
      if (tabHidden[i][j] == '9')
        if (tabVisible[i][j] != '@')
          win = false;
    }
  c = 'q';
  return win;
}

void Board::fieldReveal(int xx, int yy) {
  if (tabHidden[yy][xx] == '9')
    bombs = 0;
  tabVisible[yy][xx] = tabHidden[yy][xx];
  if (tabHidden[yy][xx] == '0') {
    tabVisible[yy][xx] = ' ';
    if (xx > 0 && tabVisible[yy][xx - 1] == '#')
      fieldReveal(xx - 1, yy);
    if (xx < sizeX - 1 && tabVisible[yy][xx + 1] == '#')
      fieldReveal(xx + 1, yy);
    if (yy > 0 && tabVisible[yy - 1][xx] == '#')
      fieldReveal(xx, yy - 1);
    if (yy < sizeY - 1 && tabVisible[yy + 1][xx] == '#')
      fieldReveal(xx, yy + 1);
  }
}

void Board::findNoEmptyDown() {
  do {
    y++;
    if (y > sizeY - 1) {
      x++;
      y = 0;
    }
    if (x > sizeX - 1) {
      x = 0;
      y = 0;
    }
  } while (tabVisible[y][x] == ' ');
}

void Board::findNoEmptyLeft() {
  do {
    x--;
    if (x < 0) {
      y--;
      x = sizeX - 1;
    }
    if (y < 0) {
      x = sizeX - 1;
      y = sizeY - 1;
    }
  } while (tabVisible[y][x] == ' ');
}

void Board::findNoEmptyRight() {
  do {
    x++;
    if (x > sizeX - 1) {
      y++;
      x = 0;
    }
    if (y > sizeY - 1) {
      x = 0;
      y = 0;
    }
  } while (tabVisible[y][x] == ' ');
}

void Board::findNoEmptyUp() {
  do {
    y--;
    if (y < 0) {
      x--;
      y = sizeY - 1;
    }
    if (x < 0) {
      x = sizeX - 1;
      y = sizeY - 1;
    }
  } while (tabVisible[y][x] == ' ');
}

int Board::getBombs() const { return bombs; }

void Board::showEndingBoard(bool win) {
  for (int i = 0; i < sizeY; i++) {
    for (int j = 0; j < sizeX; j++) {
      if (tabVisible[i][j] == '@' && tabHidden[i][j] == '9') {
        std::cout << "\033[42m"
                  << "@"
                  << "\033[0m ";
      } else if (tabHidden[i][j] == '9') {
        std::cout << "\033[1;41m"
                  << "@"
                  << "\033[0m ";
      } else if (tabVisible[i][j] == '@' && tabHidden[i][j] != '9') {
        std::cout << "\033[1;43m"
                  << "@"
                  << "\033[0m ";
      } else {
        std::cout << tabVisible[i][j] << " ";
      }
    }
    std::cout << std::endl;
  }

  if (win == true)
    std::cout << std::endl << "You won!";
  else
    std::cout << std::endl << "You lost!";
  std::cout << std::endl
            << "\033[92mGreen\033[0m-corectly marked bombs" << std::endl
            << "\033[93mYellow\033[0m-bad markings" << std::endl
            << "\033[91mRed\033[0m-unmarked bombs\n";

  std::cin.get();
}
Board::~Board() {
  for (int i = 0; i < sizeY; ++i) {
    delete[] tabVisible[i];
    delete[] tabHidden[i];
  }
  delete[] tabVisible;
  delete[] tabHidden;
}
