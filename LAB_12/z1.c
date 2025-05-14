#include <stdio.h>

int main() {
    int a = 10;
    int* wsk = &a;
    
    printf("Wartość zmiennej a: %d\n", a);
    printf("Wartość przez wskaźnik: %d\n", *wsk);
}