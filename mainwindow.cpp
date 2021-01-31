#include <QDateTime>

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{        
    connect(&_timer, SIGNAL(timeout()), this, SLOT(onTimerSlot()));
    _timer.setInterval(10);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(_scene);
    painter.drawText(10, 20, "A - push to left; B - push to right");
    for (auto& b : _ball) {
        b.update();
        b.draw(painter);
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
    case 'A':
        for(auto& b : _ball)
            b.applyForce(Force::windFromWest);
        break;
    case 'D':
        for(auto& b : _ball)
            b.applyForce(Force::windFromEast);
        break;
    default:
        ;
    }
}

void MainWindow::runScene()
{
    QColor c;
    QRandomGenerator g(static_cast<quint32>(QDateTime::currentMSecsSinceEpoch()));
    int r = g.generate()%10 + 5;
    for (int i = 0; i < 15; i++) {
        c.setRgb(g.generate()%255, g.generate()%255, g.generate()%255);
        _ball.push_back(Ball(_scene, r, c));
        r += 2;
    }
    _timer.start();
}

void MainWindow::onTimerSlot()
{
    _scene->update();
}
