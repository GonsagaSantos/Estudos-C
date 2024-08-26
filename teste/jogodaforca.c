#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define NUM_WORDS 30
#define MAX_LENGTH 20 

const char* palavras_aleatorias[NUM_WORDS] = {
    "amarelo", "balança", "cachorro", "destino", "elefante",
    "florido", "guitarra", "horizonte", "inverno", "jacaré",
    "kiwi", "lagoa", "montanha", "navio", "oceano",
    "papel", "quadro", "rato", "sombra", "tigre",
    "uva", "vaca", "wolverine", "xaxim", "yoga",
    "zebra", "abacaxi", "coração", "deserto", "estrela"
};

void desenha_forca(int forca) {
    printf("\n");
    printf("  _______\n");
    printf(" |       |\n");

    if (forca >= 1) {
        printf(" |       O\n");
    } else {
        printf(" |       \n");
    }

    if (forca >= 2) {
        printf(" |       |\n");
    } else {
        printf(" |       \n");
    }

    if (forca >= 3) {
        printf(" |      /|\n");
    } else {
        printf(" |       \n");
    }

    if (forca >= 4) {
        printf(" |      /|\\\n");
    } else {
        printf(" |       \n");
    }

    if (forca >= 5) {
        printf(" |      /\n");
    } else {
        printf(" |       \n");
    }

    if (forca >= 6) {
        printf(" |      / \\\n");
    } else {
        printf(" |       \n");
    }

    printf(" |\n");
    printf("_|_\n");
    printf("\n");
}

int main() {
    char palavra[MAX_LENGTH];
    char tentativa[MAX_LENGTH];
    char jogo_atual[MAX_LENGTH];
    char dica[5] = {'d', 'i', 'c', 'a', '\0'};
    int i, forca = 0, num_letras = 0, dicas = 0, tamanho = 0;
    bool endgame = false;

    srand(time(NULL));

    int index = rand() % NUM_WORDS;
    strcpy(palavra, palavras_aleatorias[index]);

    for (i = 0; i < strlen(palavra); i++) {
        jogo_atual[i] = '_';
        
        if(palavra[i] != ' ') {
            num_letras++;
        }
    }
    jogo_atual[strlen(palavra)] = '\0';
    
    tamanho = strlen(palavra);
    
    while (!endgame) {
        printf("\nPalavra atual: %s\n", jogo_atual);
        printf("\nNúmero de letras: %i\n", num_letras);
        printf("Chute a palavra.\n> ");
        scanf("%19s", tentativa);

        if(strcmp(tentativa, dica) == 0 && dicas == 0) {
            printf("\nA primeira letra é: %c\n", palavra[0]);
            dicas++;
        }
        else if(strcmp(tentativa, dica) == 0 && dicas == 1) {
            printf("\nA última letra é: %c\n", palavra[tamanho - 1]);
            dicas++;
        }
        else if(strcmp(tentativa, dica) == 0 && dicas > 1) {
            printf("\nLimite de dicas atingido.\n");
        }

        if (strcmp(tentativa, palavra) == 0) {
            printf("\nParabéns! Você ganhou!\n");
            endgame = true;
        } 
        if (strcmp(tentativa, palavra) != 0 && strcmp(tentativa, dica) != 0){
            bool acertou = false;
            for (i = 0; i < strlen(palavra); i++) {
                if(strcmp(tentativa, dica) == 0 && dicas == 1){
                    jogo_atual[0] = palavra[0];
                }
                else if (strcmp(tentativa, dica) == 0 && dicas == 2)
                {
                    jogo_atual[tamanho - 1] = palavra[tamanho - 1];
                } 
                else if (tentativa[0] == palavra[i]) {
                    jogo_atual[i] = tentativa[0];
                    acertou = true;
                }
            }
            if (!acertou) {
                forca++;
                desenha_forca(forca);
            }

            if (strcmp(jogo_atual, palavra) == 0) {
                printf("\nParabéns! Você ganhou!\n");
                endgame = true;
            }

            if (forca >= 6) {
                printf("\nVocê perdeu! A palavra era %s\n", palavra);
                endgame = true;
            }
        }
    }

    return 0;
}
