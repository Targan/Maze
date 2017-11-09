#include <QMessageLogger>
#include "gridscene.h"

GridScene::GridScene(QTimer* timer) :
    QGraphicsScene(),
    tm(timer), drawed(false)
{
    addItem(g.getPlayer());
}

bool GridScene::isFinished()
{
    return g.getPlayer()->x() == g.endPos().x() && g.getPlayer()->y() == g.endPos().y();
}

void GridScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    map* m=g.getmap();

    if (!drawed) {
        addRect((g.startPos().x())*pixel, (g.startPos().y())*pixel, pixel, pixel, QPen(Qt::green), QBrush(Qt::green));
        addRect((g.endPos().x())*pixel, (g.endPos().y())*pixel, pixel, pixel, QPen(Qt::red), QBrush(Qt::red));

        int minX, minY, maxX, maxY;
        minX = 0;//std::max(0, int(rect.left() / pixel));
        minY = 0;//std::max(0, int(rect.top() / pixel));
        maxX = m->getWidht();//std::min(int(rect.right() / pixel), m->getWidht());
        maxY = m->getHeight();//std::min(int(rect.bottom() / pixel), m->getHeight());

        QVector2D vect;
        for(int y=minY;y<maxY;y++)
        {
            vect.setY(y);
            for(int x=minX;x<maxX;x++)
            {
                vect.setX(x);
                if(!m->moving(vect,Right))
                {
                    int lineX=pixel*(x+1);
                    int lineY=pixel*y;
                    addLine(lineX, lineY, lineX, lineY+pixel, QPen(Qt::black));
                }
                if(!m->moving(vect,Down))
                {
                    int lineY=pixel*(y+1);
                    int lineX=pixel*x;
                    addLine(lineX, lineY, lineX+pixel, lineY, QPen(Qt::black));
                }
            }
        }

        addLine(0, 0, m->getWidht()*pixel, 0, QPen(Qt::black));
        addLine(0, 0, 0, m->getHeight()*pixel, QPen(Qt::black));
        addLine(0, m->getHeight()*pixel, m->getWidht()*pixel, m->getHeight()*pixel, QPen(Qt::black));
        addLine(m->getWidht()*pixel, 0, m->getWidht()*pixel, m->getHeight()*pixel, QPen(Qt::black));

        drawed = true;
    }

    removeItem(g.getPlayer());
    addItem(g.getPlayer());
}

void GridScene::keyPressEvent(QKeyEvent *event)
{
    if (!tm->isActive()) {
        return;
    }
    switch(event->key()){
        case Qt::Key_Up:
            g.OnMove(Up);
            break;
        case Qt::Key_Left:
            g.OnMove(Left);
            break;
        case Qt::Key_Right:
            g.OnMove(Right);
            break;
        case Qt::Key_Down:
            g.OnMove(Down);
            break;
        default:
            return;
    }
    event->accept();
}
