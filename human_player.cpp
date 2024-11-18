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
  int move;
  while (true)
  {
    std::cout << "What is your move? ";
    std::cin >> move;

    if (move >= 1 && move <= 9 && this->board->is_empty(move))
    {
      this->board->move(move, this->mark);
      break;
    }
    else
    {
      std::cout << "Invalid move! Please enter a cell number between 1 and 9 that is not already occupied." << std::endl;
    }
  }
}
