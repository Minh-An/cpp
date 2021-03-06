// Hex 

#include "stdafx.h"
#include <string>
#include <algorithm>
#include "board.h"


int main() {

	cout << "Welcome to the game of HEX!" << endl;

	int n;
	cout << "How many rows/columns on your board? (0-15): ";
	cin >> n;
	
	while (n < 0 || n > 15)
	{
		cout << "Input a number from 0-15: ";
		cin.clear();
		cin.ignore();
		cin >> n;
	}

	cout << "Blue goes first! Would you like to be blue or red? ";
		
	char c;
	bool first;

	do
	{
		cout << "Type in b or r: ";
		cin >> c;

		//Check if players wants to go first
		if (c == 'b')
		{
			first = true;
		}
		else if (c == 'r')
		{
			first = false;
		}
	} while (c != 'b' && c != 'r' );

	HexBoard hex = HexBoard(n, first);


	//if computer goes first
	if (!first)
	{
		hex.ComputerMove();
	}


	//Main gameplay
	while(true)
	{
		
		system("cls");
		cout << hex;

		//Player's turn
		cout << "Make your move! Choose a block on the board that is not yet taken (represented by '.')" << endl;
		
		int row, col;
		//Player inputs a row and column for the block they want to play
		do
		{
			cout << "row and column (seperated by space) from 0 to " << n-1 << ": ";
			cin.clear();
			cin.ignore();
			cin >> row >> col;
		//continue prompting user until they make a valid move
		} while (!cin.good() || !hex.LegalMove(row, col)); 
		hex.UpdateBoard(row, col, true);
		
		system("cls");
		cout << hex;

		if (hex.PlayerWins(row, col))
		{
			cout << "YOU WON!!!! Congratulations!!!" << endl;
			cout << "Type any character to quit: ";
			cin >> c;
			return 0;
		}

		//Computer's turn
		int x = hex.ComputerMove();
		row = x / n;
		col = x % n;
		cout << "Computer's turn! Type any character to continue and q to quit: ";
		cin >> c;

		//Check if the user wants to quit
		if (c == 'q')
		{
			return 0;
		}

		if (hex.ComputerWins(row, col))
		{
			system("cls");
			cout << hex;
			cout << "You lost! :( Try again next time." << endl;
			cout << "Type any character to quit: ";
			cin >> c;
			return 0;
		}
	}
}

