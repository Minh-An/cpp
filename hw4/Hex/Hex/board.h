//Hex Board class
#include <time.h>
#include <iostream>
#include <vector>
#include "stdafx.h"

using namespace std;

class HexBoard {

public:

	enum class Color { RED, BLUE, GREY };

	HexBoard(int n, bool first);
	bool LegalMove(int row, int col);
	void UpdateBoard(int row, int col, bool player);
	int ComputerMove();
	bool PlayerWins(int row, int col);
	bool ComputerWins(int row, int col);

	friend ostream& operator<<(ostream& out, HexBoard& hex);

protected:
	int n;
	Color playerColor;
	Color computerColor;
	vector<Color> colors;
	vector<vector<int>> edgelist;
	
	vector<int> Adjacent(int row, int col);
	char ColorAt(int row, int col);
	void DFS(vector<bool>& marked, int v, Color color);
};
