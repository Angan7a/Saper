#include "gameOptions.hpp"
#include "kbhit.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

void gameOptions(int &size_x, int &size_y, int &bombs) {
  std::string options[4] = {"Podaj poziom trudności", "Hard", "Medium", "Easy"};
  system("clear");
  int dificulty;
  dificulty = optionSelect(options);
  switch (dificulty) {
  case 1:
    size_x = 50;
    size_y = 50;
    break;
  case 2:
    size_x = 30;
    size_y = 30;
    break;
  case 3:
    size_x = 10;
    size_y = 10;
    break;
  }
  std::cin.clear();
  std::cin.ignore(10, '\n');
  system("clear");
  int bombs_number;
  options[0] = "Wybierz ilość bomb";
  std::cout << "Wybierz ilość bomb:\n";
  if (dificulty == 1) {
    options[1] = "25";
    options[2] = "50";
    options[3] = "100";
    bombs_number = optionSelect(options);
    switch (bombs_number) {
    case 1:
      bombs = 25;
      break;
    case 3:
      bombs = 100;
      break;
    case 2:
      bombs = 50;
      break;
    }

  } else if (dificulty == 2) {
    options[1] = "15";
    options[2] = "30";
    options[3] = "60";
    bombs_number = optionSelect(options);

    switch (bombs_number) {
    case 1:
      bombs = 15;
      break;
    case 3:
      bombs = 60;
      break;
    case 2:
      bombs = 30;
      break;
    }

  } else {
    options[1] = "5";
    options[2] = "10";
    options[3] = "20";
    bombs_number = optionSelect(options);

    switch (bombs_number) {
    case 1:
      bombs = 5;
      break;
    case 3:
      bombs = 20;
      break;
    case 2:
      bombs = 10;
      break;
    }
  }

  std::cin.ignore(10, '\n');
}

int optionSelect(std::string options[4]) {
  char c;
  int line = 1, loop = 1;
  while (loop) {
    system("clear");
    for (int i = 0; i < 4; i++) {
      if (i == line)
        std::cout << "\033[1;43m";
      std::cout << options[i] << std::endl;
      if (i == line)
        std::cout << "\033[0m";
    }
    while (!kbhit(c)) {
      usleep(7000);
    }
    changeLine(c, line, loop);
  }
  return line;
}

void changeLine(char c, int &line, int &loop) {
  if (c == 65 && line > 1)
    line--;
  if (c == 66 && line < 3)
    line++;
  if (c == 10)
    loop = 0;
}
