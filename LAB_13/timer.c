#include <time.h>

clock_t start, end;
double czas;

void startTimer();
float stopTimer();
float calculateTime();

void startTimer() { // Rozpoczyna pomiar czasu
    start = clock();
}

float stopTimer() { // Zatrzymuje pomiar czasu i zwraca czas w sekundach
    end = clock();
    return calculateTime();
}

float calculateTime() { // Oblicza czas w sekundach na podstawie różnicy między startem a końcem
    czas = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Czas: %f sekundy\n", czas);
    return czas;
}