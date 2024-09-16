// Pedra, Papel ou Tesoura
// Rock, Paper or Scissors

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


int VerificarJogadas(char jogada[], char jogadaCPU[])
{

    if (strcmp(jogada, "papel") == 0 && strcmp(jogadaCPU, "pedra") == 0)
    {
        printf("Você ganhou!");
        printf("\n%s", jogadaCPU);
        return 0;
    }
    else if (strcmp(jogada, "pedra") == 0 && strcmp(jogadaCPU, "tesoura") == 0)
    {
        printf("Você ganhou!");
        printf("\n%s", jogadaCPU);
        return 0;
    }
    else if (strcmp(jogada, "tesoura") == 0 && strcmp(jogadaCPU, "papel") == 0)
    {
        printf("Você ganhou!");
        printf("\n%s", jogadaCPU);
        return 0;
    }

    if (strcmp(jogadaCPU, "papel") == 0 && strcmp(jogada, "pedra") == 0)
    {
        printf("Você perdeu!");
        printf("\n%s", jogadaCPU);
        return 1;
    }
    else if (strcmp(jogadaCPU, "pedra") == 0 && strcmp(jogada, "tesoura") == 0)
    {
        printf("Você perdeu!");
        printf("\n%s", jogadaCPU);
        return 1;
    }
    else if (strcmp(jogadaCPU, "tesoura") == 0 && strcmp(jogada, "papel") == 0)
    {
        printf("Você perdeu!");
        printf("\n%s", jogadaCPU);
        return 1;
    }
    
    printf("\nA CPU jogou %s!\n", jogadaCPU);

    return 2;
}

int main()
{
    char *jogo[] = {"pedra", "papel", "tesoura"}, jogada[8] = {" "}, jogadaCPU[8];
    srand(time(NULL));
    int max = 3, min = 0, op = 0;

    while (op != 1)
    {
        int random = rand() % (max - min) + min;
        strcpy(jogadaCPU, jogo[random]);
        int endGame = VerificarJogadas(jogada, jogadaCPU);

        if (endGame == 1 || endGame == 0)
        {
            printf("\nVocê deseja continuar jogando?\n");
            scanf("%i", &op);
        }

        if (strcmp(jogada, "papel") == 0 || strcmp(jogada, "tesoura") == 0 || strcmp(jogada, "pedra") == 0 || strcmp(jogada, " ") == 0)
        {
            printf("Insira sua jogada\n");
            scanf("%s", jogada);
        }
        else
        {
            printf("\nJogada Inválida. Tente novamente.\n");
            printf("\nInsira sua jogada\n");
            scanf("%s", jogada);
        }
    }

    return 0;
}