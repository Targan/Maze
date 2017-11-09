#ifndef GRIDSCENE_H
#define GRIDSCENE_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include <game.h>

#include "common.h"

class GridScene : public QGraphicsScene
{
        Q_OBJECT
    public:
        explicit GridScene(QTimer* timer);

        bool isFinished();

    signals:

    public slots:

    protected:
        void drawBackground(QPainter *painter, const QRectF &rect);
        void keyPressEvent(QKeyEvent *event);
    private:
        game g;
        QTimer* tm;
        bool drawed;
};

#endif // GRIDSCENE_H
