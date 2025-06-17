#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "z1.c"
#include "z2.c"

int main() {
    // Zadanie 1
    int size;
    printf("Podaj rozmiar tablicy:\n");
    scanf("%d", &size);
    if (size > 0) {
        int* array = createDynamicArray(size);
        fillArrayRandom(array, size);
        printArray(array, size);
        int *pointerMin, *pointerMax;
        float avg;
        float *pointerAvg = &avg;
        znajdzSkrajneISrednia(array, size, &pointerMin, &pointerMax, &avg);
        printf("Maksymalny element: %d (%p)\n", *pointerMax, (void*)pointerMax);
        printf("Minimalny element: %d (%p)\n", *pointerMin, (void*)pointerMin);
        printf("Srednia: %.2f (%p)\n", avg, pointerAvg);
        free(array);
    } else {
        printf("Niepoprawny rozmiar tablicy\n");
    }

    // Zadanie 2
    char* string;
    printf("Podaj łancuch znaków (max 100 znaków)\n");
    fgets(string, 100, stdin); // bez powtorzenia pomija fgets
    fgets(string, 100, stdin); // zapewne problem z buforem od scanf
    usunDuplikaty(string);
    printf("%s", string);

    return 0;
}