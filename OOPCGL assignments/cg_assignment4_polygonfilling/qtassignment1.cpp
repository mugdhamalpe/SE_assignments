#include "qtassignment1.h"
#include "ui_qtassignment1.h"
#include<QPixmap>
#include<QRgb>
#include<QImage>

#include <utility>
#include <QColorDialog>
#include<QPainter>
#include<iostream>

#include <QMouseEvent>
#include<QDebug>

QImage surface(400,400,QImage::Format_RGB888);
QtAssignment1::QtAssignment1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtAssignment1)
{
    ui->setupUi(this);
}

struct Cood{
    int x;
    int y;
    bool operator<(const Cood& other)
    { if (y==other.y){
            if (x>other.x){
                return false;
            }else{
                return true;
            }
        }else{
      return y < other.y;
        }
    }
};

QtAssignment1::~QtAssignment1()
{
    delete ui;
}

void QtAssignment1::DDA_line(float x1, float y1, float x2, float y2)
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

void QtAssignment1::display(int x, int y)
{
    surface.setPixel(x,y,qRgb(rgb[0],rgb[1],rgb[2]));
}




void QtAssignment1::on_pushButton_clicked()
{
    int x1[]={100, 200, 120,300, 80,  240 };
    int y1[]={100, 60, 150,150, 200,  250 };
    DDA_line(100,100,200,60);
    DDA_line(200,60,300,150);
    DDA_line(300,150,240,250);
    DDA_line(240,250,80,200);
    DDA_line(80,200,120,150);
    DDA_line(120,150,100,100);
    for(int i=0;i<6;i++){
        points_x[i]=x1[i];
        points_y[i]=y1[i];
        }
    points_x[6]= 200;
    points_y[6] = 60;
    point_count=6;

    ui->label->setPixmap(QPixmap::fromImage(surface));
}


void QtAssignment1::on_pushButton_2_clicked()
{
    QColor color;
    color = QColorDialog::getColor();
    rgb[0]=color.red();
    rgb[1]=color.green();
    rgb[2]=color.blue();

}


void QtAssignment1::on_pushButton_3_clicked()
{
    scanfill();
}

void QtAssignment1::scanfill(){
    float x1[1000];
    float y1[1000];

    for (int i =0;i<point_count;i++){
        x1[i]=points_x[i];
        y1[i]=points_y[i];
    }

    float x_at_ymin;
    float x_l_points[100];
    float x_r_points[100];
    float y_l_points[100];
    float y_r_points[100];
    int n = point_count;
    Cood store[100] ;
    for(int i=0;i<n;i++){

        store[i].x = x1[i];
        store[i].y = y1[i];

    }
    std::sort(&store[0], &store[n]);
    x_at_ymin = store[0].x;

    for(int i =0;i<n-1;i++){
        x1[i] = store[i].x;

        y1[i] = store[i].y;
    }


    x_r_points[0] =store[0].x;
    x_l_points[0] =store[0].x;
    y_r_points[0]= store[0].y;
    y_l_points[0]= store[0].y;
    int r = 1; int l = 1;

    for (int j=1;j<n;j++){
        if (x1[j]>x_at_ymin or y1[j]==store[n-1].y ){
            x_r_points[r] = x1[j];
            y_r_points[r]= y1[j];
            r+=1;
        }
        if(x1[j]<x_at_ymin or y1[j]==store[n-1].y) {
            x_l_points[l]=x1[j];
            y_l_points[l]= y1[j];
            l+=1;
        }


        }
    r+=1;
    float x_l[1000];
    x_l[0] = x_at_ymin;
    float x_r[1000];
    x_r[0] = x_at_ymin;
    int b = 0;
    int t = 0  ;
    int offset_l = 0;
    int offset_r = 0;


    while (b<l){
        float dx = x_l_points[b+1]-x_l_points[b];
        float dy = y_l_points[b+1]-y_l_points[b];

        for(int i=1;i<=abs(dy);i++){

            x_l[i+offset_l] = x_l[i-1+offset_l]+(dx/dy);


            }
        offset_l+=dy;
        b+=1;
        }


    while (t<r-2){
        float dx = x_r_points[t+1]-x_r_points[t];
        float dy = y_r_points[t+1]-y_r_points[t];

        for(int i=1;i<=abs(dy);i++){

            x_r[i+offset_r] = x_r[i-1+offset_r]+(dx/dy);
//            std::cout<<"Travel "<<x_r_points[t+1]<<"<-"<<x_r_points[t]<<std::endl;
//            std::cout<<"dx/dy "<<dx/dy<<"dx :"<<dx<<"dy :"<<dy<<std::endl;
//            std::cout<<"Point "<<x_r[i+offset_r]<<std::endl;
            }
        offset_r+=dy;
        t+=1;



    }
    int ymin = y1[0];
    int ymax = y1[n-1];
    int c = 0 ;
    while (ymin<ymax){
        float x_l_value = x_l[c];
        float x_r_value = x_r[c];
        float y_value = ymin;
//        std::cout<<"Left value : "<<x_l_value<<"Right value : "<<x_r_value<<std::endl;
//        std::cout<<"Y value : "<<y_value<<std::endl;
        c+=1;
        ymin+=1;
        DDA_line(x_r_value,y_value,x_l_value,y_value);

    }

}

void QtAssignment1::mousePressEvent(QMouseEvent *event)
{
    float x = event->position().x();
    float y = event->position().y();

    points_x[point_count] = x;
    points_y[point_count] = y;
//    points_x[point_count+1] = points_x[0];
//    points_y[point_count+1] = points_y[0];

//    std::cout<<points_x[point_count]<<points_y[point_count]<<std::endl;
//    std::cout<<points_x[point_count-1]<<points_y[point_count-1]<<std::endl;
    if (point_count>0){
    DDA_line(points_x[point_count-1],points_y[point_count-1],points_x[point_count],points_y[point_count]);
    }else{
        display(x,y);
    }
    point_count+=1;
    ui->label->setPixmap(QPixmap::fromImage(surface));
}
