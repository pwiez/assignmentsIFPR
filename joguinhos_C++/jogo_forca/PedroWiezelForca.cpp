#include "biblaureano.h" //Notinha de rodapé: Nenhum goto foi usado pra redirecionar pra um pedaço do código, apenas pra posicionamento
// na tela. gotoXY e tudo mais...


bool verificadoraTentativa(char tentativa, int maxErros);

void creditos();

void creditos()
{
    limparTela();
    cout << "Creditos:" << endl;
    cout << "\n Carrasco: Galenogal Verga Grande" << endl;
    cout << "\n Preso: Você" << endl;
    cout << "\n Fabricante da corda da forca: The Acme Corporation (feita sob medida em 2002)" << endl;
    cout << "\n Creditos: Creditos" << endl;
    return;
}

bool verificadoraTentativa(char tentativa, int maxErros)
{
    Imagem vitoria(retornaConteudoArquivo("PedroMartinsDesenho02.txt"), 1, 6);
    Imagem forca(retornaConteudoArquivo("PedroMartinsDesenho01.txt"), 1, 1);
    Imagem presoFeliz(retornaConteudoArquivo("PedroMartinsDesenho03.txt"), 50, 1);
    Imagem derrota(retornaConteudoArquivo("PedroMartinsDesenho06.txt"), 1, 6);
    Imagem corda(retornaConteudoArquivo("PedroMartinsDesenho05.txt"), 40, 1);
    Imagem derrotacarinha(retornaConteudoArquivo("PedroMartinsDesenho07.txt"), 40, 3);

    string palavra = retornaConteudoArquivo("forca.txt");
    string palavraEscolhida = palavraAleatoria(palavra);
    string palavraFormando = "";
    string linhaDeTentativas = " ";

    int erros = 0;
    int palavraFormandoComprimento = palavraEscolhida.length(); //separando tipos de variável. Organização.

    bool letraPodeSerAdicionadaaLinhaDeTentativas = 0;

    for(int l = 0; l <= palavraFormandoComprimento -1; l++)
    {
        palavraFormando += "_";
    }

    gotoXY(30, 20);
    cout << ""<<palavraFormando<<"";

    while(erros < maxErros)
    {
        forca.imprime();
        gotoXY(40, 20);
        tentativa = readChar("\n\nInsira tentativa: ");
        gotoXY(35, 6);
        cout<<linhaDeTentativas;
        gotoXY(50, 1);
        cout << "Erros: "<<erros<<".";


        if(palavraEscolhida.find(tentativa) == string::npos)
        {
            limparTela();
            erros++;
            gotoXY(20, 24);
            cout << "ERRO!" << endl;
            gotoXY(30, 20);
            cout<<palavraFormando<<endl;
            linhaDeTentativas = (linhaDeTentativas + tentativa) + "-";
            gotoXY(35, 6);
            cout<<linhaDeTentativas;
            gotoXY(50, 1);
            cout << "Erros: "<<erros<<".";
            forca.imprime();
        }
        else
        {
            int comprimentoFrase = palavraEscolhida.length();

            for (int i = 0; i <= comprimentoFrase; ++i)
            {
                if(tentativa == palavraFormando[i])
                {
                    gotoXY(1, 19);
                    cout << "Letra já usada!!!";
                    espera(100);

                }
                if (palavraEscolhida[i] == tentativa) //se achar a tentativa na posição i, substitui
                {
                    palavraFormando[i] = tentativa;
                    letraPodeSerAdicionadaaLinhaDeTentativas = 1;
                }
            }

            if(letraPodeSerAdicionadaaLinhaDeTentativas == 1)
            {
                linhaDeTentativas = (linhaDeTentativas + tentativa) + "-";
            }

            limparTela();
            forca.imprime();
            gotoXY(35, 6);
            cout<<linhaDeTentativas;
            gotoXY(50, 1);
            cout << "Erros: "<<erros<<".";
            gotoXY(30, 20);
            cout<<palavraFormando<<endl;
        }

        if(palavraFormando.find("_") == string::npos) //quando não encontrar underline, fechou, GG
        {
            limparTela();
            vitoria.imprime();
            presoFeliz.imprime();
            mudaCor(GREEN);
            char tentarDNV = readChar("Você ganhou! (Galenogal ficou irritado) Jogar de novo? (Y/N)");
            limpaEfeito();

            if(tentarDNV == 'n' || tentarDNV == 'N')
            {
                return 1;
            }
            else if(tentarDNV == 'y' || tentarDNV == 'Y')
            {
                limparTela();
                corda.imprime();
                string menuDificuldade[] = { "Normal (6 erros)" , "Tormento (4 erros)" , "Inferno (2 erros)" , "Nightmare (1 erro)" , "Sair" };
                int opcao = mostraMenuV (4 , 7 , menuDificuldade , 5 ,GREEN); //Nightmare == IFPR

                if(opcao == 1)
                {
                    maxErros = 6;
                    limparTela();
                }
                else if(opcao == 2)
                {
                    maxErros = 4;
                    limparTela();
                }
                else if(opcao == 3)
                {
                    maxErros = 2;
                    limparTela();
                }
                else if(opcao == 4)
                {
                    maxErros = 1;
                    limparTela();
                }
                else if(opcao == 5)
                {
                    return 0;
                }

                erros = 0;
                palavraEscolhida = palavraAleatoria(palavra);
                palavraFormandoComprimento = palavraEscolhida.length();
                palavraFormando = "";

                for(int l = 0; l <= palavraFormandoComprimento -1; l++)
                {
                    palavraFormando += "_";
                }
                linhaDeTentativas = " ";
            }

            limparTela();
            forca.imprime();
            gotoXY(30, 20);
            cout << ""<<palavraFormando<<"";
        }


        if(erros == maxErros)
        {
            limparTela();
            derrota.imprime();
            derrotacarinha.imprime();
            mudaCor(RED);
            cout << "Enforcado! A palavra era '"<<palavraEscolhida<<"'." << endl;
            limpaEfeito();
            char tentarDNV = readChar("\nTentar de novo? (Y/N)");

            if(tentarDNV == 'n' || tentarDNV == 'N')
            {
                return 0;
            }

            else if(tentarDNV == 'y' || tentarDNV == 'Y')
            {
                limparTela();
                corda.imprime();

                string menuDificuldade[] = {"Normal (6 erros)", "Tormento (4 erros)", "Inferno (2 erros)", "Nightmare (1 erro)", "Sair"};
                int opcao = mostraMenuV( 4 , 7 , menuDificuldade , 5 ,GREEN);

                if(opcao == 1)
                {
                    maxErros = 6;
                    limparTela();
                }
                else if(opcao == 2)
                {
                    maxErros = 4;
                    limparTela();
                }
                else if(opcao == 3)
                {
                    maxErros = 2;
                    limparTela();
                }
                else if(opcao == 4)
                {
                    maxErros = 1;
                    limparTela();
                }
                else if(opcao == 5)
                {
                    return 0;
                }

                erros = 0;

                palavraEscolhida = palavraAleatoria(palavra);
                palavraFormandoComprimento = palavraEscolhida.length();
                palavraFormando = "";

                for(int l = 0; l <= palavraFormandoComprimento -1; l++)
                {
                    palavraFormando += "_";
                }

                linhaDeTentativas = " ";

            }

            limparTela();
            forca.imprime();
            gotoXY(30, 20);
            cout << ""<<palavraFormando<<"";
        }

        letraPodeSerAdicionadaaLinhaDeTentativas = 0;
    }
}


int main()
{
    desligaCursor(true);

    Imagem comeco(retornaConteudoArquivo("PedroMartinsDesenho04.txt"), 14, 6); //Decoração
    comeco.imprime();
    espera(3000);

    limparTela();
    Imagem corda(retornaConteudoArquivo("PedroMartinsDesenho05.txt"), 40, 1);
    corda.imprime();

    string menuDificuldade[] = { "Normal (6 erros)" , "Tormento (4 erros)" , "Inferno (2 erros)" , "Nightmare (1 erro)" , "Sair" };
    int opcao = mostraMenuV( 4 , 7 , menuDificuldade , 5 ,GREEN); //Nightmare == IFPR

    int maxErros = 0;
    char tentativa = 0;

    if(opcao == 1)
    {
        maxErros = 6;
        limparTela();
    }
    else if(opcao == 2)
    {
        maxErros = 4;
        limparTela();
    }
    else if(opcao == 3)
    {
        maxErros = 2;
        limparTela();
    }
    else if(opcao == 4)
    {
        maxErros = 1;
        limparTela();
    }
    else if(opcao == 5)
    {
        return 0;
    }

    bool gg = verificadoraTentativa(tentativa, maxErros);

    if(gg == 1)
    {
        creditos();
    }
    else
    {
        limparTela();
        cout << "Tu não merece creditos porque tu não ganhou o jogo. Fim!" << endl;
    }

    return 0;
}
