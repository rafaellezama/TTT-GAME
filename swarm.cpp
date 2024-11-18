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

void Swarm::get_move()
{
  int move;
  bool validMove = false;

  while (!validMove)
  {
    // Display the current board state (print directly here)
    std::cout << "Current Board State:" << std::endl;
    std::cout << " " << this->board->get_mark(1) << " | " << this->board->get_mark(2) << " | " << this->board->get_mark(3) << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << this->board->get_mark(4) << " | " << this->board->get_mark(5) << " | " << this->board->get_mark(6) << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << this->board->get_mark(7) << " | " << this->board->get_mark(8) << " | " << this->board->get_mark(9) << std::endl;

    std::cout << "What is your move? ";
    std::cin >> move;

    // Check if the move is valid and the cell is not already taken
    if (move >= 1 && move <= 9 && this->board->is_empty(move))
    {
      // Valid move, make the move
      this->board->move(move, this->mark);
      validMove = true; // Exit the loop
    }
    else
    {
      // Invalid move: either out of range or already chosen
      std::cout << "Invalid move. Please choose a number between 1 and 9 that isn't already taken." << std::endl;
    }
  }
}