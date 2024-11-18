#include <iostream>

#include "board.hpp"
#include "console.hpp"
#include "game_state.hpp"
#include "human_player.hpp"
#include "pyromancer.hpp"
#include "game.hpp"
#include "swarm.hpp"

bool continuePlaying()
{
  char choice;
  std::cout << "Do you want to continue playing? (Y/N): ";
  std::cin >> choice;

  while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
  {
    std::cout << "Invalid input! Please enter 'Y' to continue or 'N' to quit: ";
    std::cin >> choice;
  }

  return (choice == 'Y' || choice == 'y');
}
int main()
{
  bool gameRunning = true;

  while (gameRunning)
  {
    Board board;
    GameState game_state(&board);
    Console console(&board);
    Swarm player_one(&board, 'X');
    Pyromancer player_two(&board, 'O');
    Game game(&console, &game_state, &player_one, &player_two);

    game.start();

    gameRunning = continuePlaying();
  }

  std::cout << "bye!" << std::endl;
  return 0;
}