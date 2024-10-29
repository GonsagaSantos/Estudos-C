#include <stdio.h>
#include <math.h>
#include "letras.h"

double normaVetor(int vet[], int tamanho) {
    
    // -------- calculo das normas dos vetores
    
    double resultado = 0;
    
    for(int i = 0; i < tamanho; i++) {
        resultado += pow(vet[i], 2);
    }
    
    return sqrt(resultado);
}

int similaridade(int rows, int columns, int matVetores[rows][columns], int vetAnalisado[columns]) {
    
    // -------- declaração da matriz que irá armazenar os produtos escalares
    
    int vetProdutosEscalares[rows];
    
    // -------- calculo dos produtos escalares e armazenamento deles na respectiva coluna do vetor
    
    for(int currentRow = 0; currentRow < rows; currentRow++){

        for(int currentColumn = 0; currentColumn < columns; currentColumn++){

            vetProdutosEscalares[currentRow] += vetAnalisado[currentColumn] * matVetores[currentRow][currentColumn];

        }

    }

    // -------- calculo das normas dos vetores --------- cr = currentRow \ cc = current column
    
    double normaVetores[columns];
    double normaVetAnalisado = normaVetor(vetAnalisado, columns);

    for(int cr = 0; cr < rows; cr++) {
        normaVetores[cr] = normaVetor(matVetores[cr], columns);
    }

    // -------- calculo das similaridades
    
    double simVetores[rows];
    
    for(int cr = 0; cr < rows; cr++) {
        simVetores[cr] = vetProdutosEscalares[cr] / (normaVetores[cr] * normaVetAnalisado);
    }

    // -------- variavel para a maior similaridade
    
    int maiorSim = 0;
    for(int cr = 0; cr < rows; cr++){
        
        if(simVetores[cr] > simVetores[maiorSim]) {
            maiorSim = cr;
        }
        
    }
    
    return maiorSim;
    
}

int main()
{
    int rows;
    printf("Quantos vetores irão ser analisados?\n> ");
    scanf("%i", &rows);

    int columns;
    printf("Qual o tamanho dos vetores?");
    scanf("%i", &columns);

    int matVetores[rows][columns];

    for (int i = 0; i < rows; i++) {
        for (int x = 0; x < columns; x++) {
            printf("Qual o valor da posição %i do vetor %i? ", x + 1, i + 1);
            scanf("%i", &matVetores[i][x]);
        }
        printf("\n");
    }

    int vetAnalisado[columns];
    for(int i = 0; i < columns; i++){
        printf("Qual o valor da posição %i do vetor de base? ", i + 1);
        scanf("%i", &vetAnalisado[i]);
    }


    int resultado;
    char nome;
    
    resultado = similaridade(rows, columns, matVetores, vetAnalisado);
    nome = qualFoiOVetor(resultado);
    
    printf("O vetor com a maior similaridade foi o vetor %c", nome);
    
    return 0;
}
