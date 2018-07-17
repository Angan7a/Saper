#include "bombsCheck.hpp"
#include <iostream>

void bombsCheck(char tabVisible[10][10], char tabHidden[10][10], char &c) {
  bool win = true;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      if (tabHidden[i][j] == '9')
        if (tabVisible[i][j] != '@')
          win = false;
  if (win == true)
    std::cout << std::endl << "Wygrałeś!";
  else
    std::cout << std::endl << "Przegrałeś!";
  c = 'q';
  std::cin.get();
}
