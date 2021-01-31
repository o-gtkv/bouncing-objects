#include "ball.h"

Ball::Ball(QMainWindow* scene, int radius, QColor color)
    : _color{color}, _scene{scene}, _radius{radius}, _mass{radius / 10.f + 1},
      _velocity{0, 0}, _acceleration{0, 0},
      _location{_scene->width()/2.f, _scene->height()/2.f}
{
}

void Ball::update()
{
    _acceleration += Force::gravity/_mass;
    _velocity += _acceleration;
    _location += _velocity;
    _checkBounds();
    _acceleration.setX(0);
    _acceleration.setY(0);
}

void Ball::draw(QPainter& painter) const
{
    QBrush brush(_color);
    painter.setBrush(brush);
    painter.drawEllipse(static_cast<int>(_location.x()),
                        static_cast<int>(_location.y()),
                        2*_radius, 2*_radius);
}

void Ball::applyForce(QVector2D force)
{
    _acceleration += force;
}

void Ball::_checkBounds()
{
    if (_location.x() - _radius < 0)
    {
        _velocity.setX(-_velocity.x() / _mass);
        _location.setX(_radius);
    }
    else if (_location.x() + _radius > _scene->width())
    {
        _velocity.setX(-_velocity.x() / _mass);
        _location.setX(_scene->width() - _radius);
    }
    else if (_location.y() - _radius < 0)
    {
        _velocity.setY(-_velocity.y());
        _location.setY(_radius);
    }
    else if (_location.y() + _radius > _scene->height())
    {
        _velocity.setY(-_velocity.y());
        _location.setY(_scene->height() - _radius);
    }
}
