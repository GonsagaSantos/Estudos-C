#include <stdio.h>
#include <math.h>

double normaVetor(int n, int vet[]) {
    
    double resultado = 0;
    
    for(int i = 0; i < n; i++) {
        resultado += pow(vet[i], 2);
    }
    
    printf("A norma do vetor é: %.2f\n", sqrt(resultado));
    
    return sqrt(resultado);
}

double similaridade(int n, int vetA[], int vetB[]) {
    
    double prodEscalar = 0;
    
    for(int i = 0; i < n; i++){
        prodEscalar += vetA[i] * vetB[i];
    }
    
    double normaVetA = normaVetor(n, vetA);
    double normaVetB = normaVetor(n, vetB);
    
    printf("O produto escalar dos vetores: %.2f\n", prodEscalar);
    printf("A norma do vetor A: %.2f\n", normaVetA);
    printf("A norma do vetor B: %.2f\n", normaVetB);
    
    return prodEscalar / (normaVetA * normaVetB);
    
}

int main()
{
    int n;
    printf("Qual vai ser o tamanho dos vetores?");
    scanf("%i", &n);

    int vetA[n], vetB[n];

    for(int i = 0; i < n; i++){
        printf("Insira o valor da posição %i do vetor 1.\n> ", i + 1);
        scanf("%i", &vetA[i]);

        printf("Insira o valor da posição %i do vetor 2.\n> ", i + 1);
        scanf("%i", &vetB[i]);
    }

    double resultado;
    
    resultado = similaridade(n, vetA, vetB);
    
    printf("A similaridade entre os dois vetores é: %.2f", resultado);
    
    return 0;
}
