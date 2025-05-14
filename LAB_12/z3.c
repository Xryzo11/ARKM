#include <stdio.h>

// Tworzenie prototypu funkcji
void kopiuj_tablice(int* cel, int* zrodlo, int rozmiar);

int z3() {
    int tab1[] = {1, 2, 3, 4, 5};
    int tab2[5];
    printf("Tablica przed kopiowaniem:\n");
    for (int i = 0; i < 5; i++) { // Wyświetlenie elementów tablicy
        printf("%d ", tab1[i]);
    }
    kopiuj_tablice(tab2, tab1, 5);
    printf("\nTablica po kopiowaniu:\n");
    for (int i = 0; i < 5; i++) { // Wyświetlenie elementów tablicy
        printf("%d ", tab2[i]);
    }
    printf("\n");
    return 0;
}

void kopiuj_tablice(int* cel, int* zrodlo, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) { // Kopiowanie elementów tablicy
        cel[i] = zrodlo[i];
    }
}