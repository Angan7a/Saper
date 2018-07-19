#pragma once

#include <string>

class Board {
  int x, y, bombs;
  std::string keyGuide[10] = {" ", "q - quit", "i - move up", "k - move down", "j - move left", "l - move right", "v - show visible field (number neighbour bombs, or bombs :-))", "b - mark field as bomb", "? - mark field as it can be bomb", " "};
  char tabHidden[10][10];
  char tabVisible[10][10];
  void fieldReveal(int, int);
  void findNoEmptyDown();
  void findNoEmptyLeft();
  void findNoEmptyRight();
  void findNoEmptyUp();
  void bombMarker();
public:
  Board(int x_ = 4, int y_ = 6, int bombs_ = 5);
  void fillHashsZeros();
  void showTabVisible();
  void showTabHidden();
  void createBombs();
  void keyPressed(char&); 
  void bombsCheck(char&);
  int getBombs() const;
};
