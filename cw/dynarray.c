#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createDynamicArray(int size) {
    int *array = malloc(size * sizeof(int));
    return array;
}

void fillArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }
}

void fillArrayRandom(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = (clock() * rand()) % 1000;
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}