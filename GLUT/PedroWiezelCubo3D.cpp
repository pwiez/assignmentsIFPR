#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include "iostream"
using namespace std;

float ang1 = 0.0;
float ang2 = 0.0;
float ang3 = 0.0;
float ang4 = 0.0;
float ang5 = 0.0;
float ang6 = 0.0;
float ang7 = 0.0;
float ang8 = 0.0;
float ang9 = 0.0;



static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, ((GLfloat)width/ (GLfloat)height), 0.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
//     gluLookAt(0,20,20,0,0,0,1,0,0);
    glColor3f(1,1,0);
    glPushMatrix();
    glutSolidSphere(0.0,100,100);
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glRotated(ang1,0,0,1);
    glTranslated (0.12,0.0,0.0);
    glutSolidSphere(0.01,100,100);
    ang1 +=0.09;
    glPopMatrix();

    glColor3f(0,1,0);
    glPushMatrix();
    glRotated(ang2,0,0,1);
    glTranslated (0.2,0.0,0.0);
    glutSolidSphere(0.02,100,100);
    ang2 +=0.08;
    glPopMatrix();

    glColor3f(0,0,1);
    glPushMatrix();
    glRotated(ang3,0,0,1);
    glTranslated (0.3,0.0,0.0);
    glutSolidSphere(0.025,100,100);
    ang3 +=0.07;

    glColor3f(1,1,1);
    glRotated(ang3,0,0,1);
    glTranslated (0.05,0.0,0.0);
    glutSolidSphere(0.010,100,100);
    glPopMatrix();

    glColor3f(1,0,1);
    glPushMatrix();
    glRotated(ang4,0,0,1);
    glTranslated (0.4,0.0,0.0);
    glutSolidSphere(0.02,100,100);
    ang4 +=0.06;
    glPopMatrix();

    glColor3f(1,1,0);
    glPushMatrix();
    glRotated(ang5,0,0,1);
    glTranslated (0.5,0.0,0.0);
    glutSolidSphere(0.03,100,100);
    ang5 +=0.05;
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glRotated(ang6,0,0,1);
    glTranslated (0.6,0.0,0.0);
    glutSolidSphere(0.025,100,100);
    ang6 +=0.04;
    glPopMatrix();

    glColor3f(0,1,1);
    glPushMatrix();
    glRotated(ang7,0,0,1);
    glTranslated (0.7,0.0,0.0);
    glutSolidSphere(0.025,100,100);
    ang7 +=0.03;
    glPopMatrix();

    glColor3f(0,1,1);
    glPushMatrix();
    glRotated(ang8,0,0,1);
    glTranslated (0.8,0.0,0.0);
    glutSolidSphere(0.02,100,100);
    ang8 +=0.02;
    glPopMatrix();

    glColor3f(1,0,0);
    glPushMatrix();
    glRotated(ang9,0,0,1);
    glTranslated (0.9,0.0,0.0);
    glutSolidSphere(0.01,100,100);
    ang9 +=0.01;

    glPopMatrix();
    glutSwapBuffers();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
