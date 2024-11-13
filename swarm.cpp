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

void Swarm::get_move()
{
  // We need to validate this move!
  // Oops! Shall We Try Again lab
  int move;
  std::cout << "What is your move? ";
  std::cin >> move;
  this->board->move(move, this->mark);
}
