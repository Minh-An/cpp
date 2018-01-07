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

    void DrawHexBoard();
    int ComputerMove();
    bool PlayerWins(int id);
    bool ComputerWins(int id);
    Player GetTurn();
    void SetTurn(Player player);
    int GetLastId();
public slots:
    void SwitchTurns(int id);
private:

    bool LegalMove(int id);

    MonteCarlo evaluation;
    int n;
    QList<Hex*> hexes;
    std::vector<std::vector<int>> edgelist;
    std::vector<Player> players;
    Player whosTurn;
    bool gameOver;

    std::vector<int> Adjacent(int row, int col);
    void DFS(std::vector<bool> &marked, int v, Player player, bool &beginMarked, bool &endMarked);

};

#endif // HEXBOARD_H
