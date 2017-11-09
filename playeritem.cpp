#include "playeritem.h"


PlayerItem::PlayerItem() : QGraphicsItem()
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
}

QRectF PlayerItem::boundingRect() const
{
    return QRectF(x() * pixel - pixel, y() * pixel - pixel, (x() + 1) * pixel + pixel, (y() + 1) * pixel + pixel);
}

void PlayerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::blue));
    painter->setBrush(QBrush(Qt::blue));
    painter->drawRect(x() * (pixel - 0.95) + playersize/4, y() * (pixel - 0.95) + playersize/4, playersize, playersize);
}
