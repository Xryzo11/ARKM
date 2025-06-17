#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

int* createDynamicArray(int size) {
    int *array = malloc(size * sizeof(int));
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

void znajdzSkrajneISrednia (int* tab, int n, int** minPtr, int** maxPtr, float* srednia) {
    int *p = tab;
    *minPtr = tab;
    *maxPtr = tab;
    int sum = *p;
    p++;
    for (int i = 1; i < n; i++, p++) {
        if (*p < **minPtr) {
            *minPtr = p;
        }
        if (*p > **maxPtr) {
            *maxPtr = p;
        }
        sum += *p;
    }
    *srednia = (float)sum / n;
}