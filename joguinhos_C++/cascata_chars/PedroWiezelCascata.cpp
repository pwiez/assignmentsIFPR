//9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999

#include "biblaureano.h"

bool centralizadoraDeVaporizacao(string frasees, int y, int c, int qtdCarac);

bool centralizadoraDeVaporizacao(string frasees, int y, int c, int qtdCarac)
{
    limparTela();
    int qtd = 40;
    int posicaoDeVaporizacao = ((80 - frasees.length())/2 - 1);
    gotoXY(posicaoDeVaporizacao, 1);
    cout << frasees;

    do
    {
        if(y <= 20)
        {
            y++;
            gotoXY(posicaoDeVaporizacao, y);
            cout<<frasees[c];
            espera(7);
            gotoXY(posicaoDeVaporizacao, y-1);
            cout << " ";
            int cor = randomico(1, 255);
            mudaCor255(cor);
        }
        else if(y > 20)
        {
            posicaoDeVaporizacao++;
            y = 1;
            c++;
        }

    }
    while(c < qtdCarac);

    y = 19;
    c = 0;
    posicaoDeVaporizacao = ((80 - frasees.length())/2 - 1);

    do
    {
        if(y >= 5)
        {
            gotoXY(posicaoDeVaporizacao, y+1);
            cout << " ";
            y--;
            gotoXY(posicaoDeVaporizacao, y);
            cout<<frasees[c];
            espera(7);
            int cor = randomico(1, 255);
            mudaCor255(cor, 0);

        }
        else if(y < 5)
        {
            posicaoDeVaporizacao++;
            y = 20;
            c++;

        }

    }
    while(c < qtdCarac);

}


int main()
{
    string frasees = readString("Frase: ");
    int qtdCarac = frasees.size();
    int y = 1;
    int c = 0;
    centralizadoraDeVaporizacao(frasees, y, c, qtdCarac);
}

















