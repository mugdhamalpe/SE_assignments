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


using namespace std;


float SunX = -0.8f;
float SunY = -0.3f;
float SunZ = -1.2f;

float SunR = 100.0;
float SunG = 30.6;
float SunB = 1.8;

float SkyR = 1.00;
float SkyG = 0.721;
float SkyB = 0.278;

//1, 0.721, 0.278
float MountainR = 1.0;
float MountainG = 0.5;
float MountainB = 0.7;

//0.964, 0.701, 0.172

//0.172, 0.788, 0.964

static int flag = 1;

void draw_sun(void) {
	glColor3f(SunR, SunG, SunB);
    glTranslatef(SunX,SunY,0);
	glutSolidSphere(0.08, 40, 40);//radius , latitudinal divisions, longitudinal divisions

}

void draw_mountains() {
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);

    glVertex3f(-1, -1, -1.0);

    glVertex3f(-0.5, -0.1, -1.0);

    glVertex3f(-0.2, -1.0, -1.0);

    glVertex3f(0.5, 0.0, -1.0);

    glVertex3f(0.6, -0.2, -1.0);

    glVertex3f(1, -1, -1.0);

    glEnd();
}

void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0); //Enable light #0
    glEnable(GL_LIGHT1); //Enable light #1
    glEnable(GL_NORMALIZE); //Automatically normalize normals
    //glShadeModel(GL_SMOOTH); //Enable smooth shading
}


void draw_scene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(SkyR, SkyG, SkyB, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLfloat ambientColor[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    GLfloat lightColor1[] = { 0.5f, 0.2f, 0.2f, 1.0f };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);

    GLfloat lightPos1[] = { SunX, SunY, 1.0, 0.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

    glPushMatrix();
    draw_sun();
    glPopMatrix();

   glPushMatrix();
   draw_mountains();
    glPopMatrix();
    glutSwapBuffers();

}
void handleResize(int w, int h) {
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,                  //The camera angle
        (double)w / (double)h, //The width-to-height ratio
        1.0,                   //The near z clipping coordinate
        200.0);                //The far z clipping coordinate
}


void Update(int value) {
    cout << SunR << "-" << SunG << "-" << SunB << "-" << endl;
    if (SunX > 0.9f)
    {
        SunX = -0.8f;
        SunY = -0.3f;
        flag = 1;

        SunR = 100.0;
        SunG = 30.6;
        SunB = 1.8;

        SkyR = 1.00;
        SkyG = 0.721;
        SkyB = 0.278;
    }

    if (flag)
    {
        SunX += 0.001f;
        SunY += 0.0007f;
        SunR -= 0.001;
        SunG += 0.002;
        SunB += 0.005;
        SkyR -= 0.001;
        SkyB += 0.001;

        if (SunX > 0.01)
        {
            flag = 0;

        }
    }
    if (!flag)
    {
        SunX += 0.001f;
        SunY -= 0.0007f;
        SunR -= 0.01;
        SunB -= 0.008;
        SunG -= 0.01;
        SkyR += 0.001;
        SkyB -= 0.001;

        if (SunX < -0.3)
        {
            flag = 1;

        }
    }

    glutPostRedisplay();


    glutTimerFunc(25, Update, 0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(800, 800);

    glutCreateWindow("Sun");

    initRendering();

    glutDisplayFunc(draw_scene);
    //glutReshapeFunc(handleResize);
     glutTimerFunc(25, Update, 0);

    glutMainLoop();
    return(0);



}
