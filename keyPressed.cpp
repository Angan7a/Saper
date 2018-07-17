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
    findNoEmptyRight(x, y, tabVisible);
  }
  if (c == 'j') {
    findNoEmptyLeft(x, y, tabVisible);
  }
  if (c == 'k') {
    findNoEmptyDown(x, y, tabVisible);
  }
  if (c == 'i') {
    findNoEmptyUp(x, y, tabVisible);
  }
  if (c == 'q') {
    return;
  }
  if (c == '?' && tabVisible[y][x] == '#' ) {
    tabVisible[y][x] = '?';
  }
  if (c == '?' && tabVisible[y][x] == '@') {
    tabVisible[y][x] = '?';
    bombs++;
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
