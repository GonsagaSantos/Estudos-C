#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int check_winner(char jogo_da_velha[3][3]) {
    
    for (int i = 0; i < 3; i++) {
        if (jogo_da_velha[i][0] == jogo_da_velha[i][1] && jogo_da_velha[i][1] == jogo_da_velha[i][2] && jogo_da_velha[i][0] != ' ') {
            return (jogo_da_velha[i][0] == 'X') ? 1 : -1;
        }
        if (jogo_da_velha[0][i] == jogo_da_velha[1][i] && jogo_da_velha[1][i] == jogo_da_velha[2][i] && jogo_da_velha[0][i] != ' ') {
            return (jogo_da_velha[0][i] == 'X') ? 1 : -1;
        }
    }
    
    if (jogo_da_velha[0][0] == jogo_da_velha[1][1] && jogo_da_velha[1][1] == jogo_da_velha[2][2] && jogo_da_velha[0][0] != ' ') {
        return (jogo_da_velha[0][0] == 'X') ? 1 : -1;
    }
    if (jogo_da_velha[0][2] == jogo_da_velha[1][1] && jogo_da_velha[1][1] == jogo_da_velha[2][0] && jogo_da_velha[0][2] != ' ') {
        return (jogo_da_velha[0][2] == 'X') ? 1 : -1;
    }

    return 0;
}

int main() {
    char jogo_da_velha[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}, jogadores[10][6] = {' '}; 
    int randNumber_row, randNumber_column, op = 0, vitorias = 0;
    int position_row = 0, position_column = 0;
    bool endGame = false;

    srand(time(NULL)); 

    printf("[MENU]\n\nSelecione a modalidade de jogo.\n1. Jogador VS CPU\n2. Jogador VS Jogador\n3. Sair\n> ");
    scanf("%i", &op);

    if (op == 1) {
        printf("\nQual o nome do jogador? (Max. 5 letras)\n> ");
        scanf("%5s", jogadores[0]);
    }

    if (op == 2) {
        printf("\nQual o nome dos jogadores? (Max. 5 letras)\n> ");
        scanf("%5s\n%5s", jogadores[0], jogadores[1]);
    }

    switch (op)
    {
    case 1:

        while (!endGame) {
        
            printf("Insira a posição da jogada(Linha e Coluna): ");
            scanf("%i %i", &position_row, &position_column);

            if (jogo_da_velha[position_row][position_column] == ' ') {
                jogo_da_velha[position_row][position_column] = 'X';
            } else {
                printf("Essa posição já foi preenchida. Escolha outra posição.\n");
                continue;
            }

            if (check_winner(jogo_da_velha) == 1) {
                printf("\nFim de jogo. Vitória do jogador %5s.\n", jogadores[0]);
                break;
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf(" %c ", jogo_da_velha[i][j]);
                    if (j < 2) printf("|");
                }
                printf("\n");
                if (i < 2) printf("---|---|---\n");
            }

            
            printf("\nVez do computador.\n");

            do {
                randNumber_row = rand() % 3;
                randNumber_column = rand() % 3;
            } while (jogo_da_velha[randNumber_row][randNumber_column] != ' ');

            jogo_da_velha[randNumber_row][randNumber_column] = 'O';

        
            if (check_winner(jogo_da_velha) == -1) {
                printf("\nFim de jogo. Vitória do computador.\n");
                break;
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf(" %c ", jogo_da_velha[i][j]);
                    if (j < 2) printf("|");
                }
                printf("\n");
                if (i < 2) printf("---|---|---\n");
            }
        }
    break;
    
    case 2:

        while (!endGame) {
        
            printf("Insira a posição da jogada (Linha e Coluna): ");
            scanf("%i %i", &position_row, &position_column);

            if (jogo_da_velha[position_row][position_column] == ' ') {
                jogo_da_velha[position_row][position_column] = 'X';
            } else {
                printf("Essa posição já foi escolhida. Escolha outra posição.\n");
                continue;
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf(" %c ", jogo_da_velha[i][j]);
                    if (j < 2) printf("|");
                }
                printf("\n");
                if (i < 2) printf("---|---|---\n");
            }

            if (check_winner(jogo_da_velha) == 1) {
                printf("\nFim de jogo. Vitória do jogador %5s.\n", jogadores[0]);
                break;
            }

            
            printf("\nVez do jogador 2\n");

            printf("Insira a posição da jogada (Linha e Coluna) : ");
            scanf("%i %i", &position_row, &position_column);

            if (jogo_da_velha[position_row][position_column] == ' ') {
                jogo_da_velha[position_row][position_column] = 'O';
            } else {
                printf("Essa posição já foi escolhida. Escolha outra posição.\n");
                continue;
            }

            if (check_winner(jogo_da_velha) == -1) {
                printf("\nFim de jogo. Vitória do jogador %5s.\n", jogadores[1]);
                break;
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf(" %c ", jogo_da_velha[i][j]);
                    if (j < 2) printf("|");
                }
                printf("\n");
                if (i < 2) printf("---|---|---\n");
            }
        }

    break;

    case 3:

        return 0;

    break;

    default:

    break;
    }
}
