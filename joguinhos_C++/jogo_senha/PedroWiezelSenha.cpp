#include "biblaureano.h"

const int num_Fileiras = 10;
const string fileira = "| | | | |";

void vitoria()
{
    Imagem vitoria(retornaConteudoArquivo("Pedro_Martins_Senha_04.txt"), 5, 5);
    limparTela();
    vitoria.imprime();
    return;
}

void fracasso()
{
    Imagem fracasso(retornaConteudoArquivo("Pedro_Martins_Senha_03.txt"), 5, 5);
    limparTela();
    fracasso.imprime();
    return;
}

bool jogo(vector<int> senhaCores, bool& voltarMenu)
{

    desligaCursor(1);
    cout<<endl;
//    ^^^^^^ comentar se for linux, descomentar se for windows

    int u = 11;
    int l = 1;                          ///declaração variáveis iniciais
    int fileirasImprimidas = 0;
    int fileirasPreenchidas = 0;
    int chute = 0;
    int chuteEncontradoVezes = 0;
    int x = 1;
    int y = 1;
    int coresAdd = 0;
    int xI = 50;
    int yI = 19;
    int i = 0;
    int coordXSetinha = 20;
    int coordYSetinha = 1;

    bool fileiraPreenchida = 0;


    while(fileirasImprimidas <= num_Fileiras)
    {
        cout << ""<<fileira<<"\n";
        fileirasImprimidas++;
    }

    vector<int>::const_iterator iTera;

    gotoXY(60, 1);
    mudaCor(BLUE);
    cout << "Azul - 1;";
    gotoXY(60, 2);
    mudaCor(GREEN);
    cout<< "Verde - 2;";
    gotoXY(60, 3);
    mudaCor(PURPLE);
    cout<<"Violeta - 3;";
    gotoXY(60, 4);                  ///informações do menu
    mudaCor(YELLOW);
    cout<<"Amarelo - 4;";
    gotoXY(60, 5);
    mudaCor(RED);
    cout<< "Vermelho - 5;";
    gotoXY(60, 6);
    mudaCor(CYAN);
    cout << "Ciano - 6;";
    limpaEfeito();


    while(fileirasPreenchidas <= 10)
    {
        gotoXY(coordXSetinha, coordYSetinha);
        cout << "<";
        gotoXY(1, 24);
        cout << "Para saber a senha, digite a seguinte combinação: 777, e me agradeça depois."; ///cheat :D
        fileiraPreenchida = 0;
        gotoXY(30, 2);
        chute = readInt("Chute (1-6): ");
        string espaco = " "; ///lê e registra seu chute

        if(chute == 1)
        {
            gotoXY(x, y);
            mudaCor(BLUE, BLUE);
            cout << espaco;
            limpaEfeito(); ///coloca o chute na fileira, na posição
            x+=2;
            ++coresAdd;
        }
        else if(chute == 2)
        {
            gotoXY(x, y);
            mudaCor(GREEN, GREEN);
            cout << espaco;
            limpaEfeito();
            x+=2;
            ++coresAdd;
        }
        else if(chute == 3)
        {
            gotoXY(x, y);
            mudaCor(PURPLE, PURPLE);
            cout << espaco;
            limpaEfeito();
            x+=2;
            ++coresAdd;
        }
        else if(chute == 4)
        {
            gotoXY(x, y);
            mudaCor(YELLOW, YELLOW);
            cout << espaco;
            limpaEfeito();
            x+=2;
            ++coresAdd;
        }
        else if(chute == 5)
        {
            gotoXY(x, y);
            mudaCor(RED, RED);
            cout << espaco;
            limpaEfeito();
            x+=2;
            ++coresAdd;
        }
        else if(chute == 6)
        {
            gotoXY(x, y);
            mudaCor(CYAN, CYAN);
            cout << espaco;
            limpaEfeito();
            x+=2;
            ++coresAdd;
        }
        else if(chute == 777)
        {
            for(int j = 0; j < 4; j++)
            {
                gotoXY(xI, yI); ///cheat :D
                cout << senhaCores[j];
                ++xI;
            }
        }

        iTera = find(senhaCores.begin(), senhaCores.end(), chute);

        if( iTera != senhaCores.end() && senhaCores[i] != chute) ///caso encontre, porém não na posição...
        {
            mudaCor(WHITE, WHITE);
            gotoXY(u, l);
            cout << " ";
            ++u;
            limpaEfeito();
        }
        if(senhaCores[i] == chute) ///caso encontre no vector e esteja na posição certa
        {
            mudaCor255(245, 245);
            gotoXY(u, l);
            cout << " ";
            ++u;
            limpaEfeito();
            chuteEncontradoVezes++;
        }
        else if(iTera == senhaCores.end() && senhaCores[i] != chute && chute != 777) ///se não encontrar no vector, n imprime nada
        {
            gotoXY(u, l);
            limpaEfeito();
            cout << " ";
            u++;
        }

        iTera = senhaCores.begin() -1;  ///resetando iTera para o próximo chute

        if(x > 7)
        {
            x = 1;
            y++; ///fileira preenchida
            fileirasPreenchidas++;
        }

        limpaEfeito();
        gotoXY(30, 2);
        cout << " ";
        ++i;

        if(coresAdd == 4 && chuteEncontradoVezes < 4)
        {
            i = 0;
            u = 11;
            l++;
            coresAdd = 0;
            fileiraPreenchida = 1;
            chuteEncontradoVezes = 0; ///você não ganhou nessa fileira
            gotoXY(coordXSetinha, coordYSetinha);
            cout << " ";
            coordYSetinha++;
        }
        else if(coresAdd == 4 && chuteEncontradoVezes == 4)
        {
            return 1; ///você ganhou nessa fileira!
        }
    }
    return 0;
}

int main()
{
    bool voltarMenu = 0;

    while(voltarMenu == 0)
    {
        Imagem logo(retornaConteudoArquivo("Pedro_Martins_Senha_01.txt"), 5, 5);
        Imagem regras(retornaConteudoArquivo("Pedro_Martins_Senha_02.txt"), 1, 15);
        logo.imprime();
        espera(1000);
        limparTela();
        gotoXY(30, 1);
        mudaCor(CYAN);
        cout<< "Criado por Pedro Fernando Martins, J1";
        limpaEfeito();
        string menuOpcoes[] = {"Iniciar" , "Sair" , "Regras"};
        int opcao = mostraMenuV ( 4 , 7 , menuOpcoes , 3 ,RED);

        if(opcao == 1)
        {
            vector<int> senhaCores;
            vector<int> senhaJogador;

            int k = randomico(1, 6);
            int j = randomico(1, 6);
            int c = randomico(1, 6);
            int m = randomico(1, 6);

            while(j == k ||j==c||j==m||k==c||k==m)
            {
                k = randomico(1, 6);
                j = randomico(1, 6);
                c = randomico(1, 6);
                m = randomico(1, 6);
            }

            senhaCores.push_back(k);
            senhaCores.push_back(j);
            senhaCores.push_back(c);
            senhaCores.push_back(m);

            srand(time(0));
            random_shuffle(senhaCores.begin(), senhaCores.end());
            limparTela();
            bool vitoriaOuMorte = jogo(senhaCores, voltarMenu);

            if(vitoriaOuMorte == 1)
            {
                vitoria();
                break;
            }
            else
            {
                fracasso();
                gotoXY(20, 20);
                mudaCor(RED);

                bool tentarDNV = readBool("Deseja voltar ao menu? (1 - sim, 0 - nao) ");

                if(tentarDNV == 0)
                {
                    break;
                }
                else
                {
                    limpaEfeito();
                    limparTela();
                    opcao = 1;
                }
            }
        }
        else if(opcao == 2)
        {
            return 0;
        }
        else if(opcao == 3)
        {
            limparTela();
            regras.imprime();
            mudaCor(GREEN);
            cout << "Bem vindo a senha!" << endl;
            cout << "\nObjetivo -> Adivinhar uma senha de cores com ordem, em 10 tentativas.";
            cout << "\nCaso você insira uma cor certa, porém no local errado, imprime um pino branco.";
            cout << "\nCaso a cor certa esteja no local certo, imprime um pino cinza.";
            cout << "\nCaso você erre a cor e um lugar, não são imprimidos pinos.";
            cout << "\nA relação completa de cores está disponível na tela." << endl;
            cout << "\nBoa sorte!" << endl;
            limpaEfeito();

            bool voltar = readBool("\nDigite 1 para voltar ao menu.");

            while(voltar != 1)
            {
                voltar = readBool("\nDigite 1 para voltar ao menu.");
                opcao = 1;
            }

            opcao = 1;
            limparTela();
        }
    }
}
