#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int* y = (int*) malloc(sizeof(int));
    *y = 20;

    int z = sizeof(int);

    printf("*y=%i z=%i\n", *y, z);

    return 0;
}