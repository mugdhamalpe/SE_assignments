#ifndef QTASSIGNMENT1_H
#define QTASSIGNMENT1_H

#include <QMainWindow>
#include<QImage>
#include<QRgb>

QT_BEGIN_NAMESPACE
namespace Ui { class QtAssignment1; }
QT_END_NAMESPACE

class QtAssignment1 : public QMainWindow //single inheritance
{
    Q_OBJECT

public:
    QtAssignment1(QWidget *parent = nullptr);
    ~QtAssignment1();

    void DDA_line(float,float,float,float);
    void display(int,int);
    void scanfill();
    int rgb[3];
    void mousePressEvent(QMouseEvent *);
    float points_x[1000];
    float points_y[1000];
    int point_count=0;

signals:
      void Mouse_Pressed();

private slots:
      void on_pushButton_clicked();

      void on_pushButton_2_clicked();

      void on_pushButton_3_clicked();

private:
    Ui::QtAssignment1 *ui; //pointer instance

};
#endif // QTASSIGNMENT1_H
