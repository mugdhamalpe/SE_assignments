//hilbert curve

//Mugdha Malpe
//Roll No.21153     Batch: G1
//Div: SE01
#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

using namespace std;

void move(int j,int h,int &x,int &y)
{
    if(j==1)
        y-=h;
    else if(j==2)
        x+=h;
    else if(j==3)
        y+=h;
    else if(j==4)
        x-=h;
    lineto(x,y);
}

void hilbert(int r,int d,int l,int u,int i,int h,int &x,int &y)
{
    if(i>0)
    {
        i--;
        hilbert(d,r,u,l,i,h,x,y);
        move(r,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(d,h,x,y);
        hilbert(r,d,l,u,i,h,x,y);
        move(l,h,x,y);
        hilbert(u,l,d,r,i,h,x,y);
    }
}

int main()
{
    int n,x1,y1;
    int x0=50,y0=150,x,y,h=10,r=2,d=3,l=4,u=1;

    cout<<"\nGive the value of n: ";
    cin>>n;
    x=x0;y=y0;
    int gm,gd=DETECT;
    initgraph(&gd,&gm,NULL);
    moveto(x,y);
    hilbert(r,d,l,u,n,h,x,y);
    delay(10000);

    closegraph();

    return 0;
}



//koch curve
/*
#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;
class kochCurve
{
public:
    void koch(int it,int x1,int y1,int x5,int y5)
    {
        int x2,y2,x3,y3,x4,y4;
        int dx,dy;
        if (it==0)
        {
        line(x1,y1,x5,y5);
        }
        else
        {
        delay(10);
        dx=(x5-x1)/3;
        dy=(y5-y1)/3;
        x2=x1+dx;
        y2=y1+dy;
        x3=(int)(0.5*(x1+x5)+sqrt(3)*(y1-y5)/6);
        y3=(int)(0.5*(y1+y5)+sqrt(3)*(x5-x1)/6);
        x4=2*dx+x1;
        y4=2*dy+y1;
        koch(it-1,x1,y1,x2,y2);
        koch(it-1,x2,y2,x3,y3);
        koch(it-1,x3,y3,x4,y4);
        koch(it-1,x4,y4,x5,y5);
        }
    }
};
int main()
{
    kochCurve k;
    int it;
    cout<<"Enter Number Of Iterations : "<<endl;
    cin>>it;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    k.koch(it,150,20,20,280);
    k.koch(it,280,280,150,20);
    k.koch(it,20,280,280,280);
    getch();
    closegraph();
    return 0;
}
*/

