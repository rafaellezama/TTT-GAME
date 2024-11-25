#pragma once
#include <array>
#include <iostream>
class Board
{
private:
  std::array<char, 9> moves = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

public:
  void clear();
  void move(int i, char m);
  char get_mark(int i);
  bool is_empty(int move);
};
