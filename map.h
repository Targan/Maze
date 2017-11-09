#ifndef MAP_H
#define MAP_H
#include <QVector2D>
#include <QFile>
enum Direction
{
    Up,Down,Left,Right
};
#define BITBOTTOM 1
#define BITRIGHT 2

class map
{
    public:
        map(QString FName);
        bool moving(QVector2D pos,Direction direct);
        int getWidht(){return width;}
        int getHeight(){return height;}
    private:
        int width, height;
        char *save;
};

#endif // MAP_H
