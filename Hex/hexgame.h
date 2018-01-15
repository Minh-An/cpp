#ifndef HEXGAME_H
#define HEXGAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsTextItem>
#include "player.h"

#include "hexboard.h"

class HexGame: public QGraphicsView
{
    Q_OBJECT
public:
    HexGame(QWidget* parent = NULL);
    void DisplayMenu();
    void UpdateTurn();
    QGraphicsScene* scene;
    HexBoard* hexBoard;
    QGraphicsTextItem* turnText;
public slots:
    void StartGame(int n);

};
#endif // HEXGAME_H
