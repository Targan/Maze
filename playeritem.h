#ifndef PLAYERITEM_H
#define PLAYERITEM_H

#include <QGraphicsItem>
#include <QPainter>

#include "common.h"

class PlayerItem : public QGraphicsItem
{
    public:
        PlayerItem();

        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PLAYERITEM_H
