#pragma once

class Board {
  int x, y, bombs;
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
