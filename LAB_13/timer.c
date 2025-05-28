#include <time.h>

clock_t start, end;
double czas;

void startTimer();
float stopTimer();
float calculateTime();

void startTimer() {
    start = clock();
}

float stopTimer() {
    end = clock();
    return calculateTime();
}

float calculateTime() {
    czas = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Czas: %f sekundy\n", czas);
    return czas;
}