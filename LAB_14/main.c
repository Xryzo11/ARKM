#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
extern int array_sum(int* arr, int len);     // funkcja z asemblera
int array_sum_c(int* arr, int len);          // funkcja studenta w języku C
int fill_array(int* arr, int len);           // funkcja wypełniająca tablicę wartoscia 1
 
int main() {
    // Tworzenie i wypełnienie tablicy o długości 1000000
    int len = 1000000;
    int* arr = malloc(len * sizeof(int));
    fill_array(arr, len);

    // Deklaracja zmiennych do pomiaru czasu
    clock_t start, end;
    double time_asm, time_c;
 
    // Pomiar czasu funkcji w assemblerze
    start = clock();
    int result_asm = array_sum(arr, len);
    end = clock();
    time_asm = (double)(end - start) / CLOCKS_PER_SEC;
 
    // Pomiar czasu funkcji w C
    start = clock();
    int result_c = array_sum_c(arr, len);
    end = clock();
    time_c = (double)(end - start) / CLOCKS_PER_SEC;

    // Wyświetlenie wyników
    printf("Wynik ASM: %d, czas: %f s\n", result_asm, time_asm);
    printf("Wynik C: %d, czas: %f s\n", result_c, time_c);
 
    // Uwolnienie pamięci
    free(arr);
    return 0;
}

// Funkcja sumująca elementy tablicy w C
int array_sum_c(int* arr, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum;
}

// Funkcja wypełniająca tablicę wartością 1
int fill_array(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = 1;
    }
    return 0;
}