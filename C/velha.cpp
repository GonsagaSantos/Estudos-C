#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char nome[6];
    int vitorias;
} Jogador;

// Função para verificar o vencedor
int check_winner(char jogo_da_velha[3][3]) {
    // Verifica linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (jogo_da_velha[i][0] == jogo_da_velha[i][1] && jogo_da_velha[i][1] == jogo_da_velha[i][2] && jogo_da_velha[i][0] != ' ') {
            return (jogo_da_velha[i][0] == 'X') ? 1 : -1;
        }
        if (jogo_da_velha[0][i] == jogo_da_velha[1][i] && jogo_da_velha[1][i] == jogo_da_velha[2][i] && jogo_da_velha[0][i] != ' ') {
            return (jogo_da_velha[0][i] == 'X') ? 1 : -1;
        }
    }
    // Verifica diagonais
    if (jogo_da_velha[0][0] == jogo_da_velha[1][1] && jogo_da_velha[1][1] == jogo_da_velha[2][2] && jogo_da_velha[0][0] != ' ') {
        return (jogo_da_velha[0][0] == 'X') ? 1 : -1;
    }
    if (jogo_da_velha[0][2] == jogo_da_velha[1][1] && jogo_da_velha[1][1] == jogo_da_velha[2][0] && jogo_da_velha[0][2] != ' ') {
        return (jogo_da_velha[0][2] == 'X') ? 1 : -1;
    }
    // Nenhum vencedor
    return 0;
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(char jogo_da_velha[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", jogo_da_velha[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
}

// Função para atualizar o placar no arquivo
void atualizar_placar(Jogador jogadores[], int num_jogadores) {
    FILE *arquivo = fopen("placar.txt", "r+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Ler o conteúdo do arquivo
    char linha[100];
    bool encontrou[2] = {false, false};

    // Atualizar o placar no arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        for (int i = 0; i < num_jogadores; i++) {
            if (strstr(linha, jogadores[i].nome)) {
                fseek(arquivo, -strlen(linha), SEEK_CUR);
                fprintf(arquivo, "%-10s %d\n", jogadores[i].nome, jogadores[i].vitorias);
                encontrou[i] = true;
            }
        }
    }

    // Adicionar novas entradas se não forem encontradas
    for (int i = 0; i < num_jogadores; i++) {
        if (!encontrou[i]) {
            fprintf(arquivo, "%-10s %d\n", jogadores[i].nome, jogadores[i].vitorias);
        }
    }

    fclose(arquivo);
}

// Função para exibir o placar no console
void exibir_placar() {
    FILE *arquivo = fopen("placar.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
}

int main() {
    Jogador jogadores[2] = {{"", 0}, {"", 0}};
    int randNumber_row, randNumber_column, op = 0;
    int position_row = 0, position_column = 0;
    bool endGame;
    char jogar_novamente;

    srand(time(NULL));

    do {
        // Solicita os nomes dos jogadores
        printf("[MENU]\n\nSelecione a modalidade de jogo.\n1. Jogador VS CPU\n2. Jogador VS Jogador\n3. Exibir Placar\n4. Sair\n> ");
        scanf("%i", &op);

        if (op == 1) {
            printf("\nQual o nome do jogador? (Max. 5 letras)\n> ");
            scanf("%5s", jogadores[0].nome);
            strcpy(jogadores[1].nome, "CPU");
        } else if (op == 2) {
            printf("\nQual o nome dos jogadores? (Max. 5 letras)\n> ");
            scanf("%5s %5s", jogadores[0].nome, jogadores[1].nome);
        }

        do {
            char jogo_da_velha[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
            endGame = false;

            switch (op) {
            case 1:
                while (!endGame) {
                    printf("Insira a posição da jogada (Linha e Coluna): ");
                    scanf("%i %i", &position_row, &position_column);

                    if (jogo_da_velha[position_row][position_column] == ' ') {
                        jogo_da_velha[position_row][position_column] = 'X';
                    } else {
                        printf("Essa posição já foi preenchida. Escolha outra posição.\n");
                        continue;
                    }

                    if (check_winner(jogo_da_velha) == 1) {
                        printf("\nFim de jogo. Vitória do jogador %s.\n", jogadores[0].nome);
                        jogadores[0].vitorias++;
                        endGame = true;
                    } else {
                        exibir_tabuleiro(jogo_da_velha);
                        printf("\nVez do computador.\n");

                        do {
                            randNumber_row = rand() % 3;
                            randNumber_column = rand() % 3;
                        } while (jogo_da_velha[randNumber_row][randNumber_column] != ' ');

                        jogo_da_velha[randNumber_row][randNumber_column] = 'O';

                        if (check_winner(jogo_da_velha) == -1) {
                            printf("\nFim de jogo. Vitória do computador.\n");
                            jogadores[1].vitorias++;
                            endGame = true;
                        } else {
                            exibir_tabuleiro(jogo_da_velha);
                        }
                    }
                }
                break;

            case 2:
                while (!endGame) {
                    printf("Jogador 1: Insira a posição da jogada (Linha e Coluna): ");
                    scanf("%i %i", &position_row, &position_column);

                    if (jogo_da_velha[position_row][position_column] == ' ') {
                        jogo_da_velha[position_row][position_column] = 'X';
                    } else {
                        printf("Essa posição já foi escolhida. Escolha outra posição.\n");
                        continue;
                    }

                    if (check_winner(jogo_da_velha) == 1) {
                        printf("\nFim de jogo. Vitória do jogador %s.\n", jogadores[0].nome);
                        jogadores[0].vitorias++;
                        endGame = true;
                    } else {
                        exibir_tabuleiro(jogo_da_velha);
                        printf("Jogador 2: Insira a posição da jogada (Linha e Coluna): ");
                        scanf("%i %i", &position_row, &position_column);

                        if (jogo_da_velha[position_row][position_column] == ' ') {
                            jogo_da_velha[position_row][position_column] = 'O';
                        } else {
                            printf("Essa posição já foi escolhida. Escolha outra posição.\n");
                            continue;
                        }

                        if (check_winner(jogo_da_velha) == -1) {
                            printf("\nFim de jogo. Vitória do jogador %s.\n", jogadores[1].nome);
                            jogadores[1].vitorias++;
                            endGame = true;
                        } else {
                            exibir_tabuleiro(jogo_da_velha);
                        }
                    }
                }
                break;

            case 3:
                exibir_placar();
                break;

            case 4:
                break;

            default:
                printf("Opção inválida.\n");
            }

            if (op != 3) {
                printf("Deseja jogar novamente? (s/n): ");
                scanf(" %c", &jogar_novamente);

                if (jogar_novamente == 's' || jogar_novamente == 'S') {
                    // Atualizar o placar antes de reiniciar o jogo
                    atualizar_placar(jogadores, 2);
                }
            }

        } while (jogar_novamente == 's' || jogar_novamente == 'S');

    } while (op != 4);

    return 0;
}
