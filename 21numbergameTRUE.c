#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAM 256

typedef struct {
    char player_nome[100];
    char resultado[100];
    int pontos;
} player;

void colher(const char *nome, const char *modo, const player *p) { 
    FILE *temp;
    temp = fopen(nome, modo);
    if (temp == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    printf("Salvando %s, %d pontos, resultado:%s\n", p->player_nome, p->pontos,p->resultado);
    fwrite(p->player_nome, sizeof(char), 100, temp);
    fwrite(&p->pontos, sizeof(int), 1, temp);
    fclose(temp);
}

void exibir(char *nome_arq) {
    FILE *temp;
    player *jog = malloc(sizeof(player));
    temp = fopen(nome_arq, "rb");
    if (temp == NULL) {
        printf("Erro ao exibir arquivo.\n");
        return;
    }
    fread(jog->player_nome, sizeof(char), 100, temp);
    fread(&jog->pontos, sizeof(int), 1, temp);
    printf("%s, %d pontos\n", jog->player_nome, jog->pontos);
    fclose(temp);
}


int ler_fase(const char *arquivo_nome, int limite) {
    FILE *arquivo = fopen(arquivo_nome, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0; 
    }

    char regra[100];
    int fase_limite;
    fscanf(arquivo, "Regras: %99[^\n]\n", regra); 
    fscanf(arquivo, "Limite de numeros: %d\n", &fase_limite); 

    printf("Regras da fase: %s\n", regra);
    printf("Limite de numeros para esta fase: %d\n", fase_limite);

    fclose(arquivo);

    int num_atual = 1;
    int turno = 0;

    while (num_atual < limite) {
        printf("\nA sequencia atual vai ate %d.\n", num_atual);

        if (turno == 0) { 
            int qtd;

            printf("Quantos numeros voce deseja jogar (1 a 4)? ");
            scanf("%d", &qtd);

            if (qtd < 1 || qtd > 4) {
                printf("Erro! Voce deve escolher entre 1 e 4 numeros.\n");
                continue;
            }

            printf("Voce escolheu os numeros: ");
            int i;
            for (i = 0; i < qtd; i++) {
                num_atual++;
                printf("%d ", num_atual);

                if (num_atual == limite) {
                    printf("\nVoce falou %d, perdeu!\n", limite);
                    return 0; 
                }
            }
            printf("\n");

        } else { 
            srand(time(NULL));
            int qtd = (rand() % 4) + 1; 

            printf("A maquina escolheu %d numeros: ", qtd);
            int i;
            for (i = 0; i < qtd; i++) {
                num_atual++;
                printf("%d ", num_atual);

                if (num_atual == limite) {
                    printf("\nA maquina falou %d, perdeu!\n", limite);
                    return 1; 
                }
            }
            printf("\n");
        }

        turno = 1 - turno; 
    }

    printf("Voce completou a fase com sucesso!\n");
    return 1; 
}

int main() {
    player players[100];
    int start = 1, denovo = 0, i = 0;

    printf("Jogo de 21.\nFuncionamento: o primeiro que digitar o numero limite da fase, perde.\n");
    printf("Regras:\n 1) Comeca a partir do 1 e nao vale digitar 0 numeros;\n 2) Nao vale repetir numeros;\n 3) So vale digitar ate 4 numeros de uma vez.\n 5) A cada fase, o limite de numeros aumenta em 5\n");

    do {
        do {
            printf("\nDeseja jogar[0] ou ver as pontuacoes dos jogadores?[1]: ");
            scanf("%d", &start);

            if (start == 1) {
                exibir("estatisticas.dat");
            }
        } while (start != 0);

        printf("Escreva o seu nickgame:\n");
        scanf("%s", players[i].player_nome);

        if (ler_fase("fase1.txt", 21) == 0) {
            snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
            players[i].pontos = 0;
        } else {
        	snprintf(players[i].resultado, sizeof(players[i].resultado), "VITORIA!!");
            players[i].pontos += 10;
        }
        colher("estatisticas.dat", "ab", &players[i]);

        if (ler_fase("fase2.txt", 25) == 0) {
            snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
        } else {
        	snprintf(players[i].resultado, sizeof(players[i].resultado), "VITORIA!!");
            players[i].pontos += 10;
        }
        colher("estatisticas.dat", "ab", &players[i]);

        if (ler_fase("fase3.txt", 30) == 0) {
            snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
        } else {
        	snprintf(players[i].resultado, sizeof(players[i].resultado), "VITORIA!!");
            players[i].pontos += 10;
        }
        colher("estatisticas.dat", "ab", &players[i]);

        if (ler_fase("fase4.txt", 35) == 0) {
            snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
        } else {
        	snprintf(players[i].resultado, sizeof(players[i].resultado), "VITORIA!!");
            players[i].pontos += 10;
        }
        colher("estatisticas.dat", "ab", &players[i]);

        if (ler_fase("fase5.txt", 40) == 0) {
            snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
        } else {
        	snprintf(players[i].resultado, sizeof(players[i].resultado), "VITORIA!!");
            players[i].pontos += 10;
        }
        colher("estatisticas.dat", "ab", &players[i]);

        printf("Deseja jogar de novo? Digite 0 para recomecar: ");
        scanf("%d", &denovo);

    } while (denovo == 0);

    printf("Jogo finalizado.\n");
    return 0;
}
