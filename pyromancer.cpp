#include <iostream>

#include "pyromancer.hpp"

Pyromancer::Pyromancer(Board *board, char mark)
{
  this->board = board;
  this->mark = mark;
  this->combos = WinningCombos();
}

char Pyromancer::get_mark()
{
  return this->mark;
}

WinningCombos Pyromancer::get_winning_combos()
{
  return this->combos;
}

void Pyromancer::get_move()
{
  int option;
  std::cout << "Do you want to (1) enter a cell or (2) explode the board?" << std::endl;
  while (true)
  {
    std::cin >> option;
    if (option == 1 || option == 2)
    {
      break; // valid option, exit loop
    }
    else
    {
      std::cout << "Invalid input! Please enter 1 to enter a cell or 2 to explode the board." << std::endl;
    }
  }

  if (option == 1)
  {
    int move;
    std::cout << "Enter a cell number between 1 and 9." << std::endl;

    // Input validation for move
    while (true)
    {
      std::cin >> move;
      if (move >= 1 && move <= 9 && this->board->is_empty(move))
      {
        this->board->move(move, this->mark);
        break; // valid move
      }
      else
      {
        std::cout << "Invalid move! Please enter a cell number between 1 and 9 that is not already occupied." << std::endl;
      }
    }
  }
  else
  {
    std::cout << "Exploding the board!" << std::endl;
    this->board->clear(); // clear the board, ensure this doesn't reset a winning state unintentionally
  }
}
