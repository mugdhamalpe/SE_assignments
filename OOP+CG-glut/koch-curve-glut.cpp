/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
//#include <GL/glut.h>
#endif

#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <windows.h>


//#include<math.h>
using namespace std;
float x1 = 1, x2= 600 , y_one= 1, y2 = 600, n;



void koch(float x1, float y_one, float x2, float y2, float n)
{
	float ang = 60;
	ang = ang * 3.14 / 180; //converting deg to radians
	float x3 = (2 * x1 + x2) / 3; //using section formula
	float y3 = (2 * y_one + y2) / 3;
	float x4 = (x1 + 2 * x2) / 3;
	float y4 = (y_one + 2 * y2) / 3;
	//cos60=0.5 and sin60=0.8660
	float x = x3 + (x4 - x3) * 0.5 + (y4 - y3) * 0.8660;
	float y = y3 - (x4 - x3) * 0.8660 + (y4 - y3) * 0.5;
	if (n > 0)
	{
		koch(x1, y_one, x3, y3, n - 1);
		koch(x3, y3, x, y, n - 1);
		koch(x, y, x4, y4, n - 1);
		koch(x4, y4, x2, y2, n - 1);
	}
	else
	{
		glBegin(GL_LINE_STRIP);
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glColor3f(0.0, 1.0, 1.0);
		glVertex2f(x1, y_one); //pixel 3->x,y,z and f->float
		glColor3f(0.0, 1.0, 1.0);
		glVertex2f(x3, y3);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(x, y);
		glColor3f(1.0, 0.0, 1.0);
		glVertex2f(x4, y4);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(x2, y2);
		glEnd();

	}
}
void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //r,g,b,k
	glColor3f(0.0, 0.0, 0.0);//black selected r=0,g=0,b=0
	gluOrtho2D(0.0, 640.0, 480.0, 0.0);//display my screen orthographically on my screen
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//color buffer which is using rgb color model and start entirely new
	koch(x1, y_one, x2, y2, n);
	glFlush(); //frame buffer free for next calc
}
int main(int argv, char** argc)
{
    //cout<"Enter no of iterations: "<<endl;
    cin>>n;

	glutInit(&argv, argc);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Fractals using koch curve");
	Init(); //user defines
	//basic program req for koch curve
	glutDisplayFunc(display); //register callback handle for window re-paint event
	//inside user defined func -> diplay ---- add all callbacks
	glutMainLoop(); //infinte processing loop --- to repeat entire procedure repeadetly

	return 0;
}
