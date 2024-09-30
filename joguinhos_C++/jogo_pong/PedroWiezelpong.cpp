#include "biblaureano.h"

int main()
{
    mudaTamanhoTerminal(81, 26);
    noecho(true);
    desligaCursor(true);

    bool logo = 1;
    bool jogo = 0;

    Imagem logotipoPongoso(retornaConteudoArquivo("Pedro_Martins_pong_001.txt"), 7, 3);
    gotoXY(10, 20);
    cout << "Jogador 1: E e R";
    cout << "\n\t  Jogador 2: <- e ->";
    logotipoPongoso.imprime();
    espera(3500);                      //LOGOTIPO INICIAL
    logotipoPongoso.limpa();
    gotoXY(10, 20);
    cout << "                 ";
    cout << "\n\t                              ";

    logo = 0;
    jogo = 1;


    string barraDir = retornaConteudoArquivo("Pedro_Martins_pong_004.txt");
    string barraEsq = retornaConteudoArquivo("Pedro_Martins_pong_005.txt");
    string borda = retornaConteudoArquivo("Pedro_Martins_pong_002.txt");


    Imagem barraDireita(barraDir, 77, 8);
    Imagem barraEsquerda(barraEsq, 3, 8);
    Imagem bola("o", 39, 11);
    Imagem borda1(borda, 1, 22);
    Imagem borda2(borda, 1, 2);
    barraDireita.setLimites(1,3,1,15);
    barraEsquerda.setLimites(1,3,1,15);
    bola.setLimites(1, 2, 79, 22);

    barraDireita.imprime();
    barraEsquerda.imprime();
    borda2.imprime();
    borda1.imprime();

    gotoXY(1, 23);
    mudaCor(YELLOW);
    cout << "Jogador 1";
    limpaEfeito();

    gotoXY(71, 23);
    mudaCor(RED);
    cout << "Jogador 2";
    limpaEfeito();

    gotoXY(1, 1);
    mudaCor(YELLOW);
    cout << "E para cima, R para baixo";

    gotoXY(53, 1);
    mudaCor(RED);
    cout << "<- para cima, -> para baixo";

    gotoXY(32, 1);
    mudaCor(GREEN);
    cout << "   C++ PONG";  //a cada mudança significativa no código, vai somando em um. Deve terminar lá pelo 4.2.3 (previsão de 09/06/14)
    limpaEfeito();
    int quantidadeEmYNoMovimentoInicial = 0; // é o que define o movimento de facto (0 quando for para direita e esquerda)
    int quantidadeEmXNoMovimentoInicial = 1; //ele sempre se movimenta uma linha

    char direcaoMovimento;
    int direcao = randomico(1, 6);
    int angulo = 0;

    int pontoJogadorUm = 0;
    int pontoJogadorDois = 0;

    gotoXY(38, 23);
    cout << ""<<pontoJogadorUm<<"X"<<pontoJogadorDois<<"";


    TEMPO tempoDeJogo = tempoInicio();

    while (jogo == 1)
    {
        if(direcao == 1)
        {
            if(tempoPassado(tempoDeJogo) > 3)
            {

                quantidadeEmYNoMovimentoInicial = 0;
                bola.limpa();
                bola.incrementaX();
                bola.imprime();
                direcaoMovimento = 'd'; //direita
                tempoDeJogo = tempoInicio();
            }

        }
        else if(direcao == 2)
        {
            if(tempoPassado(tempoDeJogo) > 3)
            {

                quantidadeEmYNoMovimentoInicial = 0;
                quantidadeEmXNoMovimentoInicial = 1;
                bola.limpa();
                bola.decrementaX();
                bola.imprime();
                direcaoMovimento = 'e'; //de esquerda
                tempoDeJogo = tempoInicio();
            }


        }
        else if(direcao == 3)
        {
            if(tempoPassado(tempoDeJogo) > 3)
            {
                quantidadeEmYNoMovimentoInicial = 1;
                quantidadeEmXNoMovimentoInicial = 1;
                bola.limpa();
                bola.setY(bola.getY() - quantidadeEmYNoMovimentoInicial);
                bola.setX(bola.getX() - quantidadeEmXNoMovimentoInicial);
                bola.imprime();
                direcaoMovimento = 'e'; //de esquerda
                tempoDeJogo = tempoInicio();
            }

        }
        else if(direcao == 4)
        {
            if(tempoPassado(tempoDeJogo) > 3)
            {
                quantidadeEmYNoMovimentoInicial = 1;
                quantidadeEmXNoMovimentoInicial = 1;
                bola.limpa();
                bola.setY(bola.getY() - quantidadeEmYNoMovimentoInicial);
                bola.setX(bola.getX() + quantidadeEmXNoMovimentoInicial);
                bola.imprime();
                direcaoMovimento = 'd'; //de direita
                tempoDeJogo = tempoInicio();
            }

        }
        else if(direcao == 5)
        {
            if(tempoPassado(tempoDeJogo) > 3)
            {
                quantidadeEmXNoMovimentoInicial = -1;
                quantidadeEmYNoMovimentoInicial = 1;
                bola.limpa();
                bola.setY(bola.getY() + quantidadeEmYNoMovimentoInicial);
                bola.setX(bola.getX() + quantidadeEmXNoMovimentoInicial);
                bola.imprime();
                direcaoMovimento = 'e';
                tempoDeJogo = tempoInicio();
            }
        }
        else if(direcao == 6)
        {
            if(tempoPassado(tempoDeJogo) > 3)
            {
                quantidadeEmXNoMovimentoInicial = 1;
                quantidadeEmYNoMovimentoInicial = 1;
                bola.limpa();
                bola.setX(bola.getX() + quantidadeEmXNoMovimentoInicial);
                bola.setY(bola.getY() + quantidadeEmYNoMovimentoInicial);
                bola.imprime();
                direcaoMovimento = 'd';
                tempoDeJogo = tempoInicio();
            }
        }


        if (kbhit())
        {
            int tecla = getch();

            if (tecla == K_RIGHT)
            {
                barraDireita.limpa();
                barraDireita.incrementaY();
                barraDireita.imprime();
            }
            if (tecla == K_LEFT)
            {
                barraDireita.limpa();
                barraDireita.decrementaY();
                barraDireita.imprime();
            }
            if (tecla == 'r' || tecla == 'R')
            {
                barraEsquerda.limpa();
                barraEsquerda.incrementaY();
                barraEsquerda.imprime();
            }
            if (tecla == 'e' || tecla == 'E')
            {
                barraEsquerda.limpa();
                barraEsquerda.decrementaY();
                barraEsquerda.imprime();
            }
        }



        if(bola.getX() > 77 || bola.getX() < 3)
        {
            if(bola.getX() < 1)                //ponto do jogador 2
            {
                bola.limpa();
                ++pontoJogadorDois;
                gotoXY(38, 23);
                cout << ""<<pontoJogadorUm<<"X"<<pontoJogadorDois<<"";
                gotoXY(25, 10);
                cout << "Ponto! Reiniciando em 3 segundos.";
                espera(3000);
                barraEsquerda.limpa();
                barraEsquerda.setY(8);
                barraEsquerda.imprime();
                barraDireita.limpa();
                barraDireita.setY(8);
                barraDireita.imprime();
                gotoXY(25, 10);
                cout << "                                  ";
                bola.limpa();
                bola.setX(39);
                bola.setY(11);
                bola.imprime();
                direcao = randomico(1, 6);
                espera(50);
            }
            else if(bola.getX() > 79)   //////////////////ponto do jogador 1
            {
                bola.limpa();
                ++pontoJogadorUm;
                gotoXY(38, 23);
                cout << ""<<pontoJogadorUm<<"X"<<pontoJogadorDois<<"";
                gotoXY(25, 10);
                cout << "Ponto! Reiniciando em 3 segundos.";
                espera(3000);
                barraEsquerda.limpa();
                barraEsquerda.setY(8);
                barraEsquerda.imprime();
                barraDireita.limpa();
                barraDireita.setY(8);
                barraDireita.imprime();
                gotoXY(25, 10);
                cout << "                                 ";
                bola.limpa();
                bola.setX(39);
                bola.setY(11);
                bola.imprime();
                direcao = randomico(1, 6);
                espera(50);

            }
        }
//////////////////////////////////////////////////// Colisão com as bordas
        if(bola.colisao(borda1))
        {

            if(direcaoMovimento == 'd') //se ela bater na borda 1 se movendo pra direita
            {
                bola.limpa();
                bola.setX(bola.getX() + 2);
                bola.setY(bola.getY() - 1);
                bola.imprime();
                direcao = 4;
            }
            else if(direcaoMovimento == 'e') //mesma coisa, se mexendo pra esquerda
            {
                bola.limpa();
                bola.setX(bola.getX() - 2);
                bola.setY(bola.getY() - 1);
                bola.imprime();
                direcao = 3;
            }
            borda1.limpa();
            borda1.imprime();
            tempoDeJogo = tempoInicio();

        }
////////////////////////////////////////////////////
        else if(bola.colisao(borda2))
        {

            if(direcaoMovimento == 'd')
            {
                bola.limpa();
                bola.setX(bola.getX() + 2);
                bola.setY(bola.getY() + 1);
                bola.imprime();
                direcao = 6;
            }
            else if(direcaoMovimento == 'e')
            {
                bola.limpa();
                bola.setX(bola.getX() - 2);
                bola.setY(bola.getY() + 1);
                bola.imprime();
                direcao = 5;
            }

            borda2.limpa();
            borda2.imprime();

            tempoDeJogo = tempoInicio();
        }


        if(bola.colisao(barraEsquerda))
        {
            int yDaBarra = barraEsquerda.getY();
            int angulo = 0;


//////////////////////////////////////////////////////////////////////////////  Cada if determina a direção da bola depois do impacto.

            if(bola.getY() == yDaBarra)
            {
                angulo = 75;
                direcao = 4;
                direcaoMovimento = 'd';    //nesse caso, a bolinha bateu no topo ou na parte mais baixa
            }

            else if(bola.getY() == yDaBarra+6)
            {
                angulo = 75;
                direcao = 6;
                direcaoMovimento = 'd';
            }

///////////////////////////////////////////////////////////////

            else if(bola.getY() == yDaBarra+1)
            {
                angulo = 50;        //nesse caso, ela bateu na segunda parte de cima pra baixo ou de baixo para cima da palheta.
                direcao = 4;
                direcaoMovimento = 'd';
            }
            else if(bola.getY() == yDaBarra+5)
            {
                angulo = 50;
                direcao = 6;
                direcaoMovimento = 'd';
            }


//////////////////////////////////////////////////////

            else if(bola.getY() == yDaBarra+2)
            {
                angulo = 25;
                direcao = 4;
                direcaoMovimento = 'd'; //nesse caso, a bolinha bateu em uma das duas partes da palheta depois ou antes do meio.
            }
            else if(bola.getY() == yDaBarra+4)
            {
                direcao = 6;
                angulo = 25;
                direcaoMovimento = 'd';
            }

//////////////////////////////////////////////////

            else if(bola.getY() == yDaBarra+3)
            {
                angulo = 0;
                direcao = 1;  //nesse caso, ela bateu exatamente no meio, ou seja, angulo = 0.
                direcaoMovimento = 'd';
            }

            barraEsquerda.limpa();
            barraEsquerda.imprime();

        }


/////////////////////////////////////////////////////
        else if(bola.colisao(barraDireita))
        {
            int yDaBarra = barraDireita.getY();


            if(bola.getY() == yDaBarra)
            {
                angulo = 75;
                direcao = 3;
                direcaoMovimento = 'e';
            }
            else if(bola.getY() == yDaBarra+6)
            {
                angulo = 75;
                direcao = 5;
                direcaoMovimento = 'e';
            }

//////////////////////////////////////////////////
            else if(bola.getY() == yDaBarra+1)
            {
                angulo = 50;
                direcao = 5;
                direcaoMovimento = 'e';
            }
            else if(bola.getY() == yDaBarra+5)
            {
                angulo = 50;
                direcao = 5;
                direcaoMovimento = 'e';
            }

/////////////////////////////////////////////
            else if(bola.getY() == yDaBarra+2)
            {
                angulo = 25;
                direcao = 3;
                direcaoMovimento = 'e';
            }

            else if(bola.getY() == yDaBarra+4)
            {
                angulo = 25;
                direcao = 5;
                direcaoMovimento = 'e';
            }

/////////////////////////////////////////
            else if(bola.getY() == yDaBarra+3)
            {
                angulo = 0;
                direcao = 2;
                direcaoMovimento = 'e';
            }

            angulo = 0;
            direcaoMovimento = 0;

            barraDireita.limpa();
            barraDireita.imprime();

        }

    }
}






