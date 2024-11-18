#include <iostream>
#include <vector>

#include "swarm.hpp"

Swarm::Swarm(Board *board, char mark)
{
  this->board = board;
  this->mark = mark;

  std::vector<int> additional_win = {1, 3, 7, 9};
  this->combos = WinningCombos(additional_win);
}

char Swarm::get_mark()
{
  return this->mark;
}

WinningCombos Swarm::get_winning_combos()
{
  return this->combos;
}

WinningCombos Swarm::get_winning_combos()
{
  return this->combos;
}

void Swarm::get_move()
{
  int move;
  bool valid_move = false;

  while (!valid_move)
  {
    std::cout << "What is your move? ";
    std::cin >> move;

    if (std::cin.good() && this->board->is_empty(move))
    {
      this->board->move(move, this->mark);
      valid_move = true;
    }
    else
    {
      std::cout << "Invalid move. Try again.\n";
    }
  }
}