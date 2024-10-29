#include <stdio.h>
#include <math.h>

float normaVetor(int n, float vet[]) {
    
    int resultado = 0;
    
    for(int i = 0; i < n; i++) {
        resultado += pow(vet[i], 2);
    }
    
    return sqrt(resultado);
}

int main()
{
    int n, resultado;

    printf("Qual será o tamanho dos vetores a serem calculados?\n> ");
    scanf("%i", &n);

    float vet[n];

    for(int i = 0; i < n; i++) {
        printf("Qual será o valor da posição %i do vetor 1?\n> ", i);
        scanf("%f", &vet[i]);
    }
    
    resultado = normaVetor(n, vet);
    
    printf("A norma do vetor é: %i", resultado);
    
    return 0;
}
