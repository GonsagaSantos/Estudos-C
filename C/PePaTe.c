// Pedra, Papel ou Tesoura
// Rock, Paper or Scissors

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


int main()
{
    int decisionTable[9][3] = { // Tesoura = 1, Papel = 2, Pedra = 3, Empate = 0
        1, 1, 0,
        1, 2, 1,
        1, 3, 3,
        2, 1, 1,
        2, 2, 0,
        2, 3, 2,
        3, 1, 3,
        3, 2, 2,
        3, 3, 0,
    };
    
    char jogadas[4][8] = {
        "empate",
        "tesoura",
        "papel",
        "pedra",
    };
    
    int i = 0, x = 0;
    char jogada[8];
    int jogadaNumeral;
    
    printf("\nQual a sua jogada?\n");
    scanf("%s", jogada);
    
    srand(time(NULL));
    int max = 3, min = 1, jogadaCPU = rand() % (max - min + 1) + min;
    
    if(strcmp(jogada, "tesoura") == 0) {
        jogadaNumeral = 1;
    }
    if(strcmp(jogada, "papel") == 0) {
        jogadaNumeral = 2;
    }
    if(strcmp(jogada, "pedra") == 0) {
        jogadaNumeral = 3;
    }
    if(strcmp(jogada, "pedra") != 0 && strcmp(jogada, "papel") != 0 && strcmp(jogada, "tesoura") != 0) {
        printf("\nJogada invalida.");
        return 1;
    }
    
    for(i = 0; i < 9; i++){
  
        if(decisionTable[i][0] == jogadaNumeral && decisionTable[i][1] == jogadaCPU) {
            int resultado = decisionTable[i][2];
            printf("\nSua jogada: %s\nCPU: %s\nResultado: %s\n", jogadas[jogadaNumeral], jogadas[jogadaCPU], jogadas[resultado]);
            
            if(decisionTable[i][2] == jogadaNumeral) {
                printf("\nParabens. Voce ganhou!");
            }
            if(decisionTable[i][2] == jogadaCPU) {
                printf("\nVoce perdeu!");
            }
            if(decisionTable[i][2] == 0) {
                printf("\nEmpate. Jogue novamente!");
            }
            
        }
        
    }
    
    return 0;
}