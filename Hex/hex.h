#ifndef HEX_H
#define HEX_H

#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>

#include "player.h"


class Hex: public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT
public:
    Hex(int id, QGraphicsItem* parent = NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    void Paint(Player player);
signals:
    void clicked(int hexId);
private:
    Player owner;
    int id;
};

#endif // HEX_H
