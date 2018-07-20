#include "gameOptions.hpp"
#include <iostream>
#include <stdlib.h>

void gameOptions(int &size_x, int &size_y, int &bombs) {
  char c;
  system("clear");
  std::cout << "Podaj poziom trudności:" << std::endl
            << "h-hard\nm-medium\ne-easy\n";
  std::cin >> c;
  switch (c) {
  case 'h':
    size_x = 50;
    size_y = 50;
    break;
  case 'm':
    size_x = 30;
    size_y = 30;
    break;
  default:
    size_x = 10;
    size_y = 10;
    break;
  }
  std::cin.clear();
  std::cin.ignore(10, '\n');
  system("clear");
  std::cout << "Wybierz ilość bomb:\n";
  if (c == 'h') {
    std::cout << "1. 25\n2. 50\n3. 100\n"
              << "Podaj numer:";
    std::cin.get(c);
    switch (c) {
    case '1':
      bombs = 25;
      break;
    case '3':
      bombs = 100;
      break;
    default:
      bombs = 50;
      break;
    }

  } else if (c == 'm') {
    std::cout << "1. 15\n2. 30\n3. 60\n"
              << "Podaj numer:";
    std::cin.get(c);
    switch (c) {
    case '1':
      bombs = 15;
      break;
    case '3':
      bombs = 60;
      break;
    default:
      bombs = 30;
      break;
    }

  } else {
    std::cout << "1. 5\n2. 10\n3. 20\n"
              << "Podaj numer:";
    std::cin.get(c);
    switch (c) {
    case '1':
      bombs = 5;
      break;
    case '3':
      bombs = 20;
      break;
    default:
      bombs = 10;
      break;
    }
  }

  std::cin.ignore(10, '\n');
}
