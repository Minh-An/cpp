//Hex Board class

#include <iostream>
#include <vector>

class HexBoard {
 public:
  HexBoard();
  char getState(int row, int col);
  bool legalMove(int row, int col);
  void computerMove();
  bool gameOver();
  char getWinner();

  friend ostream& operator<<(ostream& out, HexBoard& hex);
 protected:
  int n;
  char** colors;

  vector<vector<int>> edgelist;
  vector<int> adjacent(int row, int col);
  
}
