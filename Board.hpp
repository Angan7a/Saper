#pragma once

class Board {
  int x, y, bombs;
  char tabHidden[10][10];
  char tabVisible[10][10];
public:
  Board(int x_ = 4, int y_ = 6, int bombs_ = 5);
  void fillHashsZeros();
  void showTabVisible();
/*  void createBombs();
  void bombMarker();
  void bombsCheck();
  void fieldReveal();
  void findNoEmptyDown();
  void findNoEmptyLeft();
  void findNoEmptyRight();
  void findNoEmptyUp();
  void keyPressed(); */
};
