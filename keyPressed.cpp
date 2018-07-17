#include "keyPressed.hpp"
#include "bombMarker.hpp"
#include "fieldReveal.hpp"
#include "findNoEmptyLeft.hpp"
#include "findNoEmptyUp.hpp"
#include "findNoEmptyDown.hpp"
#include "findNoEmptyRight.hpp"

void keyPressed(char &c, int &x, int &y, int &bombs, char tabVisible[10][10],
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
    fieldReveal(x, y, bombs, tabVisible, tabHidden);
    findNoEmptyRight(x, y, tabVisible);
  }
  if (c == 'b') {
    bombMarker(x, y, bombs, tabVisible);
  }
  c = 'a';
}
