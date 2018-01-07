#include "hex.h"
#include <QBrush>


Hex::Hex(int id, QGraphicsItem *parent): id(id)
{
    QVector<QPointF> hexPoints;
    hexPoints << QPointF(0,4) << QPointF(5,0) << QPointF(10, 4) << QPointF(10,8) << QPointF(5, 12) << QPointF(0,8);

    const int SCALE_BY = 6;
    for(QPointF& point: hexPoints)
    {
        point *= SCALE_BY;
    }

    QPolygonF hexagon(hexPoints);

    setPolygon(hexagon);
    Paint(Player::EMPTY);
}


void Hex::Paint(Player player)
{
    owner = player;
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    switch(player)
    {
        case Player::BLUE:
            brush.setColor(Qt::blue);
            break;
        case Player::RED:
            brush.setColor(Qt::red);
            break;
        default:
            brush.setColor(Qt::gray);
    }
    setBrush(brush);
}

void Hex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked(this->id);
}
