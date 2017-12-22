// This is a .h file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#ifndef _boggle_h
#define _boggle_h

#include <iostream>
#include <string>
#include "lexicon.h"
using namespace std;

class Boggle {
public:
    Boggle(Lexicon& dictionary, string boardText = "");
    char getLetter(int row, int col);
    bool checkWord(string word);
    bool humanWordSearch(string word);
    Set<string> computerWordSearch();
    int getScoreHuman();
    int getScoreComputer();

    // TODO: add any other member functions/variables necessary
    friend ostream& operator<<(ostream& out, Boggle& boggle);

private:
    // TODO: add any other member functions/variables necessary
	int n = 4;
	char board[n][n];
	Set<string> computerWords;
	Set<string> humanWords;
	Set<string> validWords;
	
	unordered_map<int, vector<int>> adj;
	
	void dfs();
	void dfs(int v, string prefix, bool[] marked)
	void adjacentBlocks();
};

#endif // _boggle_h
