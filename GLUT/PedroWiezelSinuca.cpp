#include <GL/glut.h>
#include <stdlib.h>
#include "math.h"
#define PI 3.1415926535897932384626433832795
#include "iostream"
using namespace std;

void bola(float x, float y)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1, 1, 1);
    glTranslated(x, y, 0);
    glPushMatrix();
    int triangulosDesenhar = 40; // number of triangles
    float pi = 3.0f * 3.14159f;
    float rai = 10;

    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= triangulosDesenhar; i++)
    {
        glVertex2f((rai * cos(i *  pi / triangulosDesenhar)-5),
                   (rai * sin(i * pi / triangulosDesenhar)));

    }
    glEnd();
    glPopMatrix();
    return;
}

void buracosMesa()
{
    glColor3d(1, 1, 1);
    glTranslated(10, 5, 0);
    glPushMatrix();
    int triangulosDesenhar = 40; // number of triangles
    float pi = 3.0f * 3.14159f;
    float rai = 6;

    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= triangulosDesenhar; i++)
    {
        glVertex2f((rai * cos(i *  pi / triangulosDesenhar)-5),
                   (rai * sin(i * pi / triangulosDesenhar)));

    }
    glEnd();
    glPopMatrix();

    glTranslated(490, 5, 0);
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= triangulosDesenhar; i++)
    {
        glVertex2f((rai * cos(i *  pi / triangulosDesenhar)-5),
                   (rai * sin(i * pi / triangulosDesenhar)));

    }
    glEnd();
    glPopMatrix();


    glTranslated(1070, 5, 0);
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= triangulosDesenhar; i++)
    {
        glVertex2f((rai * cos(i *  pi / triangulosDesenhar)-5),
                   (rai * sin(i * pi / triangulosDesenhar)));

    }
    glEnd();
    glPopMatrix();
    return;
}

float anguloPRadianos(float anguloInicial)
{
    float b = anguloInicial*(3.141592653589793 / 180);
    return b;
}
float anguloPGraus(float anguloInicial)
{
    float b = (anguloInicial*180) /3.141592653589793;
    return b;
}

void sinuca()
{
    float velocidadeInicial;
    float anguloInicial;
    float tempo = 0;
    float x = 15;
    float y = 15;
    bola(x, y);
    float atrito = 0.05;
    float xLimite = 1070;
    float xLimiteMin = 0;
    float yLimite = 630;
    float yLimiteMin = 0;
    cout << "Insira a velocidade inicial (valor recomendado:20) : " << endl;
    cin >> velocidadeInicial;
    cout << "Insira o angulo de saida: " << endl;
    cin >> anguloInicial;

    anguloInicial = anguloPRadianos(anguloInicial);
    float alcanceX = 1;
    float alcanceY = 1;

    while(true)
    {
        /// bola
        while(true)
        {
            x = velocidadeInicial * cos(anguloInicial);
            y = velocidadeInicial * sin(anguloInicial);
            alcanceX+=x;
            alcanceY+=y;
            velocidadeInicial -= atrito;

            if(velocidadeInicial < 0)
            {
                velocidadeInicial = 0;
                cout << "Insira a velocidade inicial (valor recomendado:20) : " << endl;
                cin >> velocidadeInicial;
                cout << "Insira o angulo de saida: " << endl;
                cin >> anguloInicial;
                anguloInicial = anguloPRadianos(anguloInicial);

            }

            if(alcanceX > xLimite)
            {
                anguloInicial = anguloPGraus(anguloInicial);
                anguloInicial = 180 - anguloInicial;
                anguloInicial = anguloPRadianos(anguloInicial);
            }
            if(alcanceX < xLimiteMin)
            {
                anguloInicial = anguloPGraus(anguloInicial);
                anguloInicial = 180 - anguloInicial;
                anguloInicial = anguloPRadianos(anguloInicial);
            }
            if(alcanceY > yLimite)
            {
                anguloInicial = anguloPGraus(anguloInicial);
                anguloInicial = -anguloInicial;
                anguloInicial = anguloPRadianos(anguloInicial);
            }
            if(alcanceY < yLimiteMin)
            {
                anguloInicial = anguloPGraus(anguloInicial);
                anguloInicial = -anguloInicial;
                anguloInicial = anguloPRadianos(anguloInicial);
            }

            cout << "X: "<<alcanceX<<"" << endl;
            cout << "Y: "<<alcanceY<<"" << endl;
            bola(x, y);
            glutSwapBuffers();
            tempo+=0.01;

        }
    }
}
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,width,0,height,-100,100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    //buracosMesa();
    sinuca();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080, 640);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glClearColor(0,0.5,0, 9.5);
    glutDisplayFunc(display);


    glutMainLoop();

    return EXIT_SUCCESS;
}
