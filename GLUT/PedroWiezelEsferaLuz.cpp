#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>


/// a explicação da borda preta está neste código em comentário :D

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

    GLfloat blue[] = {0, 0, 1, 0.7};
    glMaterialfv(GL_FRONT, GL_SPECULAR, blue);
    GLfloat specularLight[] = { 01, 0.25, 0.75, 1};
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    GLfloat lightPos[] = {1, -1, 0.5, 0.2};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_CULL_FACE);
    glColorMaterial (GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, blue);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix ();
    glColor3d(0.4, 0.4, 0.4);
    glTranslated(0,0,-10);
    glScalef(0.5,0.5,0.5);
    glRotatef(43.0,1.,1.,1.);
    glutSolidSphere(3, 500, 500);
    glPopMatrix();

    ///Os objetos possuem uma sombra preta devido ao fato da luz ser especular, isto é, incidir sobre um ponto específico no objeto.
    /// conforme "avança" pela superfície do objeto esta luz perde intensidade progressivamente, dando lugar a sombra, a borda preta,
    ///enquanto possui intensidade total no local onde incide.

    GLfloat yellow[] = {10, 2, 0, 0.5};
    glMaterialfv(GL_FRONT, GL_SPECULAR, yellow);
    GLfloat specularLightY[] = {1, 0.5, 0, 1};
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLightY);
    GLfloat lightPosY[] = {1, -1, 0.5, 0.1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosY);

    glColorMaterial (GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, yellow);

    glPushMatrix ();
    glColor3d(0, 0, 0.6);
    glTranslated(-4,0,-10);
    glScalef(0.5,0.5,0.5);
    glRotatef(43.0,1.,1.,1.);
    glutSolidSphere(1.6, 500, 500);
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
    glClearColor(0.4, 0.6, 0.8, 1.0);
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutMainLoop();
}
