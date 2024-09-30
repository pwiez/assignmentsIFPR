#include "biblaureano.h"
#include "math.h"

int main()
{
    desligaCursor(true);
    mudaTamanhoTerminal(100,30);
    noecho(true);
    bool mainMenu = 1;
    bool jogo = 0;
    Imagem logotipo(retornaConteudoArquivo("Pedro_Martins_angrybirds001.txt"), 20, 5);


    while(mainMenu == 1)
    {
        logotipo.imprime();
        espera(1500);
        mainMenu = 0;
        jogo = 1;
        logotipo.limpa();
    }


    Imagem naveAmiga(retornaConteudoArquivo("Pedro_Martins_angrybirds004.txt"), 2, 22);
    Imagem alvo(retornaConteudoArquivo("Pedro_Martins_angrybirds003.txt"), 72, 11);
    Imagem alvo2(retornaConteudoArquivo("Pedro_Martins_angrybirds003.txt"), 72, 12);
    Imagem alvo3(retornaConteudoArquivo("Pedro_Martins_angrybirds003.txt"), 72, 23);
    Imagem bola("o", naveAmiga.getX() + 6, naveAmiga.getY());
    Imagem decoracaoDeTela(retornaConteudoArquivo("Pedro_Martins_angrybirds_006.txt"), 70, 3);
    Imagem vitoria(retornaConteudoArquivo("Pedro_Martins_angrybirds_005.txt"), 5, 5);

    decoracaoDeTela.imprime();

    naveAmiga.setLimites(1, 2, 20, 45);
    alvo.setLimites(70, 12, 79, 14);
    alvo2.setLimites(70, 14, 79, 19);
    alvo3.setLimites(70, 18, 79, 20);
    bola.setLimites(1, 1, 90, 30);

    naveAmiga.imprime();
    alvo.imprime();
    alvo2.imprime();
    alvo3.imprime();

    TEMPO tempoAlvos = tempoInicio();

    int pontos = 0;
    int direcao = 0;
    int inimigosRestantes = 3;
    int quantidadeEmYNoMovimentoInicial, quantidadeEmXNoMovimentoInicial;
    int forca = 1;
    int quantidadeViajadaEmX = 0;
    int bonusDistancia = quantidadeViajadaEmX;


    bool alvo1PodeSerImprimido = 1;
    bool alvo2PodeSerImprimido = 1;
    bool alvo3PodeSerImprimido = 1;
    bool tiroAtirado = 0;


    mudaCor(GREEN);
    gotoXY(1, 1);
    cout << "Forca: "<<forca<<"";
    limpaEfeito();

    while(jogo == 1) //aqui começa mesmo
    {

        pontos = pontos+bonusDistancia;

        if(direcao == 1 && tiroAtirado == 1)
        {
            if(forca == 1)
            {
                quantidadeEmYNoMovimentoInicial = forca;
                quantidadeEmXNoMovimentoInicial = 2;
                bola.limpa();
                bola.setX(bola.getX() + quantidadeEmXNoMovimentoInicial);
                bola.setY(bola.getY() - quantidadeEmYNoMovimentoInicial);
                bola.imprime();
            }
            else if(forca == 2)
            {
                quantidadeEmYNoMovimentoInicial = 2;
                quantidadeEmXNoMovimentoInicial = 5;
                bola.limpa();
                bola.setX(bola.getX() + quantidadeEmXNoMovimentoInicial);
                bola.setY(bola.getY() - quantidadeEmYNoMovimentoInicial);
                bola.imprime();
            }
            else if(forca == 3)
            {
                quantidadeEmYNoMovimentoInicial = 3;
                quantidadeEmXNoMovimentoInicial = 6;
                bola.limpa();
                bola.setX(bola.getX() + quantidadeEmXNoMovimentoInicial);
                bola.setY(bola.getY() - quantidadeEmYNoMovimentoInicial);
                bola.imprime();

                int quantidadeViajadaEmX = quantidadeViajadaEmX+6;
                int bonusDistancia = quantidadeViajadaEmX;
            }
        }

        else if(direcao == 2 && tiroAtirado == 1)
        {
            bola.limpa();
            bola.incrementaX();
            bola.imprime();
            quantidadeViajadaEmX = quantidadeViajadaEmX+1;
            bonusDistancia = quantidadeViajadaEmX;

        }
        else if(direcao == 3 && tiroAtirado == 1)
        {
            quantidadeEmYNoMovimentoInicial = 1;
            quantidadeEmXNoMovimentoInicial = 2;
            bola.limpa();
            bola.setY(bola.getY() + quantidadeEmYNoMovimentoInicial);
            bola.setX(bola.getX() + quantidadeEmXNoMovimentoInicial);
            bola.imprime();
            quantidadeViajadaEmX = quantidadeViajadaEmX+2;
            bonusDistancia = quantidadeViajadaEmX;
        }


        if(kbhit())   //disparar o tiro e a força
        {
            char tecla = getch();

            if(tecla == 'f' || tecla == 'F')
            {
                direcao = 1;
                tiroAtirado = 1;
            }

            if(tecla == K_UP)
            {
                forca++;

                if(forca > 3)
                {
                    forca = 1;
                }

                mudaCor(GREEN);
                gotoXY(1, 1);
                cout << "Forca: "<<forca<<"";
                limpaEfeito();
            }

            if(tecla == K_DOWN)
            {
                forca--;

                if(forca < 1)
                {
                    forca = 3;
                }

                mudaCor(GREEN);
                gotoXY(1, 1);
                cout << "Forca: "<<forca<<"";
                limpaEfeito();

            }
        }


        if(bola.getX() == 41)
        {
            direcao = 2;
        }

        if(bola.getX() >  42+forca)
        {
            direcao = 3;
        }


        //movimentação e posicionamento dos alvos


        if(tempoPassado(tempoAlvos) > 10) //JooJ só se move se passar disso
        {

            int movimentacaoAlvoUm = randomico(0, 2);
            int movimentacaoAlvoDois = randomico(0, 2);
            int movimentacaoAlvoTres = randomico(0, 2);

            if(movimentacaoAlvoUm == 1 && tempoDecorrido(tempoAlvos) > 3 && alvo1PodeSerImprimido == 1)  //movimentacao do primeiro alvo
            {
                alvo.limpa();
                alvo.incrementaY();
                alvo.imprime();
                tempoAlvos = tempoInicio();
            }
            else if(movimentacaoAlvoUm == 0  && tempoDecorrido(tempoAlvos) > 3 && alvo1PodeSerImprimido == 1)
            {
                alvo.limpa();
                alvo.decrementaY();
                alvo.imprime();
                tempoAlvos = tempoInicio();
            }


/////////////////////////////////////////////////////////////////////////////////////////////////////////

            if(movimentacaoAlvoDois == 0  && tempoDecorrido(tempoAlvos) > 3 && alvo2PodeSerImprimido == 1) //segundo alvo
            {
                alvo2.limpa();
                alvo2.incrementaY();
                alvo2.imprime();
                tempoAlvos = tempoInicio();
            }
            else if(movimentacaoAlvoDois == 1  && tempoDecorrido(tempoAlvos) > 3 && alvo2PodeSerImprimido == 1)
            {
                alvo2.limpa();
                alvo2.decrementaY();
                alvo2.imprime();
                tempoAlvos = tempoInicio();
            }


/////////////////////////////////////////

            if(movimentacaoAlvoTres == 1  && tempoDecorrido(tempoAlvos) > 3 && alvo3PodeSerImprimido == 1) //terceiro alvo
            {
                alvo3.limpa();
                alvo3.incrementaY();
                alvo3.imprime();
                tempoAlvos = tempoInicio();
            }
            else if(movimentacaoAlvoTres == 0  && tempoDecorrido(tempoAlvos) > 3 && alvo3PodeSerImprimido == 1)
            {
                alvo3.limpa();
                alvo3.decrementaY();
                alvo3.imprime();
                tempoAlvos = tempoInicio();
            }
///////////////////////////////////////////////

            if(alvo.colisao(alvo2) && alvo1PodeSerImprimido == 1 && alvo2PodeSerImprimido == 2)
            {
                alvo.limpa();
                alvo2.limpa();

                alvo.decrementaY();
                alvo2.incrementaY();

                alvo.imprime();
                alvo2.imprime();

                tempoAlvos = tempoInicio();
            }

            if(alvo2.colisao(alvo3) && alvo2PodeSerImprimido == 1 && alvo3PodeSerImprimido == 1)
            {
                alvo2.limpa();
                alvo3.limpa();

                alvo2.decrementaY();
                alvo3.incrementaY();

                alvo2.imprime();
                alvo3.imprime();

                tempoAlvos = tempoInicio();
            }

            tempoAlvos = tempoInicio();



        }

        if(bola.colisao(alvo) && alvo1PodeSerImprimido == 1)
        {
            alvo.limpa();
            bola.limpa();
            pontos = pontos + 1000;
            gotoXY(12, 1);
            cout << "Pontos: "<<pontos<<" (1000 por alvo, mais o bonus de distancia)";
            alvo1PodeSerImprimido = 0;
            inimigosRestantes--;
        }
        else if(bola.colisao(alvo2) && alvo2PodeSerImprimido == 1)
        {
            alvo2.limpa();
            bola.limpa();
            pontos = pontos + 1000;
            gotoXY(12, 1);
            cout << "Pontos: "<<pontos<<" (1000 por alvo, mais o bonus de distancia)";
            alvo2PodeSerImprimido = 0;
            inimigosRestantes--;
        }
        else if(bola.colisao(alvo3) && alvo3PodeSerImprimido == 1)
        {
            alvo3.limpa();
            bola.limpa();
            pontos = pontos +1000;
            gotoXY(12, 1);
            cout << "Pontos: "<<pontos<<" (1000 por alvo, mais o bonus de distancia)";
            alvo3PodeSerImprimido = 0;
            inimigosRestantes--;
        }

        espera(40);


        if(bola.getX() >  86 || bola.getY() > 28 || bola.getY() < 1)
        {
            bola.limpa();
            bola.setY(naveAmiga.getY());
            bola.setX(naveAmiga.getX() + 6);
            tiroAtirado = 0;
             quantidadeViajadaEmX = 0;
             bonusDistancia = quantidadeViajadaEmX;

        }

        if(inimigosRestantes == 0)
        {



            limparTela();


            Imagem vitoria(retornaConteudoArquivo("Pedro_Martins_angrybirds_005.txt"), 5, 5);
            vitoria.imprime();

            gotoXY(30, 22);
            cout << "Todos os alvos foram destruidos. Bom trabalho!";

            gotoXY(30, 24);
            cout << "Pontos totais: "<<pontos<<"";

            espera(5000);
            return 1;


        }

        int quantidadeViajadaEmX = quantidadeViajadaEmX+6;
        int bonusDistancia = quantidadeViajadaEmX;


    }

}
























