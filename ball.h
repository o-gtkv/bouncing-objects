#ifndef BALL_H
#define BALL_H

#include <QPainter>
#include <QColor>
#include <QVector2D>
#include <QMainWindow>

#include "force.h"

class Ball
{
public:
    enum class Direction
    {
        LEFT, RIGHT
    };

    Ball() = default;
    Ball(QMainWindow* scene, int radius, QColor color);
    void update();
    void draw(QPainter& painter) const;
    void applyForce(QVector2D force);
    void _checkBounds();

private:
    QColor       _color;
    QMainWindow* _scene;
    int          _radius;
    float        _mass;
    QVector2D    _velocity;
    QVector2D    _acceleration;
    QVector2D    _location;
};


#endif // BALL_H
