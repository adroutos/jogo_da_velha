#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 3

void jogar(char tabuleiro[MAX][MAX],char sorteado);
char sorteia_letra(void);
void printa_tabuleiro(char tabuleiro[MAX][MAX]);

int main(void)
{
    char tabuleiro[MAX][MAX] = {{'L','L','L'},
        {'L','L','L'},
        {'L','L','L'}}; // coluna x linha
    
    char letra_inicial;
    int resp;

    srand(time(NULL));

    printa_tabuleiro(tabuleiro);

    letra_inicial = sorteia_letra();
    printf(" decidam-se quem vai ser o 'x' e quem vai ser o 'o'!\n");
    printf(" Quando estiverem prontos digite 1\n");
    scanf("%d",&resp);

    if(resp == 1)
    {
        printf(" sorteado pra começar primeiro o jogador da letra %c\n",letra_inicial);
        jogar(tabuleiro, letra_inicial);
    }
}
void jogar(char tabuleiro[MAX][MAX], char sorteado)
{
    int nao_acabou = 1;
    int lix,colx,lio,colo;
    char nao_sorteado;
    int i = 0;
    if(sorteado == 'x')
        nao_sorteado = 'o';
    else
        nao_sorteado = 'x';

    while(i < 5)
    {
        printf(" Digite a linha jogador %c: \n",sorteado);
        scanf(" %d",&lix);
        printf(" Digite a coluna jogador %c: \n",sorteado);
        scanf(" %d",&colx);
        tabuleiro[lix][colx] = sorteado;

        printa_tabuleiro(tabuleiro);

        printf(" Digite a linha jogador %c: \n",nao_sorteado);
        scanf(" %d",&lio);
        printf(" Digite a coluna jogador %c: \n",nao_sorteado);
        scanf(" %d",&colo);
        tabuleiro[lio][colo] = nao_sorteado;
        printa_tabuleiro(tabuleiro);

        i++;
    }
}
void printa_tabuleiro(char tabuleiro[MAX][MAX])
{
    for(int i = 0;i < MAX;i++)
    {
        for(int j  =0;j < MAX;j++)
        {
            printf(" %c",tabuleiro[i][j]);
        }
        printf("\n");
    }

}
char sorteia_letra(void)
{
    int num = rand()%2;

    if(num == 1)
        return 'x';
    else
        return 'o';
}
