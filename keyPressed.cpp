#include "keyPressed.hpp"

void keyPressed(char& c, int& x, int& y) {
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
  c = 'a';
}
