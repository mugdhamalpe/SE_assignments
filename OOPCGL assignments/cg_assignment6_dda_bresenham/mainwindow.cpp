#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage surface(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawCircle(float x, float y, float xc, float yc)
{   //sets the pixel at the specified coordinates to the specified color
    surface.setPixel(x+xc, y+yc, qRgb(255,255,255));
    surface.setPixel(-x+xc, y+yc, qRgb(255,255,255));
    surface.setPixel(x+xc, -y+yc, qRgb(255,255,255));
    surface.setPixel(-x+xc, -y+yc, qRgb(255,255,255));
    surface.setPixel(y+xc, x+yc, qRgb(255,255,255));
    surface.setPixel(y+xc, -x+yc, qRgb(255,255,255));
    surface.setPixel(-y+xc, x+yc, qRgb(255,255,255));
    surface.setPixel(-y+xc, -x+yc, qRgb(255,255,255));

}



//to draw a pixel seperated by 20px
void MainWindow::on_pushButton_clicked() //slot

{   int x,y;
    x = ui->textEdit->toPlainText().toInt();
    y = ui->textEdit_2->toPlainText().toInt();

    surface.setPixel(x,y,qRgb(255,0,0));
    surface.setPixel(x+20,y,qRgb(255,0,0));
    ui->label->setPixmap(QPixmap::fromImage(surface));// GUI thread - put the image in the QLabel
   //method which allows to set image into label
//    QLabel l ;
//    l.setPixmap(QPixmap::fromImage(i));
//    l.show();
//
}

//the dda line will be drawn
void MainWindow::on_pushButton_2_clicked()
{
    int x,y,q,w;
    x = ui->textEdit->toPlainText().toInt();
     y = ui->textEdit_2->toPlainText().toInt();
      q = ui->textEdit_3->toPlainText().toInt();
       w = ui->textEdit_4->toPlainText().toInt();
       DDA_line(x,y,q,w);

}



void MainWindow::display(int x, int y){
    surface.setPixel(x,y,qRgb(255,255,255));
}

void MainWindow::DDA_line(float x1, float y1, float x2, float y2)
{
    float step;
       float dx = (x2-x1);
       float dy = (y2-y1);
       if (abs(dx)>=abs(dy))
       {
           step = abs(dx);
       }
       else
       {
           step = abs(dy);
       }
       float x_inc = dx/step;
       float y_inc = dy/step;
       display(x1,y1);

       for (int i=0; i<step;i++){
           x1 = x1 + x_inc;
           y1 = y1 + y_inc;
           display(x1,y1);

       }
       ui->label->setPixmap(QPixmap::fromImage(surface));
}

void MainWindow::B_circle(float xc, float yc, float r)
{

    float dk;
    float x = 0;
    float y = r;

    dk = 3 - 2*r;
    drawCircle(x,y,xc,yc);
    while(x < y)
    {
        if(dk <= 0)
        {
            dk = dk + (4*x) + 6;
            drawCircle(++x,y,xc,yc);
        }
        else
        {
            dk = dk + (4*(x-y)) + 10;
            drawCircle(++x,--y,xc,yc);
        }
    }


    ui->label->setPixmap(QPixmap::fromImage(surface));

}
//A figure of assi6 will be drawn
void MainWindow::on_pushButton_3_clicked()
{   int xc,yc,r; MainWindow figure;
    xc = ui->textEdit_5->toPlainText().toInt();
     yc = ui->textEdit_6->toPlainText().toInt();
      r = ui->textEdit_7->toPlainText().toInt();
      figure.DDA_line(xc-0.86*r,yc+0.5*r,xc,yc-r);
      figure.DDA_line(xc+0.86*r,yc+0.5*r,xc,yc-r);
      figure.DDA_line(xc-0.86*r,yc+0.5*r,xc+0.86*r,yc+0.5*r);
      figure.B_circle(xc,yc,r);
      figure.B_circle(xc,yc,r/2);
      ui->label->setPixmap(QPixmap::fromImage(surface));
}

//B figure of assi6 will be drawn
void MainWindow::on_pushButton_4_clicked()
{
    int x,y,l,b; MainWindow figure_2;
    float k;
    x = ui->textEdit_8->toPlainText().toInt();
     y = ui->textEdit_9->toPlainText().toInt();
      l = ui->textEdit_10->toPlainText().toInt();
       b = ui->textEdit_11->toPlainText().toInt();
       figure_2.DDA_line(x-l/2,y-b/2,x+l/2,y-b/2);
       figure_2.DDA_line(x-l/2,y-b/2,x-l/2,y+b/2);
       figure_2.DDA_line(x-l/2,y+b/2,x+l/2,y+b/2);
       figure_2.DDA_line(x+l/2,y+b/2,x+l/2,y-b/2);
       figure_2.DDA_line(x,y-b/2,x-l/2,y);
       figure_2.DDA_line(x,y-b/2,x+l/2,y);
       figure_2.DDA_line(x,y+b/2,x-l/2,y);
       figure_2.DDA_line(x,y+b/2,x+l/2,y);

       k = (l * b) / (2 * sqrt((pow(l, 2) + pow(b, 2))));
       figure_2.B_circle(x,y,k);
        ui->label->setPixmap(QPixmap::fromImage(surface));
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->label->clear();

}
