#include "biblaureano.h"

void mostraInfoePreparaTerreno()
{
    mudaCor(WHITE);
    gotoXY(1, 10);
    cout << "       Bem vindo ao jogo do Labirinto!" << endl;
    cout << "\n   Para jogar, desenhe o labirinto. 'Q' liga o desenhador, e 'W' desliga." << endl;
    cout << "   Quando estiver pronto, aperte 'R', ";
    cout << "e divirta-se vendo um robozinho" <<endl;
    cout << "   preenchendo os espaços do labirinto!" <<endl;
    limpaEfeito();
    espera(3500);
    limparTela();
    desligaCursor(1);
}

void fechaParede(Imagem parede, int matrizDaTela[79][24])
{
    int x = 0;
    int y = 0;
    for(x = 1; x<79; x++)
    {
        mudaCor255(33);
        parede.imprime(x, 1);
        matrizDaTela[x][1] = 1;
    }
    for(y = 1; y<24; y++)
    {
        mudaCor255(33);
        parede.imprime(1, y);
        matrizDaTela[1][y] = 1;
    }
    for(y = 24; y>1; y--)
    {
        mudaCor255(33);
        parede.imprime(78, y);
        matrizDaTela[78][y] = 1;
    }
    for(x = 1; x<79; x++)
    {
        mudaCor255(33);
        parede.imprime(x, 24);
        matrizDaTela[x][24] = 1;
    }

}


void game(int matrizDaTela[79][24], Imagem trilha, Imagem parede)
{

    class ROBOTO
    {
    private:
    protected:
    public:
        int x, y;
        vector<int> coordX;
        vector<int> coordY;
    };

    int x = 0;
    int y = 0;

    Imagem roboto("R", 2, 2);
    roboto.setLimites(1,1,79,24);

    gotoXY(1, 1);
    int xInicialRoboto = readInt("X inicial (max 78): ");
    gotoXY(35, 1);
    int yInicialRoboto = readInt("Y inicial (max 23): ");

    roboto.setX(xInicialRoboto);
    roboto.setY(yInicialRoboto);


    vector<int> coordX;
    vector<int> coordY;

    fechaParede(parede, matrizDaTela);

    while(true)
    {
        while(matrizDaTela[roboto.getX()][roboto.getY()-1] == 0)
        {
            roboto.limpa();
            espera(20);
            roboto.decrementaY();
            roboto.imprime();
            mudaCor255(33);
            trilha.imprime(roboto.getX(),roboto.getY()+1);
            matrizDaTela[roboto.getX()][roboto.getY()+1] = 2;
            coordX.push_back(roboto.getX());
            coordY.push_back(roboto.getY());
        }
        while(matrizDaTela[roboto.getX()-1][roboto.getY()] == 0)
        {
            roboto.limpa();
            espera(20);
            roboto.decrementaX();
            roboto.imprime();
            mudaCor255(33);
            trilha.imprime(roboto.getX()+1,roboto.getY());
            matrizDaTela[roboto.getX()+1][roboto.getY()] = 2;
            coordX.push_back(roboto.getX());
            coordY.push_back(roboto.getY());
        }
        while(matrizDaTela[roboto.getX()+1][roboto.getY()] == 0)
        {
            roboto.limpa();
            espera(20);
            roboto.incrementaX();
            roboto.imprime();
            mudaCor255(33);
            trilha.imprime(roboto.getX()-1,roboto.getY());
            matrizDaTela[roboto.getX()-1][roboto.getY()] = 2;
            coordX.push_back(roboto.getX());
            coordY.push_back(roboto.getY());
        }
        while(matrizDaTela[roboto.getX()][roboto.getY()+1] == 0)
        {
            roboto.limpa();
            espera(20);
            roboto.incrementaY();
            roboto.imprime();
            mudaCor255(33);
            trilha.imprime(roboto.getX(),roboto.getY()-1);
            matrizDaTela[roboto.getX()][roboto.getY()-1] = 2;
            coordX.push_back(roboto.getX());
            coordY.push_back(roboto.getY());
        }

        if(matrizDaTela[roboto.getX()][roboto.getY()+1] != 0 &&
                matrizDaTela[roboto.getX()+1][roboto.getY()] != 0 &&
                matrizDaTela[roboto.getX()][roboto.getY()-1] != 0 &&
                matrizDaTela[roboto.getX()-1][roboto.getY()] != 0)
        {
            roboto.limpa();
            matrizDaTela[coordX.back()][coordY.back()] = 0;
            mudaCor255(33);
            trilha.limpa();
            trilha.imprime();
            coordX.pop_back();
            coordY.pop_back();
        }
    }
}


int main()
{
    mostraInfoePreparaTerreno();

    int matrizDaTela[79][24];

    class ROBOTO
    {
    private:
    protected:
    public:
        int x, y;
        vector<int> coordX;
        vector<int> coordY;
    };

    for(int a=0; a<24; a++)
    {
        for(int b=0; b<79; b++)
        {
            matrizDaTela[b][a] = 0;
        }
    }

    bool podeImprimir = false;

    Imagem drawer("@", 37, 12);
    drawer.setLimites(1,1,79, 24);
    drawer.imprime();

    Imagem parede
    ("#");
    parede.setLimites(1, 1,79,24);

    Imagem trilha(",");
    trilha.setLimites(1,1,79,24);

    while(true)
    {

        if(kbhit())
        {
            char tecla = getch();

            if (tecla == 'Q' || tecla == 'q')
            {
                podeImprimir = true;
            }
            if (tecla == 'w' || tecla == 'W')
            {
                podeImprimir = false;
            }

            if (tecla == K_LEFT)
            {
                drawer.limpa();
                drawer.decrementaX();
                drawer.imprime();

                if(podeImprimir == true)
                {
                    mudaCor255(33);
                    parede.imprime(drawer.getX()+1,drawer.getY());
                    matrizDaTela[drawer.getX()+1][drawer.getY()] = 1;

                }
            }
            if (tecla == K_RIGHT )
            {
                drawer.limpa();
                drawer.incrementaX();
                drawer.imprime();
                if(podeImprimir == true)
                {
                    mudaCor255(33);
                    parede.imprime(drawer.getX()-1,drawer.getY());
                    matrizDaTela[drawer.getX()-1][drawer.getY()] = 1;


                }
            }
            if (tecla == K_UP)
            {
                drawer.limpa();
                drawer.decrementaY();
                drawer.imprime();

                if(podeImprimir == true)
                {
                    mudaCor255(33);
                    parede.imprime(drawer.getX(),drawer.getY()+1);
                    matrizDaTela[drawer.getX()][drawer.getY()+1] = 1;

                }
            }
            if (tecla == K_DOWN)
            {
                drawer.limpa();
                drawer.incrementaY();
                drawer.imprime();
                if(podeImprimir == true)
                {
                    mudaCor255(33);
                    parede.imprime(drawer.getX(),drawer.getY()-1);
                    matrizDaTela[drawer.getX()][drawer.getY()-1] = 1;

                }
            }
            if (tecla == 'r' || tecla == 'R')
            {
                drawer.limpa();
                game(matrizDaTela, trilha, parede);
            }
        }
    }
    return 0;
}


