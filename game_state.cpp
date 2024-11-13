#include "game_state.hpp"

GameState::GameState(Board *board)
{
  this->board = board;
}

bool GameState::winning_combo(std::vector<int> combo)
{
  if (combo.size() == 3)
  {
    return board->get_mark(combo.at(0)) == board->get_mark(combo.at(1)) && board->get_mark(combo.at(1)) == board->get_mark(combo.at(2));
  }
  else
  {
    // figure out how to check if there are three copies of the same mark in the list of four indices
  }
}

std::string GameState::select_winner(int cell)
{
  std::string output = "";
  output += board->get_mark(cell);
  output += " wins";
  return output;
}

std::string GameState::current_state(Player *current_player)
{
  std::vector<std::vector<int>> combos = current_player->get_winning_combos().all();
  std::vector<std::vector<int>>::iterator combo_iterator;

  for (combo_iterator = combos.begin(); combo_iterator != combos.end(); combo_iterator++)
  {
    if (this->winning_combo(*combo_iterator))
    {
      return select_winner(combo_iterator->at(0));
    }
  }

  return "in-progress";
}
