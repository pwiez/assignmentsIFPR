#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

float velocidadeInicial = 0;
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

bool colisaoBolaPreta = false;
bool progresso = false;

float xBolaPreta = 0;
float yBolaPreta = 0;
float atritoPreto = 3;
float xLimiteBolaPreta = 1070;
float xLimiteMinBolaPreta = 0;
float yLimiteBolaPreta = 640;
float yLimiteMinBolaPreta = 0;
float alcanceXBolaPreta = 540;
float alcanceYBolaPreta = 500;

int posMouseX1, posMouseY1 = 0;
int posMouseX2, posMouseY2 = 0;
bool flag = 0;
bool esquerda = 0;
bool outraVelocidade = 0;

bool tacoPode = 1;
float a = 0;
int cliques = 0;

bool tacoAtirando = 0;

bool direitoPressionado = 0;
bool esquerdoPressionado = 1;

float xMouse, yMouse = 0;

float distanciaTaco = 2.5;
bool aumentadiminuidistancia = 0;

void bola()
{
    int triangulosDesenhar = 50; // number of triangles
    float pi = 3.0f * 3.14159f;
    float rai = 10;

    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= triangulosDesenhar; i++)
    {
        glColor3d(1, 1, 1);
        glVertex2f((rai * cos(i *  pi / triangulosDesenhar)),
                   (rai * sin(i * pi / triangulosDesenhar)));

    }
    glEnd();
    return;
}

void bolaPreta()
{
    int triangulosDesenhar = 250; // number of triangles
    float pi = 3.0f * 3.14159f;
    float rai = 10;

    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= triangulosDesenhar; i++)
    {
        glColor3d(0, 0 ,0);
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


void taco()
{
    glColor3d(0.75, 0.5, 0.1);
    glLineWidth(5);
    glBegin(GL_LINES);

    glVertex2d(0, 0);
    glVertex2d(250, 0);


    glEnd();
    return;
}

void mouseControle( int botao, int estado, int x, int y )
{
    if ( estado == GLUT_DOWN)
    {
        switch ( botao )
        {
        case GLUT_RIGHT_BUTTON:
            direitoPressionado = 1;
            cliques++;
        case GLUT_LEFT_BUTTON:
            esquerdoPressionado = 1;
            cliques++;
            if(cliques == 3)
            {
                tacoPode == 0;
                tacoAtirando = 1;
            }

        default:
            break;
        }
    }
}

void forcaTacada(int x, int y)
{
    glPushMatrix();
    glRotated(a, 0, 0, 1);
    glTranslated(alcanceX, alcanceY+20, 0);
    taco();
    glPopMatrix();
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

    if(tacoPode == 1)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3d(1,1,1);
        glPushMatrix();
//        if(tacoAtirando == 1)
//        {
//            anguloInicial = a+180;
//            anguloInicial = anguloPRadianos(anguloInicial);
//            tacoPode = 0;
//            velocidadeInicial = 1550;
//        }
        glTranslated(alcanceXBolaPreta, alcanceYBolaPreta, 0);
        bolaPreta();
        glPopMatrix();
        glPushMatrix();
        glTranslated(alcanceX, alcanceY, 0);
        bola();
        glPopMatrix();
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

        if(direitoPressionado ==0)
        {
            a+=1;
            glPushMatrix();
            glTranslated(alcanceX, alcanceY, 0);
            glRotated(a, 0, 0, 1);
            //glTranslated(2, 2, 0);
            taco();
            glPopMatrix();
            if(a > 360)
            {
                a = 0.1;
            }
            glutSwapBuffers();
            glutPostRedisplay();
        }
        if(direitoPressionado == 1 )
        {

            a+=0.001;
            if(aumentadiminuidistancia == 0)
            {
                distanciaTaco += 0.4;
                velocidadeInicial += 20;
            }
            if(aumentadiminuidistancia == 1)
            {
                distanciaTaco -= 0.4;
                velocidadeInicial -= 20;
            }
            glPushMatrix();
            glTranslated(alcanceX, alcanceY, 0);
            glRotated(a, 0, 0, 1);
            glTranslated(distanciaTaco, 2, 0);
            taco();
            glPopMatrix();
            if(a > 360)
            {
                a = 0.1;
            }
            if(distanciaTaco >= 50 || distanciaTaco <= 2)
            {
                aumentadiminuidistancia = !aumentadiminuidistancia;
            }
            glutSwapBuffers();
            glutPostRedisplay();

        }
    }


    if(tacoAtirando == 1)
    {
        anguloInicial = a+180;
        anguloInicial = anguloPRadianos(anguloInicial);
        tacoPode = 0;
        tacoAtirando = 0;
        distanciaTaco = 2.1;
        aumentadiminuidistancia = 0;
    }
    if(tacoPode == 0 && tacoAtirando == 0)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3d(1,1,1);
        glPushMatrix();
        glTranslated(alcanceXBolaPreta, alcanceYBolaPreta, 0);
        bolaPreta();
        glPopMatrix();
        glPushMatrix();
        glTranslated(alcanceX, alcanceY, 0);
        bola();
        glPopMatrix();

        if((alcanceX<= 60 && alcanceY>= 610) || ((alcanceX<= 570 && alcanceX>= 510) && alcanceY>= 610) || (alcanceX>= 1030 && alcanceY>= 610) ||
                (alcanceX<= 60 && alcanceY<=50) || ((alcanceX<= 570 && alcanceX>= 510) && alcanceY<= 50) || (alcanceX>= 1030 && alcanceY<= 50))
        {
            alcanceX= 540;
            alcanceY= 320;
            tacoAtirando = 0;
            tacoPode = 1;
            esquerdoPressionado = 0;
            direitoPressionado = 0;
            cliques =  0;
            distanciaTaco = 2.1;
            Sleep(2000);
            velocidadeInicial = 0;
        }
        if((alcanceXBolaPreta<= 60 && alcanceYBolaPreta>= 610) || ((alcanceXBolaPreta<= 570 && alcanceXBolaPreta>= 510) && alcanceYBolaPreta>= 610) || (alcanceXBolaPreta>= 1030 && alcanceYBolaPreta>= 610) ||
                (alcanceXBolaPreta<= 60 && alcanceYBolaPreta<=50) || ((alcanceXBolaPreta<= 570 && alcanceXBolaPreta>= 510) && alcanceYBolaPreta<= 50) || (alcanceXBolaPreta>= 1030 && alcanceYBolaPreta<= 50))
        {
            vezes++;
            cout << "Vezes encaçapadas: " << vezes << "" << endl;
            alcanceX= 540;
            alcanceY= 320;
            tacoAtirando = 0;
            tacoPode = 1;
            distanciaTaco = 2.1;
            esquerdoPressionado = 0;
            direitoPressionado = 0;
            cliques =  0;
            alcanceXBolaPreta = 540;
            alcanceYBolaPreta = 500;
            Sleep(2000);
            colisaoBolaPreta = 0;
            velocidadeInicial = 0;
        }

        if(alcanceXBolaPreta <= alcanceX + 20 && alcanceXBolaPreta >= alcanceX-20 && alcanceYBolaPreta <= alcanceY + 20&& alcanceYBolaPreta >= alcanceY - 20 )
        {
            colisaoBolaPreta = !colisaoBolaPreta;
        }

        x = velocidadeInicial * cos(anguloInicial);
        y = velocidadeInicial * sin(anguloInicial);

        if(colisaoBolaPreta == false)
        {
            alcanceX+=x/100;
            alcanceY+=y/100;
        }
        else
        {
            alcanceXBolaPreta+=x/100;
            alcanceYBolaPreta+=y/100;
        }
        velocidadeInicial -= atrito;

        if(velocidadeInicial < 0 && velocidadeInicial >= -10)
        {
            velocidadeInicial = 0;
//        colisaoBolaPreta = 0;
//        cout << "Insira a velocidade inicial (valor recomendado: 1000) : " << endl;
//        cin >> velocidadeInicial;
//        cout << "Insira o angulo de saida: " << endl;
//        cin >> anguloInicial;
            anguloInicial = anguloPRadianos(anguloInicial);
            tacoAtirando = 0;
            tacoPode = 1;
            colisaoBolaPreta = 0;
            cliques = 0;
            direitoPressionado = 0;
            esquerdoPressionado = 0;
            distanciaTaco = 2.1;
        }

        if(alcanceX > xLimite || alcanceXBolaPreta > xLimite)
        {
            anguloInicial = anguloPGraus(anguloInicial);
            anguloInicial = 180 - anguloInicial;
            anguloInicial = anguloPRadianos(anguloInicial);
        }
        if(alcanceX < xLimiteMin || alcanceXBolaPreta < xLimiteMin)
        {
            anguloInicial = anguloPGraus(anguloInicial);
            anguloInicial = 180 - anguloInicial;
            anguloInicial = anguloPRadianos(anguloInicial);
        }
        if(alcanceY > yLimite || alcanceYBolaPreta > yLimite)
        {
            anguloInicial = anguloPGraus(anguloInicial);
            anguloInicial = -anguloInicial;
            anguloInicial = anguloPRadianos(anguloInicial);
        }
        if(alcanceY < yLimiteMin || alcanceYBolaPreta < yLimiteMin)
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
        glutPostRedisplay();
    }



}


int main(int argc, char *argv[])
{
    cout << "Para escolher o angulo, aperte o botão direito, e pra medir a força da tacada,"<<endl;
    cout << "Espere o taco estar na posição certa e aperte o botão esquerdo do mouse" << endl;

    glutInit(&argc, argv);
    glutInitWindowSize(1080, 640);
    glutInitWindowPosition(100, 150);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutMouseFunc(mouseControle);
    glutPassiveMotionFunc(forcaTacada);
    glClearColor(0.1,0.3,0.1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutMainLoop();
    return EXIT_SUCCESS;




//    glPushMatrix();
//        taco();
//        glPopMatrix();
}
