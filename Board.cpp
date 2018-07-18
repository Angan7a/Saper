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
    x = 1 + rand() % 10;
    y = 1 + rand() % 10;
    tabInt[y][x] = 9;
    for (int i = y - 1; i <= y + 1; i++)
      for (int j = x - 1; j <= x + 1; j++)
        if (tabInt[i][j] != 9)
          tabInt[i][j]++;
  }
  for (int i = 1; i < 11; i++) {
    for (int j = 1; j < 11; j++) {
      tabHidden[i - 1][j - 1] = (tabInt[i][j] % 10) + 48;
    }
  }
}

void Board::keyPressed(char &c) {
  if (c == 'l') {
    findNoEmptyRight();
  }
  if (c == 'j') {
    findNoEmptyLeft();
  }
  if (c == 'k') {
    findNoEmptyDown();
  }
  if (c == 'i') {
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

void Board::bombsCheck(char &c) {
  bool win = true;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      if (tabHidden[i][j] == '9')
        if (tabVisible[i][j] != '@')
          win = false;
  if (win == true)
    std::cout << std::endl << "Wygrales!";
  else
    std::cout << std::endl << "Przegrales!";
  c = 'q';
  std::cin.get();
}

void Board::fieldReveal(int xx, int yy) {
  if (tabHidden[yy][xx] == '9')
    bombs = 0;
  tabVisible[yy][xx] = tabHidden[yy][xx];
  if (tabHidden[yy][xx] == '0') {
    tabVisible[yy][xx] = ' ';
    if (xx > 0 && tabVisible[yy][xx - 1] == '#')
      fieldReveal(xx - 1, yy);
    if (xx < 9 && tabVisible[yy][xx + 1] == '#')
      fieldReveal(xx + 1, yy);
    if (yy > 0 && tabVisible[yy - 1][xx] == '#')
      fieldReveal(xx, yy - 1);
    if (yy < 9 && tabVisible[yy + 1][xx] == '#')
      fieldReveal(xx, yy + 1);
  }
}

void Board::findNoEmptyDown() {
  do {
    y++;
    if (y > 9) {
      x++;
      y = 0;
    }
    if (x > 9) {
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
      x = 9;
    }
    if (y < 0) {
      x = 9;
      y = 9;
    }
  } while (tabVisible[y][x] == ' ');
}

void Board::findNoEmptyRight() {
  do {
    x++;
    if (x > 9) {
      y++;
      x = 0;
    }
    if (y > 9) {
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
      y = 9;
    }
    if (x < 0) {
      x = 9;
      y = 9;
    }
  } while (tabVisible[y][x] == ' ');
}

int Board::getBombs() const { return bombs; }
