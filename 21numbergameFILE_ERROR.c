#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct {
    char player_nome[100], resultado[100];
    int pontos;
} player;

int ler_fase(const char *arquivo_nome, int limite)
{
    // Tentando abrir o arquivo em modo de leitura de texto ("r")
    FILE *arquivo = fopen(arquivo_nome, "r");
    
    if (arquivo == NULL) {
        // Erro ao abrir o arquivo, exibe o caminho do arquivo tentando ser aberto
        perror("Erro ao abrir o arquivo");
        printf("Certifique-se de que o arquivo '%s' exista e esteja no diretório correto.\n", arquivo_nome);
        return 0; // Retorna 0 em caso de erro
    }

    char regra[100];
    int fase_limite;
    // Lê as regras e o limite de números da fase
    fscanf(arquivo, "Regras: %99[^\n]\n", regra); 
    fscanf(arquivo, "Limite de números: %d\n", &fase_limite); 

    // Exibe as regras e o limite de números
    printf("Regras da fase: %s\n", regra);
    printf("Limite de números para esta fase: %d\n", fase_limite);

    fclose(arquivo); // Fecha o arquivo após leitura

    int num_atual = 1;
    // Loop principal do jogo até o limite da fase
    while (num_atual <= limite) {
        printf("A sequência atual vai até %d. Você deve inserir de 1 a 4 números seguintes.\n", num_atual);
        int nums[4], qtd = 0;

        printf("Digite entre 1 e 4 números:\n");
        while (qtd < 4) {
            printf("Digite o próximo número (sequencial após %d): ", num_atual);
            scanf("%d", &nums[qtd]);

            if (nums[qtd] == num_atual + 1) {
                num_atual = nums[qtd];
                qtd++;
            } else {
                printf("Erro! Você deve inserir o próximo número da sequência.\n");
                continue;
            }
            if (num_atual == limite) {
                printf("Você falou %d, perdeu!\n", limite);
                return 0; // Jogador perdeu
            }
        }
    }

    printf("Você completou a fase com sucesso!\n");
    return 1; // Jogador venceu a fase
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    player players[100];
    int start = 1, denovo = 0, i = 0;

    printf("Jogo de 21. Funcionamento: o primeiro que digitar o número limite da fase, perde.\n");
    printf("Regras:\n 1) Começa a partir do 1 e não vale digitar 0 números;\n 2) Não vale repetir números;\n 3) Só vale digitar até 4 números de uma vez.\n 5) A cada fase, o limite de números aumenta em 5\n");

    do {
        do {
            printf("\nDeseja jogar[0] ou ver as pontuações dos jogadores?[1]: ");
            scanf("%d", &start);

            if (start == 1) {
                for (size_t j = 0; j < i; j++) {
                    printf("Jogador: %s.\t Pontos: %d.\t Resultado: %s.\n", players[j].player_nome, players[j].pontos, players[j].resultado);
                }
            }
        } while (start != 0);

        // Leitura do nome do jogador
        printf("Escreva o seu nickgame:\n");
        scanf("%s", players[i].player_nome);

        // Inicialização do jogador com 0 pontos e resultado indefinido
        players[i].pontos = 0;
        snprintf(players[i].resultado, sizeof(players[i].resultado), "JOGANDO");

        // Jogar as fases, caso o jogador perca, ele não avança
        if (ler_fase("fase1.txt", 21) == 0) {
            snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
            printf("Você perdeu! Fim do jogo para %s.\n", players[i].player_nome);
            i++; // O jogador é adicionado apenas após uma derrota ou vitória
            continue; // Volta para o menu de início
        } else {
            players[i].pontos += 10; // Adiciona pontos ao vencer a fase
        }

        if (ler_fase("fase2.txt", 25) == 0) {
            snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
            printf("Você perdeu! Fim do jogo para %s.\n", players[i].player_nome);
            i++; // Adiciona jogador apenas se perder ou terminar
            continue;
        } else {
            players[i].pontos += 10;
        }

        if (ler_fase("fase3.txt", 30) == 0) {
            snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
            printf("Você perdeu! Fim do jogo para %s.\n", players[i].player_nome);
            i++; 
            continue;
        } else {
            players[i].pontos += 10;
        }

        if (ler_fase("fase4.txt", 35) == 0) {
            snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
            printf("Você perdeu! Fim do jogo para %s.\n", players[i].player_nome);
            i++; 
            continue;
        } else {
            players[i].pontos += 10;
        }

        if (ler_fase("fase5.txt", 40) == 0) {
            snprintf(players[i].resultado, sizeof(players[i].resultado), "DERROTA!");
            printf("Você perdeu! Fim do jogo para %s.\n", players[i].player_nome);
            i++; 
            continue;
        } else {
            players[i].pontos += 10;
            snprintf(players[i].resultado, sizeof(players[i].resultado), "VITÓRIA!");
            printf("Parabéns, %s! Você completou todas as fases e venceu o jogo!\n", players[i].player_nome);
        }

        // Incrementa o índice de jogadores somente após terminar o jogo
        i++;

        printf("Deseja jogar de novo? Digite 0 para recomecar ou outro número para sair:");
        scanf("%d", &denovo);

    } while (denovo == 0);

    printf("Jogo finalizado.\n");

    return 0;
}