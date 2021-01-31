#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QRandomGenerator>
#include <QTimer>
#include <QVector>
#include <QMainWindow>
#include <QKeyEvent>

#include "ball.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void runScene();
    void paintEvent(QPaintEvent*) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent* event) Q_DECL_OVERRIDE;

private:
    QVector<Ball> _ball;
    MainWindow*   _scene = this;
    QTimer        _timer;

private slots:
    void onTimerSlot();
};

#endif // MAINWINDOW_H
