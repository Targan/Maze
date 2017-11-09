#include "game.h"
game::game() : start(0,0), finish(19,2)
{
    field=new map("qqq");
    player = new PlayerItem();
    player->setX(start.x());
    player->setY(start.y());
}
void game::OnMove(Direction dir)
{
    QVector2D pos(int(player->pos().x()), int(player->pos().y()));
    if(field->moving(pos, dir))
    {
        switch (dir) {
            case Up:
                player->setY(player->y() - 1);
                break;
            case Down:
                player->setY(player->y() + 1);
                break;
            case Right:
                player->setX(player->x() + 1);
                break;
            case Left:
                player->setX(player->x() - 1);
                break;
        }
    }

}

