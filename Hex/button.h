#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsTextItem>


class Button: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Button(QString name, int n = 0, QGraphicsItem* parent = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
signals:
    void clicked(int n);
private:
    QGraphicsTextItem* text;
    int n;
};

#endif // BUTTON_H
