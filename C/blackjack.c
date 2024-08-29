#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

// Definindo um struct, sendo que cada struct é uma carta do baralho
typedef struct {
    char nome[10];
    char naipe[9];
    int valor;
} Carta;

typedef struct {
    char nome[3];
    char naipe[9];
    int valor;
} As;

// Formando o baralho, inicializando cada struct (carta) como uma carta diferente
void inicializarBaralho(Carta baralho[], As baralho_as[]) {
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

    for(int i = 0; i < 4; i++) {
        strcpy(baralho_as->naipe, naipe[i]);
    }
}

// Função para embaralhar o baralho usando Fisher-Yates
void embaralhamento(Carta baralho[], int n) {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Gera um índice aleatório de 0 a i
        // Troca a carta i com a carta j
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

int main() {
    setlocale(LC_ALL, "");

    int i = 0 || 1;

    Carta baralho[52];
    As as[8];
    inicializarBaralho(baralho, as);
    embaralhamento(baralho, 52);

    int acumulador_jogador = 0, acumulador_dealer = 0;
    // Mostra as duas cartas do jogador
    for (int i = 0; i < 6; i++) {

        if(i < 2) {
            acumulador_jogador += baralho[i].valor;
            printf("Sua carta %i é %10s de %9s, %i -------- Acumulador: %i\n", i + 1, baralho[i].nome, baralho[i].naipe, baralho[i].valor, acumulador_jogador); 

            if(strcmp(baralho[i].nome, "As") == 0 && baralho[-1].valor == 10) {
                baralho[i].valor = 1; // Se a mão do jogador tiver uma dama, rei, valete (qualquer carta que valha 10), então o As passa a valer 1
            }
            if(strcmp(baralho[i].nome, "As") == 0 && baralho[-1].valor < 10){
                baralho[i].valor = 11; // Senão, o As passa a valer 11
            }
        }

        if(i >= 2 && i < 5) {
            printf("A carta %i do Dealer é %10s de %9s, %i -------- Acumulador: %i\n\n", i + 1, baralho[i].nome, baralho[i].naipe, baralho[i].valor, acumulador_dealer); 

            if(strcmp(baralho[i].nome, "As") == 0 && baralho[-1].valor == 10) {
                baralho[i].valor = 1; // Se a mão do jogador tiver uma dama, rei, valete (qualquer carta que valha 10), então o As passa a valer 1
            }
            if(strcmp(baralho[i].nome, "As") == 0 && baralho[-1].valor != 10){
                baralho[i].valor = 11; // Senão, o As passa a valer 11
            }

            acumulador_dealer += baralho[i].valor;
        }
    }

    printf("\nAcumulador Jogador: %i ----------- Acumulador Dealer: %i", acumulador_jogador, acumulador_dealer);

    if(acumulador_jogador >= 21) {
        printf("\nBlackJack natural. Parabéns! Você fez o impossível.           %i\n", acumulador_jogador);
        return 0;
    }

    char pedir[] = "pedir", parar[] = "parar", dividir[] = "dividir", desistir[] = "desistir", jogada[9];
    bool endGame = false;

    while(!endGame) {
        printf("\nSua vez!\nQual será sua jogada?\n> ");
        scanf("%9s", &jogada);

        if(strcmp(jogada, pedir) == 0){
            embaralhamento(baralho, 52);
            printf("\nSua nova carta é: %10s de %9s, %i", baralho[0].nome, baralho[0].naipe, baralho[0].valor);
            acumulador_jogador += baralho[0].valor;
            
            if(acumulador_jogador >= 21){
                printf("\nVocê perdeu! Acumulador: %i", acumulador_jogador);
                break;
            }
        }

        if(strcmp(jogada, parar) == 0){
            printf("\nVocê parou.");
            break;
        }

        if(strcmp(jogada, desistir) == 0){
            printf("\nVocê desistiu.");
            break;
        }

    } 

    return 0;
}
