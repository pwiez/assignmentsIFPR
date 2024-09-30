
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

static int slices = 16;
static int stacks = 16;
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
    glFrustum(-ar-6, ar+6, -6.0, 6.0, 6.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
double t;
double a;
static void display(void)
{

     t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
     a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,1,0);
    glPushMatrix();
    glTranslated(0,0,-7);
    glutSolidSphere(1,slices+1000,stacks+1000);
    glPopMatrix();

    if(a > 1)
    {
        glColor3d(0.7, 0.7, 0.7);
        glPushMatrix();
        //glRotated(30,1,0,0);
        glRotated(ang1,0,0,1);
        glTranslated(0,-2.5,-12);
        glutWireSphere(0.07,slices,stacks); //mercurio
        ang1+=1.5;
        glPopMatrix();
        t = 0;

        glColor3d(0.8, 0.2, 0.1);
        glPushMatrix();
        //glRotated(30,1,0,0);
        glRotated(ang2,0,0,1); //venus
        glTranslated(-1,-3.5,-14);
        glutWireSphere(0.11,slices,stacks);
        ang2+=1.25;
        glPopMatrix();

        glColor3d(0, 0, 1);
        glPushMatrix();
        //glRotated(30,1,0,0);
        glRotated(ang3,0,0,1);
        glTranslated(0,-4.5,-12); //terra
        glutWireSphere(0.14,slices,stacks);
        ang3+=1;
        glPopMatrix();

        glColor3d(1, 0, 0);
        glPushMatrix();
        //glRotated(30,1,0,0);
        glRotated(ang4,0,0,1); //marte
        glTranslated(0,-5.5,-12);
        glutWireSphere(0.10,slices,stacks);
        ang4+=0.80;
        glPopMatrix();
        t = 0;

        glColor3d(0.6, 0.3, 0);
        glPushMatrix();
        //glRotated(30,1,0,0);
        glRotated(ang5,0,0,1);
        glTranslated(0,-6.5,-12); //jupiter
        glutWireSphere(0.25,slices,stacks);
        ang5+=0.60;
        glPopMatrix();
        t = 0;

        glPushMatrix();
        //glRotated(30,1,0,0); //saturno
        glRotated(ang6,0,0,1);
        glTranslated(0,-7.5,-12);
        glutWireSphere(0.19,slices,stacks);
        ang6+=0.40;
        glPopMatrix();
        t = 0;

        glColor3d(0.5,0.5, 1);
        glPushMatrix();
        //glRotated(30,1,0,0);
        glRotated(ang7,0,0,1); //urano
        glTranslated(0,-8.5,-12);
        glutWireSphere(0.17,slices,stacks);
        ang7+=0.30;
        glPopMatrix();
        t = 0;

        glColor3d(0, 0, 1);
        glPushMatrix();
        //glRotated(30,1,0,0); //netuno
        glRotated(ang8,0,0,1);
        glTranslated(0,-9.5,-12);
        glutWireSphere(0.17,slices,stacks);
        ang8+=0.20;
        glPopMatrix();
        t = 0;

        glColor3d(1, 1, 1);
        glPushMatrix();
        //glRotated(30,1,0,0); //plutao
        glRotated(ang9,0,0,1);
        glTranslated(0,-10.5,-12);
        glutWireSphere(0.04,slices,stacks);
        ang9+=0.15;
        glPopMatrix();
        t = 0;
        a = 0;
    }

    glutSwapBuffers();
    glutPostRedisplay();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;

    case '+':
        slices++;
        stacks++;
        break;

    case '-':
        if (slices>3 && stacks>3)
        {
            slices--;
            stacks--;
        }
        break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 640);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0, 0, 0, 0);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
