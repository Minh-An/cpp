// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header
// TODO: remove this comment header
// TODO: remove this comment header
#include "Boggle.h"

// letters on all 6 sides of every cube
static string CUBES[16] = {
    "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
    "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
    "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
    "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};

// letters on every cube in 5x5 "Big Boggle" version (extension)
static string BIG_BOGGLE_CUBES[25] = {
   "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
   "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
   "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
   "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
   "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

Boggle::Boggle(Lexicon& dictionary, string boardText) {
    // TODO: implement
	for(int i=0; i<n; i++)  
	{
		for(int j=0; j<n; j++) 
		{
			board[i][j] = '?'; //TODO INITIALIZE BOARD
		}
	}
}

char Boggle::getLetter(int row, int col) {
    return board[row][col];
}

bool Boggle::checkWord(string word) {
    // TODO: implement
    return false;   // remove this
}

bool Boggle::humanWordSearch(string word) {
    // TODO: implement
    return false;   // remove this
}

int Boggle::getScoreHuman() {
    int score = 0;
	for(string s: humanWords)
	{
		score += s.length() - 3;
	}
	return score;
}

Set<string> Boggle::computerWordSearch() {
    // TODO: implement
    Set<string> result;   // remove this
    return result;        // remove this
}

int Boggle::getScoreComputer() {
    int score = 0;
	for(string s: computerWords)
	{
		score += s.length() - 3;
	}
	return score;
}

ostream& operator<<(ostream& out, Boggle& boggle) {
    // TODO: implement
	for(int i=0; i<n; i++)  
	{
		for(int j=0; j<n; j++) 
		{
			out << board[i][j];
		}
		out << endl;
	}
    return out;
}


void dfs() {
	int tiles = board.rows() * board.cols();
    for (int v = 0; v < tiles; v++) {
        bool marked[tiles];
        string prefix;
        dfs(v, prefix, marked);
    }
}

void dfs(int v, string prefix, boolean[] marked)
 {
    marked[v] = true;
    int row = v / n;
    int col = v % n;

    if(board.getLetter(row, col) == 'Q')
    {
        prefix.append("QU");
    }
    else 
	{
        prefix.append(board.getLetter(row, col));
    }
    if(dict.contains(prefix.toString()) && prefix.length() > 2)
    {
        validWords.add(prefix.toString());
    }
    if(dict.hasPrefix(prefix.toString())) {
        for (int w : adj.get(v)) {
            if (!marked[w]) {
                dfs(board, w, prefix, marked, adj, validWords);
                    prefix.deleteCharAt(prefix.length()-1);
                    if(prefix.charAt(prefix.length()-1) == 'Q')
                    {
                        prefix.deleteCharAt(prefix.length()-1);
                    }
                    marked[w] = false;
                }
            }
        }
    }

void adjacentBlocks()
{
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector<int> adjToIJ;
                if (i != 0) {
                    adjToIJ.push_back((i - 1) * n + j);
                    if (j != 0) {
                        adjToIJ.push_back((i - 1) * n + j - 1);
                    }
                    if (j != n-1) {
                        adjToIJ.push_back((i - 1) * n + j + 1);
                    }
                }
                if (i != n - 1) {
                    adjToIJ.push_back((i + 1) * n + j);
                    if (j != 0) {
                        adjToIJ.push_back((i + 1) * n + j - 1);
                    }
                    if (j != n-1) {
                        adjToIJ.push_back((i + 1) * n + j + 1);
                    }
                }
                if (j != 0) {
                    adjToIJ.push_back((i) * n + j - 1);
                }
                if (j != board.cols()-1) {
                    adjToIJ.push_back((i) * n + j + 1);
                }
                adj.emplace(i * n + j, adjToIJ);
            }
        }
}