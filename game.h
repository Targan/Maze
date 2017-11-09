#ifndef GAME_H
#define GAME_H
#include <QTimer>
#include "map.h"
#include "playeritem.h"

class game
{
    public:
        game();
        void OnMove(Direction);
        void setPause(bool pauseOn);
        map *getmap(){return field;}
        PlayerItem *getPlayer() { return player; }
        QVector2D startPos() { return start; }
        QVector2D endPos() { return finish; }

    private:
        QVector2D start;
        QVector2D finish;
        QVector2D pause;
        map *field;
        PlayerItem *player;
};

#endif // GAME_H
