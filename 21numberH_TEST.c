#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "21_fase1.h"
#include "21_fase2.h"
#include "21_fase3.h"
#include "21_fase4.h"
#include "21_fase5.h"

typedef struct 
{
    char player_nome[100], resultado[100];
    int pontos;

} player;


int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    player players[100];
    int start=1, denovo=0,i=0;

    printf("Jogo de 21. Funcionamento: o primeiro que digitar 21, perde.\n");
    printf("Regras:\n 1) Começa a partir do 1 e não vale digitar 0 números;\n 2) Não vale repetir números;\n 3) Só vale digitar até 4 números de uma vez.\n 5)A cada fase, o limite de numeros aumenta em 5\n");

   do
   {
    
    do
    {
        
    printf("\nDeseja jogar[0] ou ver as pontuações dos jogadores?[1]");
    scanf("%d",&start);

    if (start==1)
    {
        for (size_t j = 0; j < i; j++)
        {
            printf("Jogador: %s.\t Pontos: %d.\t Resultado: %s.\n",players[j].player_nome, players[j].pontos, players[j].resultado);
        }
        
    }
    } while (start!=0);

        printf("Escreva o seu nickgame:\n");
        scanf("%s",players[i].player_nome);   


        if (fase1() == 0) {
            printf("Você não completou a fase 1. Fim do jogo para este jogador.\n");
            snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
            i++;
            continue;
        }
        else
        {
            players[i].pontos+=10;
        }
        

        if (fase2() ==0) {
            printf("Você não completou a fase 2. Fim do jogo para este jogador.\n");
             snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
            i++;
            continue;
        }
        else
        {
            players[i].pontos+=10;
        }

        if (fase3() ==0) {
            printf("Você não completou a fase 3. Fim do jogo para este jogador.\n");
             snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
            i++;
            continue;
        }
        else
        {
            players[i].pontos+=10;
        }

        if (fase4() ==0) {
            printf("Você não completou a fase 4. Fim do jogo para este jogador.\n");
             snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
            i++;
            continue;
        }
        else
        {
            players[i].pontos+=10;
        }

        if (fase5() ==0) {
            printf("Você não completou a fase 5. Fim do jogo para este jogador.\n");
            snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
            i++;
            continue;
        }
        else
        {
            players[i].pontos+=10;
            snprintf(players[i].resultado, sizeof(players[i].resultado), "VITORIA!");
            i++;
        }

        printf("Deseja jogar de novo? Digite 0 para recomecar:");
        scanf("%d",&denovo);

    }while (denovo==0);

    printf("Jogo finalizado.");

    return 0;

   }
