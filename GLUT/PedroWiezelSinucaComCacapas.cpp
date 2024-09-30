#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

float velocidadeInicial;
float anguloInicial;
float x = 10;
float y = 10;
float atrito = 3;
float xLimite = 1070;
float xLimiteMin = 0;
float yLimite = 640;
float yLimiteMin = 0;
float alcanceX = 270;
float alcanceY = 320;
int vezes = 0;

void bola()
{
    int triangulosDesenhar = 50; // number of triangles
    float pi = 3.0f * 3.14159f;
    float rai = 10;

    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= triangulosDesenhar; i++)
    {
        glVertex2f((rai * cos(i *  pi / triangulosDesenhar)),
                   (rai * sin(i * pi / triangulosDesenhar)));

    }
    glEnd();
    return;
}

void circulo()
{
    float rai = 30;
    int triangulosDesenhar = 100;
    float piMaior = 2.0 * 3.14159;

    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= triangulosDesenhar; i++)
    {
        glColor3d(0,0,0);
        glVertex2d((rai * cos(i *  piMaior / triangulosDesenhar)),(rai * sin(i * piMaior / triangulosDesenhar)));

    }
    glEnd();

    return;
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

static void display(void)
{

    while(true)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3d(1,1,1);

        glPushMatrix();
        glTranslated(alcanceX, alcanceY, 0);
        bola();
        glPopMatrix();

        if((alcanceX<= 60 && alcanceY>= 610) || ((alcanceX<= 570 && alcanceX>= 510) && alcanceY>= 610) || (alcanceX>= 1030 && alcanceY>= 610) ||
                (alcanceX<= 60 && alcanceY<=50) || ((alcanceX<= 570 && alcanceX>= 510) && alcanceY<= 50) || (alcanceX>= 1030 && alcanceY<= 50))
        {
            vezes++;
            cout << "Vezes encaçapadas: " << vezes << "" << endl;
            alcanceX= 540;
            alcanceY= 320;
            cout << "Insira a velocidade inicial (valor recomendado: 1000) : " << endl;
            cin >> velocidadeInicial;
            cout << "Insira o angulo de saida: " << endl;
            cin >> anguloInicial;
            anguloInicial = anguloPRadianos(anguloInicial);
        }

        x = velocidadeInicial * cos(anguloInicial);
        y = velocidadeInicial * sin(anguloInicial);
        alcanceX+=x /100;
        alcanceY+=y/100;
        velocidadeInicial -= atrito;

        if(velocidadeInicial < 0)
        {
            velocidadeInicial = 0;
            cout << "Insira a velocidade inicial (valor recomendado: 1000) : " << endl;
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

        glPushMatrix();
        glTranslated(540,30,0);
        circulo();
        glPopMatrix();

        glPushMatrix();
        glTranslated(30, 30,0);
        circulo();
        glPopMatrix();

        glPushMatrix();
        glTranslated(1050, 30,0);
        circulo();
        glPopMatrix();

        glPushMatrix();
        glTranslated(30, 620,0);
        circulo();
        glPopMatrix();

        glPushMatrix();
        glTranslated(540, 620,0);
        circulo();
        glPopMatrix();

        glPushMatrix();
        glTranslated(1050, 620,0);
        circulo();
        glPopMatrix();

        glutSwapBuffers();
    }
}

//static void idle(void)
//{
//    glutPostRedisplay();
//}

int main(int argc, char *argv[])
{
    cout << "Insira a velocidade inicial (valor recomendado:1000) : " << endl;
    cin >> velocidadeInicial;
    cout << "Insira o angulo de saida: " << endl;
    cin >> anguloInicial;
    anguloInicial = anguloPRadianos(anguloInicial);

    glutInit(&argc, argv);
    glutInitWindowSize(1080, 640);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
//    glutIdleFunc(idle);

    glClearColor(0.1,0.3,0.1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glutMainLoop();

    return EXIT_SUCCESS;
}
