#include <iostream>

#include "human_player.hpp"

HumanPlayer::HumanPlayer(Board *board, char mark)
{
  this->board = board;
  this->mark = mark;
  this->combos = WinningCombos();
}

char HumanPlayer::get_mark()
{
  return this->mark;
}

WinningCombos HumanPlayer::get_winning_combos()
{
  return this->combos;
}

void HumanPlayer::get_move()
{
  // We need to validate this move!
  // Oops! Shall We Try Again lab
  int move;
  std::cout << "What is your move? ";
  std::cin >> move;
  this->board->move(move, this->mark);
}
