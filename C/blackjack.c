#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição da estrutura Carta
typedef struct {
    char nome[10];
    char naipe[9];
    int valor;
} Carta;

// Função para inicializar o baralho
void inicializarBaralho(Carta baralho[]) {
    const char *nome[] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
    const char *naipe[] = {"Copas", "Espadas", "Ouros", "Paus"};
    int valor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            strcpy(baralho[index].nome, nome[j]);
            strcpy(baralho[index].naipe, naipe[i]);
            baralho[index].valor = valor[j];
            index++;
        }
    }
}

// Função para embaralhar o baralho usando Fisher-Yates
void embaralhamento(Carta baralho[], int n) {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com a hora atual

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Gera um índice aleatório de 0 a i
        // Troca a carta i com a carta j
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

int main() {
    Carta baralho[52];
    inicializarBaralho(baralho);
    embaralhamento(baralho, 52);
    embaralhamento(baralho, 52);

    // Exibe as duas primeiras cartas embaralhadas
    for (int i = 0; i < 2; i++) {
        printf("Sua carta %i é %10s de %9s, %i\n", i + 1, baralho[i].nome, baralho[i].naipe, baralho[i].valor); 
    }

    return 0;
}
