#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPoint mouse_pos;

protected:
    void mouseMoveEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
