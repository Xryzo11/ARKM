// Import bibliotek
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypy funkcji
char*intToBinary(int integerPart);
char*decToBinary(float decimal, int places);
char*intToString(int number);

int main() {
    // Wypisanie tekstu i pobieranie wartości od użytkownika
    printf("Podaj licznik: ");
    int numerator;
    scanf("%d", &numerator);
    printf("Podaj mianownik: ");
    int denominator;
    scanf("%d", &denominator);
    printf("Podaj ilosc miejsc po przecinku: ");
    int places;
    scanf("%d", &places);
    if (denominator == 0) { // Sprawdzenie, czy mianownik jest zerem
        printf("Nie mozna dzielic przez zero!\n");
        return 1;
    }
    int integerPart = 0;
    while (numerator >= denominator) { // Obliczanie części całkowitej
        numerator -= denominator;
        integerPart++;
    }
    float decimal = (float) numerator / denominator;
    char *intBinary = NULL; // Tworzenie wskaźnika na łańcuch znaków
    if (integerPart > 0) { // Obliczanie części całkowitej w systemie binarnym
        intBinary = intToBinary(integerPart);
    } else {
        intBinary = strdup("0");
    }
    char *decBinary = NULL; // Tworzenie wskaźnika na łańcuch znaków
    if (places > 0) { // Obliczanie części ułamkowej w systemie binarnym
        decBinary = decToBinary(decimal, places);
    }
    // Wypisanie wyniku
    printf("Wynik w systemie binarnym: ");
    printf("%s", intBinary);
    if (places > 0) {
        printf(".");
        printf("%s", decBinary);
    }
    printf("\n");
    // Zwolnienie pamięci
    free(intBinary);
    free(decBinary);
    return 0;
}

char* intToBinary(int integerPart) { // Konwersja liczby całkowitej na system binarny
    char *intBinary = malloc(100);
    intBinary[0] = '\0';
    while (integerPart > 0) {
        char *temp = intToString(integerPart % 2); // Konwersja bitu na łańcuch
        strcat(intBinary, temp);
        free(temp); // Zwolnienie pamięci
        integerPart /= 2;
    }
    return intBinary;
}

char* decToBinary(float decimal, int places) { // Konwersja liczby ułamkowej na system binarny
    char *decBinary = malloc(100);
    decBinary[0] = '\0';
    while (places > 0) {
        decimal *= 2;
        int bit = (int) decimal;
        char *temp = intToString(bit); // Konwersja bitu na łańcuch
        strcat(decBinary, temp);
        free(temp); // Zwolnienie pamięci
        decimal -= bit;
        places--;
    }
    return decBinary;
}

char* intToString(int number) { // Konwersja liczby całkowitej na łańcuch
    char *str = malloc(100);
    sprintf(str, "%d", number);
    return str;
}