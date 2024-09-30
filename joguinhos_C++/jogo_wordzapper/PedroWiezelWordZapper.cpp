#include "biblaureano.h"

///sdds tempo livre.
///sdds n ter problemas de saúde por causa de trabalhos e estresse.
///sdds vida
///sdds felicidade

void vitoria(char& tecladnv, int pontos)
{
    noecho(0);
    gotoXY(1, 1);
    tecladnv = readChar("De novo? (s/n) ");

    if( tecladnv == 's' ||  tecladnv == 'S')
    {
        limparTela();
        noecho(1);
        return;

    }
    if(tecladnv == 'G' || tecladnv == 'g')
    {
        limparTela();
        cout << "Você agora é deus do C++. Você ganhou automaticamente todos os jogos e a vida." << endl;
        cout << "Você é amor. Você é vida." << endl;
        cout << "Shhhh. It's all C++ now." << endl;
    }
    else
    {
        if(pontos < 1000000)
        {
            limparTela();
            cout << "Você marcou "<<pontos<<" pontos. Menos de um milhão? Que desonra. Volte e zapeie mais palavras!" << endl;
        }
        else if(pontos > 1000000 && pontos < 2000000)
        {
            limparTela();
            cout << "Você marcou "<<pontos<<" pontos. Quantidade lamentável. Jogue de novo." << endl;
        }
        else if(pontos > 2000000 && pontos < 3000000)
        {
            limparTela();
            cout << "Você marcou "<<pontos<<" pontos. Ainda não é aceitável. Jogue de novo." << endl;
        }
        else if(pontos > 3000000 && pontos < 4000000)
        {
            limparTela();
            cout << "Você marcou "<<pontos<<" pontos. Essa é uma quantidade menos lamentável." << endl;
        }
        else if(pontos > 4000000 && pontos < 5000000)
        {
            limparTela();
            cout << "Você marcou "<<pontos<<" pontos. Está ok. Não é um recorde mas está bom." << endl;
        }
        else if(pontos > 5000000 && pontos < 6000000)
        {
            limparTela();
            cout << "Você marcou "<<pontos<<" pontos. Bem jogado." << endl;
        }
        else if(pontos > 6000000 && pontos < 7000000)
        {
            limparTela();
            cout << "Você marcou "<<pontos<<" pontos. Muito bem jogado." << endl;
        }
        else if(pontos > 7000000)
        {
            limparTela();
            cout << "Você marcou "<<pontos<<" pontos. Você é um deus das palavras." << endl;
        }
        noecho(1);
        return;
    }
}

void estufaVector(vector<char> letras, int s, char letra)
{
    for(int s = 0; s <= 26; s++)
    {
        letras.push_back(letra);
        letra++;
    }
}

void instrucoes(int& opcao, char& pronto)
{
    limparTela();
    cout << "Bem vindo ao..." << endl;
    Imagem wordZapper(retornaConteudoArquivo("Pedro_Martins_WordZapper_01.txt"), 1, 3);
    wordZapper.imprime();
    espera(4000);
    limparTela();

    mudaCor(RED);
    cout << "Sua missão é formar a palavra escrita na tela brevemente." << endl;
    cout << "Para isso, atire nas letras." << endl;
    cout << "Dos lados, virão inimigos, que te atrapalharão." << endl;

    mudaCor(YELLOW);
    cout << "\nUma nave inimiga vale uma quantidade de 1 ponto." << endl;
    cout << "Acertar uma letra vale uma quantidade aleatória de pontos." << endl;
    cout << "Acertar uma letra já acertada vale uma quantidade aleatória menor de pontos." << endl;

    mudaCor(GREEN);
    cout << "\nR atira para cima, E, para esquerda, e T, para direita." << endl;
    cout << "Para movimentação, use as setas direcionais." << endl;
    cout << "\n\n\n\t\t\tBom jogo!" << endl;

    opcao = 1;
    pronto = readChar("Pronto? (s/n)");
    limparTela();

    return;
}

int main()
{
    char apronto = 'n';
    char& pronto = apronto;
    char tecladnv = 's';

    while(tecladnv == 's' || tecladnv == 'S')
    {
        string menuDif [] = {"Novo Jogo", "Instruções", "Sair"};
        int opcao = mostraMenuV ( 4, 7, menuDif, 3, GREEN);

        if(opcao == 1)
        {

            gotoXY(33, 16);
            limparTela();
            pronto ='S';


            if(pronto == 'S' || pronto == 's')
            {
                limparTela();
                noecho(1);

                while(tecladnv == 's' || tecladnv == 'S')
                {
                    int pontos = 0;
                    string palavras = retornaConteudoArquivo("Pedro_Martins_WordZapper_02.txt");
                    string palavra = palavraAleatoria(palavras); ///seleciona a palavra
                    string palavraMostrar = palavra;
                    string palavraFormar = "";
                    int ondebotarPalavra = (79-(palavra.size()+1))/2;

                    gotoXY(ondebotarPalavra, 1);
                    cout << "Palavra: " << endl;
                    gotoXY(ondebotarPalavra, 2);
                    cout<<palavraMostrar<<endl;
                    espera(3500);
                    limparTela();
                    gotoXY(64, 1);
                    cout << "r - atira p/cima"<<endl;
                    gotoXY(64, 2);
                    cout << "e - atira p/esq."<<endl;
                    gotoXY(64, 3);
                    cout << "t - atira p/dir."<<endl;

                    desligaCursor(1);

                    int p = 0;
                    int k = 1;
                    int j = 2;
                    int s = 3;

                    char letra = 97;
                    char tela[79][24];

                    Imagem nave("(|*|)", 39, 23);
                    nave.imprime();
                    Imagem tiro("*", nave.getX()+4, nave.getY());
                    Imagem naveInimiga("@%@");
                    Imagem naveInimigaEsquerda("@#@");
                    naveInimiga.setLimites(1, 1, 79, 24);
                    naveInimigaEsquerda.setLimites(1, 1, 79, 24);
                    tiro.setLimites(1, 9, 79, 24);
                    nave.setLimites(1, 12, 79, 24);
                    Imagem parede("$");

                    for(int i = 1; i <= 79; i++)
                    {
                        mudaCor(GREEN);
                        parede.imprime(i, 8); ///PAREDES DE CIFRÃO VALEM MAIS DO QUE DINHEIRO. MAOEEEE - Abravanel
                    }


                    vector<char> letras;

                    tela[33][10] = ' ';
                    tela[36][10] = ' ';
                    tela[39][10] = ' ';
                    tela[42][10] = ' ';

                    for(int s = 0; s <= 26; s++)
                    {
                        letras.push_back(letra);
                        letra++;
                    }
                    for(int l = 0; l < palavra.length(); l++)
                    {
                        palavraFormar += '*'; ///forma a palavra desconhecida
                    }

                    gotoXY(ondebotarPalavra, 2);
                    cout<<palavraFormar;

                    int contTempoUm = 0;
                    int contTempoDois = 0; ///função tempo é bem bugada, foi na base do int mesmo...
                    int contTempoTres= 0;
                    int contTempoQuatro = 0;
                    int contTiro = 0;
                    int contNaveInimiga = 0;

                    int direcaoBala = 0;

                    bool tiroImprimido = 0; ///para movimentação

                    int yNaveSpawn = randomico(11, 24);

                    naveInimiga.imprime(73, yNaveSpawn);
                    naveInimigaEsquerda.imprime(4, yNaveSpawn+2);

                    while(true)
                    {
                        mudaCor(BLUE);
                        gotoXY(64, 5);
                        cout<<"Pontos: "<<pontos<<""<<endl;
                        limpaEfeito();

                        ++contTempoUm;
                        ++contTempoDois; ///vai add nos tempos
                        ++contTempoTres;
                        ++contTempoQuatro;
                        ++contNaveInimiga;

                        if(tiro.colisao(parede))
                        {
                            tiro.limpa();
                            parede.limpa();
                            parede.imprime(tiro.getX(), tiro.getY());

                        }
                        if(nave.colisao(naveInimiga) || nave.colisao(naveInimigaEsquerda) )
                        {
                            nave.limpa();
                            nave.setX(37);
                            nave.setY(18);
                            nave.imprime();
                            limpaEfeito();
                        }
                        if(tiro.colisao(naveInimiga))
                        {
                            tiro.limpa();
                            naveInimiga.limpa();
                            yNaveSpawn = randomico(11, 24);
                            naveInimiga.imprime(79, yNaveSpawn);
                            pontos++;
                        }
                        if(tiro.colisao(naveInimigaEsquerda))
                        {
                            tiro.limpa();
                            naveInimiga.limpa();
                            yNaveSpawn = randomico(11, 24);
                            naveInimigaEsquerda.imprime(79, yNaveSpawn);
                            pontos++;
                        }
                        if(contNaveInimiga > 10)
                        {
                            naveInimiga.limpa();
                            naveInimigaEsquerda.limpa();
                            naveInimiga.decrementaX();
                            naveInimigaEsquerda.incrementaX();
                            naveInimiga.imprime();
                            naveInimigaEsquerda.imprime();
                            contNaveInimiga = 0;
                        }
                        if(contTempoUm > 250)
                        {
                            mudaCor(RED);
                            gotoXY(33, 10);
                            cout << letras[p] ;
                            tela[33][10] = letras[p];
                            ++p;
                            contTempoUm = 0;
                            limpaEfeito();
                        }
                        if(p== 27)
                        {
                            p = 0;
                        }
                        if(contTempoDois > 250)
                        {
                            mudaCor(RED);
                            gotoXY(36, 10);
                            cout << letras[k];
                            tela[36][10] = letras[k];
                            limpaEfeito();
                            ++k;
                            contTempoDois = 0;
                        }

                        if(k == 27)
                        {
                            k = 0;
                        }

                        if(contTempoTres > 250)
                        {
                            mudaCor(RED);
                            gotoXY(39, 10);
                            cout << letras[j] ;
                            tela[39][10] = letras[j];
                            limpaEfeito();
                            ++j;
                            contTempoTres = 0;
                        }

                        if(j == 27)
                        {
                            j = 0;
                        }

                        if(contTempoQuatro > 250)
                        {
                            mudaCor(RED);
                            gotoXY(42, 10);
                            cout << letras[s] ;
                            tela[42][10] = letras[s];
                            ++s;
                            limpaEfeito();
                            contTempoQuatro = 0;
                        }

                        if(s == 27)
                        {
                            s = 0;
                        }

                        if(kbhit())
                        {
                            char tecla = getch();

                            if (tecla == K_LEFT)
                            {
                                nave.limpa();
                                nave.decrementaX();
                                nave.imprime();
                                limpaEfeito();
                            }
                            if(tecla == K_RIGHT )
                            {
                                nave.limpa();
                                nave.incrementaX();
                                nave.imprime();
                                limpaEfeito();
                            }
                            if(tecla == K_UP)
                            {
                                nave.limpa();
                                nave.decrementaY();
                                nave.imprime();
                                limpaEfeito();
                            }
                            if(tecla == K_DOWN)
                            {
                                nave.limpa();
                                nave.incrementaY();
                                nave.imprime();
                                limpaEfeito();
                            }
                            if(tecla == 'r' && tiroImprimido != 1 || tecla == 'R' && tiroImprimido != 1)
                            {
                                mudaCor(WHITE);
                                tiro.limpa();
                                tiro.imprime(nave.getX()+2, nave.getY()-1); ///tiro pra cima
                                tiroImprimido = 1;
                                direcaoBala = 1;
                            }
                            if(tecla == 'E' && tiroImprimido != 1 || tecla == 'e' && tiroImprimido != 1)
                            {
                                mudaCor(WHITE);
                                tiro.limpa();
                                tiro.imprime(nave.getX(), nave.getY()); ///tiro pra esq
                                tiroImprimido = 1;
                                direcaoBala = 2;
                            }
                            if(tecla == 'T' && tiroImprimido != 1 || tecla == 't' && tiroImprimido != 1)
                            {
                                mudaCor(WHITE);
                                tiro.limpa();
                                tiro.imprime(nave.getX()+4, nave.getY()); ///tiro pra dir
                                tiroImprimido = 1;
                                direcaoBala = 3;
                            }
                        }
                        if(tiroImprimido == 1)
                        {
                            contTiro++; ///tempo mov tiro
                        }
                        if(contTiro > 10 && direcaoBala == 1)
                        {
                            mudaCor(WHITE);
                            tiro.limpa();
                            tiro.decrementaY(); ///tiro cima
                            tiro.imprime();
                            contTiro = 0;
                            limpaEfeito();
                        }
                        else if(contTiro > 10 && direcaoBala == 2)
                        {
                            mudaCor(WHITE);
                            tiro.limpa(); ///tiro esq.
                            tiro.decrementaX();
                            tiro.imprime();
                            contTiro = 0;
                            limpaEfeito();
                        }
                        else if(contTiro > 10 && direcaoBala == 3)
                        {
                            mudaCor(WHITE);
                            tiro.limpa(); ///tiro dir.
                            tiro.incrementaX();
                            tiro.imprime();
                            contTiro = 0;
                            limpaEfeito();
                        }
                        if(tiro.getY() == 9)
                        {
                            tiro.limpa();
                            tiroImprimido = 0;
                        }
                        if(tiro.getX() == 42 && tiro.getY() == 10)
                        {
                            if(palavra.find(tela[42][10]) != string::npos)
                            {
                                for(int i = 0; i< palavraFormar.length(); i++)
                                {
                                    if(palavra[i] == tela[42][10]) ///verifica a letra atingida. E substitui se houver na palavra. Mesmo esquema da forca.
                                    {
                                        palavraFormar[i] = tela[42][10];
                                        gotoXY(ondebotarPalavra, 2);
                                        cout<<palavraFormar;
                                    }
                                }
                                tiro.limpa();
                                pontos += randomico(1, 100000);
                            }
                            else
                            {
                                tiro.limpa();
                            }

                        }
                        else if(tiro.getX() == 39 && tiro.getY() == 10)
                        {
                            if(palavra.find(tela[39][10]) != string::npos)
                            {
                                for(int i = 0; i<= palavraFormar.length(); i++)
                                {
                                    if(palavra[i] == tela[39][10])
                                    {
                                        palavraFormar[i] = tela[39][10]; ///verifica e substitui
                                        gotoXY( ondebotarPalavra, 2);
                                        cout<<palavraFormar;
                                    }
                                }

                                tiro.limpa();
                                pontos += randomico(1, 100000);
                            }
                            else
                            {
                                tiro.limpa();
                            }
                        }
                        else if(tiro.getX() == 36 && tiro.getY() == 10)
                        {
                            if(palavra.find(tela[39][10]) != string::npos)
                            {
                                for(int i = 0; i<= palavraFormar.length(); i++) ///verifica e substitui
                                {
                                    if(palavra[i] == tela[36][10])
                                    {
                                        palavraFormar[i] = tela[36][10];
                                        gotoXY(ondebotarPalavra, 2);

                                        cout<<palavraFormar;
                                    }
                                }
                                tiro.limpa();
                                pontos += randomico(1, 100000);
                            }
                            else
                            {
                                tiro.limpa();
                            }

                        }
                        else if(tiro.getX() == 33 && tiro.getY() == 10)
                        {
                            if(palavra.find(tela[33][10]) != string::npos)
                            {
                                for(int l = 0; l<= palavraFormar.length(); l++)
                                {
                                    if(palavra[l] == tela[33][10]) ///verifica e substitui
                                    {
                                        palavraFormar[l] = tela[33][10];
                                        gotoXY(ondebotarPalavra, 2);
                                        cout<<palavraFormar;
                                    }
                                }

                                tiro.limpa();
                                pontos += randomico(1, 100000);
                            }
                            else
                            {
                                tiro.limpa();
                            }
                        }
                        if(palavraFormar.find('*') == string::npos)
                        {
                            vitoria(tecladnv, pontos); ///ei. acabou o asterisco. (isso significa fim de jogo. Continue? (y/n))
                            break;
                        }
                        if(naveInimiga.getX() < 2)
                        {
                            naveInimiga.limpa();
                            naveInimiga.setY(randomico(11, 24));
                            naveInimiga.setX(74);
                            naveInimiga.imprime();
                        }
                        if(naveInimigaEsquerda.getX() > 77) ///volte aqui, nave!
                        {
                            naveInimigaEsquerda.limpa();
                            naveInimigaEsquerda.setX(5);
                            naveInimigaEsquerda.setY(randomico(11, 24));
                            naveInimigaEsquerda.imprime();
                        }

                        limpaEfeito();

                        if(tiro.getX() > 78)
                        {
                            tiro.limpa();
                            tiroImprimido = 0;
                        }
                        if(tiro.getX() < 2)
                        {
                            tiro.limpa();
                            tiroImprimido = 0;
                        }
                    }
                }
            }
            else
            {

                return 0;
            }
        }
        else if(opcao == 2)
        {
            instrucoes(opcao, pronto);
        }
        else if(opcao == 3)
        {
            return 0;
        }
    }
}
