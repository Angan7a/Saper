#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "show.hpp"

int main() {
  int x = 4, y = 6;
  char tabHidden[10][10];
  char tabVisible[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tabVisible[i][j] = '#';
      tabHidden[i][j] = '0';
    }
  }
  while (1) {
    system("clear");
    show(tabVisible, x, y, 1);
    std::cout << std::endl;
    show(tabHidden, x, y, 1);
    usleep(700000);

    system("clear");
    show(tabVisible, x, y, 0);
    std::cout << std::endl;
    show(tabHidden, x, y, 0);
    usleep(700000);
  }
  return 0;
}
