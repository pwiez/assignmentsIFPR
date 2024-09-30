#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

static void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (45.0, (GLdouble) width/(GLdouble)height, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
static void display(void)
{
    glShadeModel(GL_SMOOTH);

    static float amb[] =  {0.4, 0.4, 0.4, 0.0};
    static float dif[] =  {0, 1.0, 1.0, 0.0};


    float light_diffuse[] = {0.5, 0.5, 0.0, 1.0};
    float light_position[] = {200.0, 200.0, 0.0, 0.0};


    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3d( 0, 0, 0);
    glPushMatrix ();
    glTranslated(0,-1.5,-5);//CHÃO
    glScalef(2.5,0.1,3);
    glutSolidCube(4);
    glPopMatrix();

    glPushMatrix ();
    glTranslated(0.5,-0.35,-15);//CUBO EMBIXO DIREITA
    glScalef(0.5,0.5,0.5);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix ();
    glTranslated(-1,-2,-15);//CUBO EMBAIXO ESQUERDA
    glScalef(0.5,0.5,0.5);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix ();
    glTranslated(0,1.3,-15);//CUBO EM CIMA
    glScalef(0.5,0.5,0.5);
    glutSolidCube(3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Janela Principal");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutMainLoop();
}
