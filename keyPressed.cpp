#include "keyPressed.hpp"
#include "fieldReveal.hpp"
#include "findNoEmptyRight.hpp"
#include "findNoEmptyLeft.hpp"

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
  }
  if (c == 'i') {
    y--;
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
