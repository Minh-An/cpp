#ifndef HEXBOARD_H
#define HEXBOARD_H

#include <vector>
#include <QList>

#include "player.h"
#include "hex.h"
#include "montecarlo.h"

class HexBoard: public QObject
{
    Q_OBJECT
public:
    HexBoard(int n);

    Player WhosTurn;
    void DrawHexBoard();
    int ComputerMove();
    bool HasPlayerWon(int id);
    bool HasComputerWon(int id);
public slots:
    void SwitchTurns(int id);
private:
    friend class MonteCarlo;
    bool IsLegalMove(int id);

    int n;
    QList<Hex*> hexes;
    std::vector<std::vector<int>> edgelist;
    std::vector<Player> players;
    bool gameOver;

    std::vector<int> Adjacent(int row, int col);
    void DFS(std::vector<bool> &marked, int v, Player player, bool &beginMarked, bool &endMarked);

};

#endif // HEXBOARD_H
