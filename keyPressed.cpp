#include "keyPressed.hpp"

void keyPressed(char& c, int& x, int& y, char tabVisible[10][10], char tabHidden[10][10]) {
  if (c == 'l') {
    x++;
  }
  if (c == 'j') {
    x--;
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
      tabVisible[y][x] = tabHidden[y][x];
  }
  c = 'a';
}
