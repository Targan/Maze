#include "map.h"

map::map(QString FName)
{
    QFile file(FName);
    if (!file.open(QIODevice::ReadOnly))
            return;
    file.read((char*)&width,sizeof(int));
    file.read((char*)&height,sizeof(int));
    save=(char*)malloc(width*height);
    file.read(save,width*height);
    file.close();
}

bool map::moving(QVector2D pos, Direction direct)
{
    int x = int(pos.x());
    int y = int(pos.y());
    if(x<0||x>=width||y<0||y>=height)
        return false;
    switch (direct) {
        case Up:
            if(y<1)
                return false;
            return !(save[x + (y-1) * width]&BITBOTTOM);
        case Down:
            if(y>=height-1)
                return false;
            return !(save[x + y * width]&BITBOTTOM);
        case Right:
            if(x>=width-1)
                return false;
            return !(save[x + y * width]&BITRIGHT);
        case Left:
            if(x<1)
                return false;
            return !(save[x-1 + y * width]&BITRIGHT);
        default:
            return false;
    }
}
