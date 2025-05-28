#include <stdio.h>
#include <time.h>
#include "list.c"
#include "arrays.c"
#include "timer.c"

int main() {
    List list;
    int array[100000];

    // testList(&list);

    printf("Wypełnianie 1000 elementów w tablicy\n");
    preFillArray(array, 100000);
    startTimer();
    fillArray(array, 1000);
    float fillArray1k = stopTimer();

    printf("Wypełnianie 10000 elementów w tablicy\n");
    preFillArray(array, 100000);
    startTimer();
    fillArray(array, 10000);
    float fillArray10k = stopTimer();

    printf("Wypełnianie 100000 elementów w tablicy\n");
    preFillArray(array, 100000);
    startTimer();
    fillArray(array, 100000);
    float fillArray100k = stopTimer();

    printf("\n");

    printf("Wypełnianie 1000 elementów w liście\n");
    initList(&list);
    startTimer();
    fillList(&list, 1000);
    float fillList1k = stopTimer();
    freeList(&list);

    printf("Wypełnianie 10000 elementów w liście\n");
    initList(&list);
    startTimer();
    fillList(&list, 10000);
    float fillList10k = stopTimer();
    freeList(&list);

    printf("Wypełnianie 100000 elementów w liście\n");
    initList(&list);
    startTimer();
    fillList(&list, 100000);
    float fillList100k = stopTimer();
    freeList(&list);

    printf("\n");

    printf("Wstawianie elementu w środek tablicy na indeksie 1000\n");
    preFillArray(array, 100000);
    fillArray(array, 1100);
    startTimer();
    addToArray(array, 100000, 1000, -2);
    float addArray = stopTimer();

    printf("Wstawianie elementu w środek listy na indeksie 1000\n");
    initList(&list);
    fillList(&list, 1100);
    startTimer();
    addToListOnIndex(&list, -2, 1000);
    float addList = stopTimer();
    freeList(&list);

    printf("\n");

    printf("Wypisywanie elementu o indeksie 5000 z tablicy\n");
    preFillArray(array, 100000);
    fillArray(array, 100000);
    startTimer();
    printf("Element o indeksie 5000: %d\n", array[5000]);
    float getArray = stopTimer();

    printf("Wypisywanie elementu o indeksie 5000 z listy\n");
    initList(&list);
    fillList(&list, 100000);
    startTimer();
    printf("Element o indeksie 5000: %d\n", getFromList(&list, 5000));
    float getList = stopTimer();
    freeList(&list);

    printf("\n");

    printf("Usuwanie elementu o indeksie 1000 z tablicy\n");
    preFillArray(array, 100000);
    fillArray(array, 100000);
    startTimer();
    removeFromArray(array, 100000, 1000);
    float removeArray = stopTimer();

    printf("Usuwanie elementu o indeksie 1000 z listy\n");
    initList(&list);
    fillList(&list, 100000);
    startTimer();
    removeFromList(&list, 1000);
    float removeList = stopTimer();
    freeList(&list);

    printf("\n");
    printf("----- Porównanie czasów -----\n");
    printf("Wypełnianie 1000 elementów: %.6f sekundy (tablica), %.6f sekundy (lista)\n", fillArray1k, fillList1k);
    printf("Wypełnianie 10000 elementów: %.6f sekundy (tablica), %.6f sekundy (lista)\n", fillArray10k, fillList10k);
    printf("Wypełnianie 100000 elementów: %.6f sekundy (tablica), %.6f sekundy (lista)\n", fillArray100k, fillList100k);
    printf("Wstawianie elementu w środek: %.6f sekundy (tablica), %.6f sekundy (lista)\n", addArray, addList);
    printf("Wypisywanie elementu o indeksie 5000: %.6f sekundy (tablica), %.6f sekundy (lista)\n", getArray, getList);
    printf("Usuwanie elementu o indeksie 1000: %.6f sekundy (tablica), %.6f sekundy (lista)\n", removeArray, removeList);

    printf("\n");
    printf("----- Różnica czasów (tablica - lista) -----\n");
    printf("Wypełnianie 1000 elementów: %.6f sekundy\n", fillArray1k - fillList1k);
    printf("Wypełnianie 10000 elementów: %.6f sekundy\n", fillArray10k - fillList10k);
    printf("Wypełnianie 100000 elementów: %.6f sekundy\n", fillArray100k - fillList100k);
    printf("Wstawianie elementu w środek: %.6f sekundy\n", addArray - addList);
    printf("Wypisywanie elementu o indeksie 5000: %.6f sekundy\n", getArray - getList);
    printf("Usuwanie elementu o indeksie 1000: %.6f sekundy\n", removeArray - removeList);
}