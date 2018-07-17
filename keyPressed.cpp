#include "keyPressed.hpp"
#include "fieldReveal.hpp"
#include "findNoEmptyRight.hpp"
#include "findNoEmptyLeft.hpp"
#include "findNoEmptyUp.hpp"
#include "findNoEmptyDown.hpp"

void keyPressed(char &c, int &x, int &y, char tabVisible[10][10],
                char tabHidden[10][10]) {
  if (c == 'l') {
    x++;
    findNoEmptyRight(x, y, tabVisible);
  }
  if (c == 'j') {
    x--;
    findNoEmptyLeft(x, y, tabVisible);
  }
  if (c == 'k') {
    y++;
    findNoEmptyDown(x, y, tabVisible);
  }
  if (c == 'i') {
    y--;
    findNoEmptyUp(x, y, tabVisible);
  }
  if (c == 'q') {
    return;
  }
  if (c == 'v') {
    fieldReveal(x, y, tabVisible, tabHidden);
    findNoEmptyRight(x, y, tabVisible);
  }
  c = 'a';
}
