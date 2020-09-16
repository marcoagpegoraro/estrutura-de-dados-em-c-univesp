#include <stdio.h>

#define alturaMaxima 255

typedef int CHAVE;

typedef struct {
    int peso;
    int altura;
} PesoAltura;

int main(){
    PesoAltura pessoa1;
    pessoa1.peso = 80;
    pessoa1.altura = 185;

    printf("Peso: %d Altura: %d\n", pessoa1.peso, pessoa1.altura);
    
    if(pessoa1.altura > alturaMaxima) printf("altura acima da maxima\n");
    else printf("altura abaixo da maxima\n");


    return 0;
}