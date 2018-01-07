#include "stdafx.h"
#include "board.h"

HexBoard::HexBoard(int n, bool first) :n(n) 
{
	srand(time(NULL));
	colors.resize(n*n);
	edgelist.resize(n*n);

	if (first) 
	{
		playerColor = Color::BLUE;
		computerColor = Color::RED;
	}
	else
	{
		playerColor = Color::RED;
		computerColor = Color::BLUE;
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			colors[count] = Color::GREY;
			edgelist[count] = Adjacent(i,j);
			count++;
		}
	}
};

bool HexBoard::LegalMove(int row, int col)
{
	if (row >= 0 && row < n && col >= 0 && col < n)
	{
		if (colors[row*n+col] == Color::GREY)
		{
			return true;
		}
	}
	return false;
};

void HexBoard::UpdateBoard(int row, int col, bool player)
{
	if (player)
	{
		colors[row*n + col] = playerColor;
	}
	else
	{
		colors[row*n + col] = computerColor;
	}
};

int HexBoard::ComputerMove()
{
	int row, col;
	do
	{
		row = rand() % n;
		col = rand() % n;
	} while (!LegalMove(row, col));
	UpdateBoard(row,col, false);
	return row * n + col;
}

bool HexBoard::PlayerWins(int row, int col)
{
	vector<bool> marked(n*n);
	DFS(marked, row*n + col, playerColor);
	bool beginMarked = false;
	bool endMarked = false;
	for (int i = 0; i < n; i++)
	{
		int begin, end;
		if (playerColor == Color::BLUE)
		{
			begin = i * n;
			end = begin + n - 1;
		}
		else //player color is RED
		{
			begin = i;
			end = begin + n * (n - 1);
		}

		//check for first column/row marked
		if (marked[begin])
		{
			beginMarked = true;
		}
		//check for last column/row marked
		if (marked[end])
		{
			endMarked = true;
		}
	}
	return beginMarked && endMarked;
};

bool HexBoard::ComputerWins(int row, int col)
{
	vector<bool> marked(n*n);
	DFS(marked, row*n + col, computerColor);
	bool beginMarked = false;
	bool endMarked = false; 
	for (int i = 0; i < n; i++)
	{
		int begin, end;
		if (computerColor == Color::BLUE)
		{
			begin = i * n;
			end = begin + n - 1;
		}
		else //computer color is RED
		{
			begin = i;
			end = begin + n * (n - 1);
		}

		//check for first column/row marked
		if (marked[begin])
		{
			beginMarked = true;
		}
		//check for last column/row marked
		if (marked[end])
		{
			endMarked = true;
		}
	}
	return beginMarked && endMarked;
};


vector<int> HexBoard::Adjacent(int row, int col)
{
	vector<int> adj;
	if (row != 0)
	{
		adj.push_back((row-1)*n + col);
		if (col != n-1)
		{
			adj.push_back((row - 1)*n + col + 1);
		}
	}
	if (row != n - 1)
	{
		adj.push_back((row + 1)*n + col);
		if (col != n - 1)
		{
			adj.push_back((row + 1)*n + col - 1);
		}
	}
	if (col != 0)
	{
		adj.push_back(row*n + col - 1);
	}
	if (col != n-1)
	{
		adj.push_back(row*n + col + 1);
	}

	return adj;
};

char HexBoard::ColorAt(int row, int col)
{
	Color c = colors[row * n + col];
	if (c == Color::BLUE)
	{
		return 'X';
	}
	else if (c == Color::RED)
	{
		return 'o';
	}
	else
	{
		return '.';
	}
}
void HexBoard::DFS(vector<bool>& marked, int v, Color color)
{
	marked[v] = true;
	for (int w: edgelist[v])
	{
		if (colors[w] == color && !marked[w])
		{
			DFS(marked, w, color);
		}
	}
};


ostream& operator<<(ostream& out, HexBoard& hex)
{
	for (int i = 0; i < hex.n; i++) {

		for (int k = 0; k < i; k++) {
			out << "  ";
		}

		for (int j = 0; j < hex.n; j++) {
			out << hex.ColorAt(i,j);
			if (j != hex.n - 1) {
				out << " - ";
			}
		}
		out << endl;
		for (int k = 0; k < i; k++) {
			out << "  ";
		}

		if (i != hex.n - 1) {
			for (int j = 0; j < hex.n; j++) {
				out << " \\";
				if (j != hex.n - 1) {
					out << " /";
				}
			}
			out << endl;
		}
	}
	out << endl;
	return out;
};