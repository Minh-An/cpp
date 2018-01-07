#include "hexboard.h"
#include "hexgame.h"

#include <iostream>

extern HexGame* game;

HexBoard::HexBoard(int n): n(n)
{
    players.resize(n*n);
    edgelist.resize(n*n);
    whosTurn = Player::BLUE;
    gameOver = false;
}

void HexBoard::DrawHexBoard()
{
    const size_t yMargin = 100;
    const size_t xMargin = 25;
    int count = 0;
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            //add hex to scene
            Hex* hex = new Hex(count);
            hexes.append(hex);
            size_t rowShift = hex->boundingRect().width() / 2 * i;
            size_t columnShift = hex->boundingRect().width() * j;
            hex->setPos(xMargin + rowShift + columnShift, yMargin + hex->boundingRect().height()*2/3*i);
            connect(hex, SIGNAL(clicked(int)), this, SLOT(SwitchTurns(int)));
            game->scene->addItem(hex);

            //update edgelist and players
            players[count] = Player::EMPTY;
            edgelist[count] = Adjacent(i,j);
            count++;
        }
    }
}

bool HexBoard::LegalMove(int id)
{
    if (id >= 0 && id < n*n)
    {
        if (players[id] == Player::EMPTY)
        {
            return true;
        }
    }
    return false;
}

int HexBoard::ComputerMove()
{
    int randId;
    do
    {
        randId = rand() % (n*n);
    } while (!LegalMove(randId));
    hexes.at(randId)->Paint(Player::RED);
    players.at(randId) = Player::RED;
    whosTurn = Player::BLUE;
    return randId;
}

bool HexBoard::PlayerWins(int id)
{
    std::vector<bool> marked(n*n, false);
    bool beginMarked = false;
    bool endMarked = false;
    DFS(marked, id, Player::BLUE, beginMarked, endMarked);
    return beginMarked && endMarked;
}

bool HexBoard::ComputerWins(int id)
{
    std::vector<bool> marked(n*n, false);
    bool beginMarked = false;
    bool endMarked = false;
    DFS(marked, id, Player::RED, beginMarked, endMarked);
    return beginMarked && endMarked;
}

Player HexBoard::GetTurn()
{
    return whosTurn;
}

void HexBoard::SetTurn(Player player)
{
    whosTurn = player;
}

void HexBoard::SwitchTurns(int id)
{
    if(whosTurn == Player::BLUE && LegalMove(id) && !gameOver)
    {
        hexes.at(id)->Paint(Player::BLUE);
        players.at(id) = Player::BLUE;
        if(PlayerWins(id))
        {
               game->turnText->setPlainText("YOU WON!!!");
               gameOver = true;
               return;
        }
        whosTurn = Player::RED;
        game->UpdateTurn();
        int computerId = ComputerMove();
        game->UpdateTurn();
        if(ComputerWins(computerId))
        {
            game->turnText->setPlainText("YOU LOST :(");
            gameOver = true;
            return;
        }
    }
}


std::vector<int> HexBoard::Adjacent(int row, int col)
{
    std::vector<int> adj;
    if (row > 0)
    {
        adj.push_back((row-1)*n + col);
        if (col != n-1) adj.push_back((row - 1)*n + col + 1);
    }
    if (row < n - 1)
    {
        adj.push_back((row + 1)*n + col);
        if (col != 0) adj.push_back((row + 1)*n + col - 1);
    }
    if (col > 0) adj.push_back(row*n + col - 1);
    if (col < n-1) adj.push_back(row*n + col + 1);

    return adj;
}

void HexBoard::DFS(std::vector<bool>& marked, int v, Player player, bool& beginMarked, bool& endMarked)
{
    marked[v] = true;
    if(player == Player::BLUE)
    {
        if(v%n == 0) beginMarked = true;
        if(v%n == n-1) endMarked = true;
    }
    else if(player == Player::RED)
    {
        if(v/n == 0) beginMarked = true;
        if(v/n == n-1) endMarked = true;
    }
    for (int w: edgelist[v])
    {
        if (players[w] == player && !marked[w])
        {
            DFS(marked, w, player, beginMarked, endMarked);
        }
    }
}
