#ifndef fase4_h
#define fase4_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int fase4() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int nums[100] = {0}; // Array para armazenar números
    int count = 1; // Para rastrear o número de entradas
    int escolha, quant, quantpc, num;

    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    nums[0] = 0; // Começa a lista com 0

    // Escolha inicial do jogador
    printf("FASE4: limite de 35 numeros.\n");
    printf("> ESCOLHA: quer começar em primeiro[1] ou segundo[2]?\n");
    printf("1 ou 2: ");
    scanf("%d", &escolha);

    while (count < 35) {
        if (escolha == 1) {
            do
            {
                
            printf("Escreva a quantidade de números que deseja digitar, máximo 4: ");
            scanf("%d", &quant);

            if (quant>4||quant<1)
            {
                printf("Insira um valor valido, de 1 a 4.\n");
            }
            

            } while (quant>4||quant<1);

            for (int c = 0; c < quant; c++) {

                int next_num = nums[count - 1] + 1;
                nums[count++] = next_num;

                if (nums[count - 1] == 21) {
                    printf("PERDEU!\n");
                    return 0;
                }

                if (c == quant - 1) {
                    printf("Números adicionados: ");
                    for (int i = 0; i < count; i++) {
                        printf("%d ", nums[i]);
                    }
                    printf("\n");
                }
            }

            // Jogada do computador
            quantpc = rand() % 4 + 1; // Gera quantidade aleatória de 1 a 4
            int next_num = nums[count - 1] + 1; // Próximo número a ser adicionado

            for (int c = 0; c < quantpc; c++) {
                nums[count++] = next_num++;
                if (nums[count - 1] == 35) {
                    printf("GANHOU!\n");
                    return 1;
                }
            }

            printf("Números adicionados pelo computador: ");
            for (int i = 0; i < count; i++) {
                printf("%d ", nums[i]);
            }
            printf("\n");

        } else if (escolha == 2) {
            // Jogada do computador antes do jogador
            quantpc = rand() % 4 + 1; // Gera quantidade aleatória de 1 a 4
            int next_num = nums[count - 1] + 1; // Próximo número a ser adicionado

            for (int c = 0; c < quantpc; c++) {
                nums[count++] = next_num++;
                if (nums[count - 1] == 35) {
                    printf("GANHOU!\n");
                    return 1;
                }
            }

            printf("Números adicionados pelo computador: ");
            for (int i = 0; i < count; i++) {
                printf("%d ", nums[i]);
            }
            printf("\n");

            // Jogada do jogador
            do
            {
                
            printf("Escreva a quantidade de números que deseja digitar, máximo 4: ");
            scanf("%d", &quant);

            if (quant>4||quant<1)
            {
                printf("Insira um valor valido, de 1 a 4.\n");
            }
            

            } while (quant>4||quant<1);

            for (int c = 0; c < quant; c++) {

                int next_num = nums[count - 1] + 1;
                nums[count++] = next_num;

                if (nums[count - 1] == 35) {
                    printf("PERDEU!\n");
                    return 0;
                }

                if (c == quant - 1) {
                    printf("Números adicionados: ");
                    for (int i = 0; i < count; i++) {
                        printf("%d ", nums[i]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 1;
}

#endif 