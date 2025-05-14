#include <stdio.h>

int z1() {
    int a = 10;
    int* wsk = &a;
    
    printf("Wartość zmiennej a: %d\n", a);
    printf("Wartość przez wskaźnik: %d\n", *wsk);
}