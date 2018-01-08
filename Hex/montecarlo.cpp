#include "montecarlo.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

MonteCarlo::MonteCarlo(const std::vector<Player>& players, int n,
                       const std::vector<std::vector<int>>& edgelist):players(players), n(n), edgelist(edgelist)
{
    std::srand ( unsigned ( std::time(0) ) );
}

int MonteCarlo::Score(int id)
{
    std::vector<int> emptyHexes;
    std::vector<Player> playersCopy = players;
    playersCopy[id] = Player::RED;
    for(int i = 0; i < players.size(); i++)
    {
        if(playersCopy[i] == Player::EMPTY)
        {
            emptyHexes.push_back(i);
        }
    }


    int computerWins = 0;
    for(int trial = 0; trial < TRIALS; trial++)
    {
        std::random_shuffle(emptyHexes.begin(), emptyHexes.end());
        Player next = Player::BLUE;
        for(int id: emptyHexes)
        {
            playersCopy[id] = next;
            next = (next == Player::BLUE) ? Player::RED : Player::BLUE;
        }

        bool endMarked = false;
        std::vector<bool> marked(n*n, false);
        for(int i = 0; i < n; i++)
        {
            if(playersCopy[i] == Player::RED && !endMarked)
            {
                DFS(marked, i, endMarked, playersCopy);
            }
        }
        if(endMarked)
        {
            computerWins++;
        }
    }
    return computerWins;
}

void MonteCarlo::DFS(std::vector<bool> &marked, int v, bool &endMarked, const std::vector<Player> &playersCopy)
{
    marked[v] = true;

    if(v/n == n-1)
    {
        endMarked = true;
        return;
    }
    for (int w: edgelist[v])
    {
        if (playersCopy[w] == Player::RED && !marked[w])
        {
            DFS(marked, w, endMarked, playersCopy);
            if(endMarked)
            {
                return;
            }
        }
    }
}
