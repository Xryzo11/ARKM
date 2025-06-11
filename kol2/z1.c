#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

int* createDynamicArray(int size) {
    int *array = malloc(size / sizeof(int));
    return array;
}

void fillArrayRandom(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = (clock() * rand()) % 100;
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int* znajdzMax(int* tab, int n) {
    int* p = tab;
    int* pMax = tab;
    for (int i = 0; i < n; i++, p++) {
        if (*p > *pMax) {
            pMax = p;
        }
    }
    return pMax;
}