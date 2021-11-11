#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMouseEvent>
#include"QColorDialog"
#include<QtDebug>


QImage image(800,800,QImage::Format_RGB888);
QImage image1(800,800,QImage::Format_RGB888);
QColor color;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver=0;
    start=true;
    flag=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Draws window
void MainWindow::on_pushButton_clicked()
{
    xmin=ui->textEdit->toPlainText().toFloat();
    ymin=ui->textEdit_2->toPlainText().toFloat();
    xmax=ui->textEdit_3->toPlainText().toFloat();
    ymax=ui->textEdit_4->toPlainText().toFloat();
    dda(xmin,ymin,xmin,ymax);
    dda(xmin,ymax,xmax,ymax);
    dda(xmax,ymax,xmax,ymin);
    dda(xmax,ymin,xmin,ymin);

    ui->label->setPixmap(QPixmap::fromImage(image));
}
//Before clipping
void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    float x,y,dx,dy,step,xi,yi;
    float i;
    dx=abs(x2-x1);
    dy=abs(y2-y1);

    if(dx>=dy)
    step=dx;
    else
    step=dy;

    xi=(x2-x1)/step;
    yi=(y2-y1)/step;

    x=x1;
    y=y1;

    i=1;
    while(i<=step)
    {
    image.setPixel(x,y,color.rgb());
    x=x+xi;
    y=y+yi;
    i=i+1;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}
//After clipping
void MainWindow::Bres(float x1, float y1, float x2, float y2)
{
        float dx,dy,p;
        float x,y;
        float i=0;
        x=x1;
        y=y1;
         dx=abs(x2-x1);
         dy=abs(y2-y1);
         if(dx>=dy)
         {
           p=2*dy-dx;
           while(i<=dx)
           {image1.setPixel(x,y,color.rgb());
               if(p<0)
               {
                   p=p+2*dy;
               }
               else{
                   p=p+2*(dy-dx);
                   y=y+sign(y2-y1);
               }
               x=x+sign(x2-x1);
               i++;
           }
             }
         else{

             p=2*dx-dy;
             while(i<=dy)
             {image1.setPixel(x,y,color.rgb());
                 if(p<0)
                 {
                     p=p+2*dx;
                 }
                 else{
                     p=p+2*(dx-dy);
                     x=x+sign(x2-x1);
                 }
                 y=y+sign(y2-y1);
                 i++;
             }
         }
         ui->label_2->setPixmap(QPixmap::fromImage(image1));

}
float MainWindow::sign(float x)
{
    if(x<0)
        return -1;
    else
        return 1;
}
//Chooses color
void MainWindow::on_pushButton_3_clicked()
{
    color=QColorDialog::getColor();
}
//Calculates region code
void MainWindow::code(int c[],float x,float y)
{
    if(x<xmin)
    {
        c[0]=1;
    }
    else
    {
        c[0]=0;
    }

    if(x>xmax)
    {
        c[1]=1;
    }
    else
    {
        c[1]=0;
    }

    if(y<ymin)
    {
        c[2]=1;
    }
    else
    {
        c[2]=0;
    }

    if(y>ymax)
    {
        c[3]=1;
    }
    else
    {
        c[3]=0;
    }

}
//line out of window
void MainWindow::test(int c[], int d[])
{
    int i=0;

        for (i=0;i<4;i++)
        {
            if(c[i]!=0 && d[i]!=0)
            {
                flag=false;

            }
        }
}

void MainWindow::Clip(int c[],int d[],float &x,float &y,float m)
{
    int i=0;
    for (i=0;i<4;i++)
        {
            if(c[i]!=0 && d[i]!=0)
            {
                flag=false;
                break;
            }
            if(flag)
            {
                if(c[0]!=0)
                {
                    y=m*(xmin-x)+y;
                    x=xmin;
                }
                else if(c[1]!=0)
                {
                    y=m*(xmax-x)+y;
                    x=xmax;
                }
                else if(c[2]!=0)
                {
                    x=((ymin-y)/m)+x;
                    y=ymin;
                }
                else if(c[3]!=0)
                {
                    x=((ymax-y)/m)+x;
                    y=ymax;
                }
            }
        }
}




void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start)
    {
        int p=ev->pos().x();
        int q=ev->pos().y();
        a[ver]=p;
        b[ver]=q;
        if(ev->button()==Qt::RightButton)
        {
            start=false;
        }
        else
        {
            if(ver%2==1)
            {
                dda(a[ver],b[ver],a[ver-1],b[ver-1]);
            }
        }
        ver++;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    Bres(xmin,ymin,xmin,ymax);
    Bres(xmin,ymax,xmax,ymax);
    Bres(xmax,ymax,xmax,ymin);
    Bres(xmax,ymin,xmin,ymin);
    for(int i=0;i<ver;i=i+2)
    {
        flag=true;
        int t[4],u[4];
        code(t,a[i],b[i]);
        code(u,a[i+1],b[i+1]);
        test(t,u);
        if(flag==false)
        {
            continue;
        }
        float slope=float((b[i+1]-b[i])/(a[i+1]-a[i]));
        Clip(t,u,a[i],b[i],slope);
        Clip(u,t,a[i+1],b[i+1],slope);
        Bres(a[i],b[i],a[i+1],b[i+1]);
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QImage image(800,800,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label_2->setPixmap(QPixmap::fromImage(image));
}
