#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[3];
    int valor;
} As;

typedef struct {
    char nome[7];
    int valor;
} Cartas;

void inicializar_cartas(Cartas baralho[]) {
    const char *nome[] = {"Um", "Dois", "Tres", "Quatro", "Dez", "Valete", "Dama", "Rei"};
    int valor[] = {1, 2, 3, 4, 10, 10, 10, 10};
    
    for(int i = 0; i < 8; i++){
        strcpy(baralho[i].nome, nome[i]);
        baralho[i].valor = valor[i];
    }
}

int main() {
    As as;
    Cartas baralho [8];
    inicializar_cartas(baralho);
    
    strcpy(as.nome, "As");
    srand(time(NULL));
    int index = rand() % 8;
    
    if(baralho[index].valor == 10) {
        as.valor = 1;
    }
    else {
        as. valor = 11;
    }
    
    printf("\nValor do As: %i", as.valor);
    printf("\nValor da carta %7s: %i", baralho[index].nome, baralho[index].valor);
    
    return 0;
    
}

//Testando alternativas pra mudar o valor do As dinamicamente