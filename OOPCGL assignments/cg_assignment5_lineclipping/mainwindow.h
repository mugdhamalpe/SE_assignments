#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int ver=0;
    bool start,flag;
    float a[100],b[100];
    float xmin,ymin,xmax,ymax;

protected:
    void mousePressEvent(QMouseEvent *ev);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void dda(float x1, float y1, float x2, float y2);
    void Bres(float x1, float y1, float x2, float y2);
    void code(int c[4],float x,float y);
    void test(int c[4],int d[4]);
    void Clip(int c[4],int d[4],float &x,float &y,float m);
    float sign(float x);

    void on_pushButton_4_clicked();
};
#endif // MAINWINDOW_H
