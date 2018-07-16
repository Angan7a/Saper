#include "keyPressed.hpp"
#include "fieldReveal.hpp"

void keyPressed(char &c, int &x, int &y, char tabVisible[10][10],
                char tabHidden[10][10]) {
  if (c == 'l') {
    y++;
  }
  if (c == 'j') {
    y--;
  }
  if (c == 'k') {
    x++;
  }
  if (c == 'i') {
    x--;
  }
  if (c == 'q') {
    return;
  }
  if (c == 'v') {
    fieldReveal(x, y, tabVisible, tabHidden);
  }
  c = 'a';
}
