#ifndef MONTECARLO_H
#define MONTECARLO_H

#include <vector>
#include <utility>
#include "player.h"

const int TRIALS = 5000;

class MonteCarlo
{
public:
    MonteCarlo(const std::vector<Player>& players, int n, const std::vector<std::vector<int>>& edgelist);
    std::pair<int, int> Score(int id);
private:

    std::vector<std::vector<int>> edgelist;
    std::vector<Player> players;
    int n;
    int maxWins;
    void DFS(std::vector<bool>& marked, int v, bool& endMarked, const std::vector<Player>& playersCopy);
};

#endif // MONTECARLO_H
