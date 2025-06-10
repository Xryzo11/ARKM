#include <stdio.h>
#include <stdlib.h>

#include "dynarray.c"
#include "maxvalpoint.c"
#include "string.c"

int main () {
    // Tablica dynamiczna (dynarray.c)
    int *dynArray = createDynamicArray(10);
    fillArrayRandom(dynArray, 10);
    printf("Wypisanie tablicy\n");
    printArray(dynArray, 10);
    printf("\n");

    // Wskaznik maksymalnej wartosci (maxvalpoint.c)
    printf("Wskaznik maksymalnej wartosci w tablicy\n");
    int *max_ptr = findMaxValue(dynArray,10);
    printf("%d\n", *max_ptr);
    printf("\n");

    // Operacje na lancuchach (string.c)
    printf("Operacje na lancuchach\n");
    char string[] = "AbCdEfGhIjKlMnOpRsTuWxYz";
    printf("%s\n", string);
    printf("lowerToUpper - ");
    lowerToUpper(string);
    printf("%s\n", string);
    printf("removeCharacter - ");
    removeCharacter(string, 10);
    printf("%s\n", string);

    // Cleanup
    printf("\n");
    free(dynArray);
    return 0;
}