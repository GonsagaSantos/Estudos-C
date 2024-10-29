#include <stdio.h>

float produtoEscalar(float vet1[], float  vet2[], int n) {
    
    int resultado = 0;
    
    for(int i = 0; i < n; i++) {
        resultado += vet1[i] * vet2[i];
    }
    
    return resultado;
    
}

int main()
{    
    int n = 0, resultado;

    printf("Qual será o tamanho dos vetores a serem calculados?\n> ");
    scanf("%i", &n);

    float vet1[n], vet2[n];
    
    for(int i = 0; i < n; i++) {
        printf("Qual será o valor da posição %i do vetor 1?\n> ", i);
        scanf("%f", &vet1[i]);

        printf("Qual será o valor da posição %i do vetor 2?\n> ", i);
        scanf("%f", &vet2[i]);
    }

    resultado = produtoEscalar(vet1, vet2, n);
    printf("O produto escalar é: %i", resultado);
    
    return 0;
}
