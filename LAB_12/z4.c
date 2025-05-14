#include <stdio.h>

// Tworzenie prototypu funkcji
void* moja_memcpy(void* cel, const void* zrodlo, int rozmiar);

int z4() {
    char tekst1[] = "Hello!";
    char tekst2[10];
    moja_memcpy(tekst2, tekst1, 6);
    printf("%s\n", tekst2);
    return 0;
}

void* moja_memcpy(void* cel, const void* zrodlo, int rozmiar) {
    unsigned char* dest = (unsigned char*) cel; // Rzutowanie wskaźnika cel na unsigned char*
    unsigned char* src = (unsigned char*) zrodlo; // Rzutowanie wskaźnika zrodlo na unsigned char*
    for (int i = 0; i < rozmiar; i++) { // Pętla kopiująca elementy
        dest[i] = src[i];
    }
    dest[rozmiar] = '\0'; // Dodanie znaku końca łańcucha
    return cel;
}