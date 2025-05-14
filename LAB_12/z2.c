#include <stdio.h>

// Tworzenie prototypu funkcji
void zamien(int* x, int* y);

int main() {
    int a = 5;
    int b = 8;
    printf("Przed zamiana: a = %d, b = %d\n", a, b);
    zamien(&a, &b);
    printf("Po zamianie: a = %d, b = %d\n", a, b);
    return 0;
}

void zamien(int* x, int* y) {
    int temp = *x; // Pomocnicza zmienna tymczasowa
    *x = *y; // Przypisanie wartości y do x
    *y = temp; // Przypisanie wartości temp (starego x) do y
}