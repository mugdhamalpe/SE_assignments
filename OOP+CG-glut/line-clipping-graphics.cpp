#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <stdlib.h>

//program for line clipping
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int rcode_begin[4]={0,0,0,0},rcode_end[4]={0,0,0,0},region_code[4];
    int W_xmax,W_ymax,W_xmin,W_ymin,flag=0;
    float slope;
    int x,y,x1,y1,i, xc,yc;
    int gr=DETECT,gm;
    initgraph(&gr,&gm,"");
    printf("\n--------- Cohen Sutherland Line Clipping algorithm ---------");
    printf("\n Now, enter XMin, YMin = ");

    scanf("%d %d",&W_xmin,&W_ymin);
    printf("\n First enter XMax, YMax = ");
    scanf("%d %d",&W_xmax,&W_ymax);
    printf("\n Please enter initial point x and y= ");
    scanf("%d %d",&x,&y);
    printf("\n Now, enter final point x1 and y1= ");
    scanf("%d %d",&x1,&y1);
    cleardevice();
    rectangle(W_xmin,W_ymin,W_xmax,W_ymax);
    line(x,y,x1,y1);
    line(0,0,600,0);
    line(0,0,0,600);
    if(y>W_ymax)  {
        rcode_begin[0]=1;     // Top
        flag=1 ;
    }
    if(y<W_ymin) {
        rcode_begin[1]=1;           // Bottom
        flag=1;
    }
    if(x>W_xmax)  {
        rcode_begin[2]=1;           // Right
        flag=1;
    }
    if(x<W_xmin)   {
        rcode_begin[3]=1;           //Left
        flag=1;
    }

    //end point of Line
    if(y1>W_ymax){
        rcode_end[0]=1;           // Top
        flag=1;
    }
    if(y1<W_ymin) {
        rcode_end[1]=1;           // Bottom
        flag=1;
    }
    if(x1>W_xmax){
        rcode_end[2]=1;           // Right
        flag=1;
    }
    if(x1<W_xmin){
        rcode_end[3]=1;           //Left
        flag=1;
     }
    if(flag==0)
    {
        printf("No need of clipping as it is already present in the polygon");
    }
    flag=1;
    for(i=0;i<4;i++){
        region_code[i]= rcode_begin[i] && rcode_end[i] ;
        if(region_code[i]==1)
            flag=0;
        }
        if(flag==0)
        {
            printf("\n Line is completely outside the polygon");
        }
        else{
            slope=(float)(y1-y)/(x1-x);
            if(rcode_begin[2]==0 && rcode_begin[3]==1)   //left
            {
            y=y+(float) (W_xmin-x)*slope ;
            x=W_xmin;

            }
            if(rcode_begin[2]==1 && rcode_begin[3]==0)       // right
            {
            y=y+(float) (W_xmax-x)*slope ;
            x=W_xmax;

            }
            if(rcode_begin[0]==1 && rcode_begin[1]==0)      // top
            {
            x=x+(float) (W_ymax-y)/slope ;
            y=W_ymax;

            }
            if(rcode_begin[0]==0 && rcode_begin[1]==1)     // bottom
            {
            x=x+(float) (W_ymin-y)/slope ;
            y=W_ymin;

            }
            // end points
            if(rcode_end[2]==0 && rcode_end[3]==1)   //left
            {
            y1=y1+(float) (W_xmin-x1)*slope ;
            x1=W_xmin;

            }
            if(rcode_end[2]==1 && rcode_end[3]==0)       // right
            {
            y1=y1+(float) (W_xmax-x1)*slope ;
            x1=W_xmax;

            }
            if(rcode_end[0]==1 && rcode_end[1]==0)      // top
            {
            x1=x1+(float) (W_ymax-y1)/slope ;
            y1=W_ymax;

            }
            if(rcode_end[0]==0 && rcode_end[1]==1)     // bottom
            {
            x1=x1+(float) (W_ymin-y1)/slope ;
            y1=W_ymin;
            }
    }
    delay(5000);
    clearviewport();
    rectangle(W_xmin,W_ymin,W_xmax,W_ymax);
    line(0,0,600,0);
    line(0,0,0,600);
    setcolor(YELLOW);
    line(x,y,x1,y1);
    getch();
    closegraph();
}

/*
// C++ program to implement Cohen Sutherland algorithm for line clipping.
#include <iostream>
#include<stdio.h>
#include<graphics.h>

using namespace std;

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

//Defining x_max, y_max and x_min, y_min for clipping rectangle.
//Since diagonal points are enough to define a rectangle
const int x_max = 180;
const int y_max = 180;
const int x_min = 40;
const int y_min = 40;

// Draw line
void draw(float x1, float y1, float x2, float y2)
{
    float h = (float)getwindowheight();
    float w = (float)getwindowwidth();
    line(x1+w/2, (h/2)-y1,x2+w/2, (h/2)-y2);
}


// Function to compute region code for a point(x, y)
int computeCode(double x, double y)
{
    // initialized as being inside
    int code = INSIDE;

    if (x < x_min)       // left of rectangle
        code |= LEFT;
    else if (x > x_max)  // right of rectangle
        code |= RIGHT;
    if (y < y_min)       // below the rectangle
        code |= BOTTOM;
    else if (y > y_max)  // above the rectangle
        code |= TOP;

    return code;
}

// Clear Screen
void myCleardevice()
{
    float h = (float)getwindowheight();
    float w = (float)getwindowwidth();
    cleardevice();   //clear the screen
    line(0,h/2, w, h/2);
    line(w/2,0,w/2,h);
}

// Draw Boundary
void drawBoundary()
{
    draw(x_min,y_min, x_max, y_min);
    draw(x_min, y_min, x_min, y_max);
    draw(x_max, y_min, x_max, y_max);
    draw(x_min,y_max, x_max, y_max);
}


// Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)

void cohenSutherlandClip(double x1, double y1,
                         double x2, double y2)
{
    // Compute region codes for P1, P2
    int code1 = computeCode(x1, y1);

    int code2 = computeCode(x2, y2);


    // Initialize line as outside the rectangular window
    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle, in same region
            break;
        }
        else
        {
            // Some segment of line lies within the rectangle
            int code_out;
            double x, y;

            // At least one endpoint is outside the rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point; using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Now intersection point x,y is found We replace point outside rectangle by intersection point
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        cout <<"Line accepted from " << x1 << ", "
             << y1 << " to "<< x2 << ", " << y2 << endl;
        // display the rectangle
        // also accepted (portion of) lines

        myCleardevice();
        drawBoundary();
        draw(x1,y1,x2,y2);

    }
    else
        cout << "Line rejected" << endl;
}



int main()
{
    int gd = DETECT, gm;

    // Initialize graphics function instead if turbo, use NULL or ""
    initgraph (&gd, &gm, "");

    float h = (float)getwindowheight();
    float w = (float)getwindowwidth();

    // Axis
    line(0,h/2, w, h/2);
    line(w/2,0,w/2,h);

    drawBoundary();
    int x1=0,y1=0,x2=200,y2=220;
    draw(x1,y1,x2,y2);

    cout<<"Press 0 to clip!\n";
    int ans;
    scanf("%d", &ans);

    if(ans == 0)
        cohenSutherlandClip(x1,y1,x2,y2);

    getch();
    return 0;
}
*/
