#ifndef FORCE_H
#define FORCE_H

#include <QVector2D>

class Force final
{
public:                
    Force() = delete;
    static QVector2D gravity;
    static QVector2D windFromEast;
    static QVector2D windFromWest;
};

#endif // FORCE_H
