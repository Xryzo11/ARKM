#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createDynamicArray(int size) {
    // (rozmiar w elementach) * (rozmiar typu tablicy)
    // w przypadku np float, musialoby byc:
    // malloc(size * sizeof(float));
    // bo kazdy typ ma inny tozmiar w pamieci
    int *array = malloc(size * sizeof(int));
    return array;
}

// void bo bezposrednio modyfikuje tablice
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