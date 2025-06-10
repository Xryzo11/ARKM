#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void lowerToUpper(char* string) {
    // jedzie po stringu az nie znajdzie znaku koncowego
    for (int i = 0; string[i] != '\0'; i++) {
        if (islower(string[i])) {
            string[i] = toupper(string[i]);
        }
    }
}

void removeCharacter(char* string, int index) {
    if (index < 0) return;
    // jedzie do konca, i mogloby byc i=index,
    // ale wtedy wczesniej byloby trzeba sprawdzic rozmiar stringa
    // w taki sposob jakby byl index za wysoki to petla sie zatrzyma na '\0'
    for (int i = 0; string[i] != '\0'; i++) {
        if (i == index) {
            // zaczyna od momentu gdzie skonczyla sie ostatnia petla (znak do usuniecia)
            // przesuwa kazdy znak po nim w lewo (efektywnie usuwajac ten na podanym indeksie)
            for (int j = i; string[j] != '\0'; j++) {
                string[j] = string[j + 1];
            }
            // anuluje zewnetrzna petle bo znak juz zostal usuniety,
            // nie ma po co sprawdzac dalej
            break;
        }
    }
}