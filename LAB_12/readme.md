Wykoanane bez zadań dla chętnych

---

Cel laboratorium:

Poznanie mechanizmu wskaźników w języku C.
Ćwiczenie operacji arytmetyki wskaźników.
Zrozumienie kopiowania danych w pamięci.
Implementacja własnej funkcji kopiującej pamięć.
 

Zadania do wykonania:

Zadanie 1: Proste wskaźniki

Deklaracja zmiennej a, wskaźnika wsk, przypisanie adresu i wypisanie wartości:

int a = 10;
int* wsk = &a;
 
printf("Wartość zmiennej a: %d\n", a);
printf("Wartość przez wskaźnik: %d\n", *wsk);
 

Zadanie 2: Zamiana dwóch zmiennych

Napisz funkcję:

void zamien(int* x, int* y);

Użyj zmiennej pomocniczej do zamiany wartości miejscami.

Test funkcji:

int a = 5, b = 8;
zamien(&a, &b);
printf("a = %d, b = %d\n", a, b);
 
Zadanie 3: Kopiowanie tablicy

Napisz funkcję kopiującą tablicę za pomocą wskaźników:

void kopiuj_tablice(int* cel, int* zrodlo, int rozmiar);


Przykład testu:

int tab1[] = {1, 2, 3, 4, 5};
int tab2[5];
kopiuj_tablice(tab2, tab1, 5);
 

Zadanie 4: Własna funkcja memcpy

Napisz funkcję:

void* moja_memcpy(void* cel, const void* zrodlo, int rozmiar);
Użyj unsigned char* do kopiowania bajt po bajcie.

 

Funkcja powinna kopiować dokładnie rozmiar bajtów z pamięci wskazywanej przez zrodlo do pamięci wskazywanej przez cel.

Użyj wskaźników typu unsigned char*, ponieważ zapewniają one kopiowanie pojedynczych bajtów bez interpretacji ich jako liczby ze znakiem.

Pamiętaj, że wskaźniki należy odpowiednio rzutować, aby można było operować na bajtach.

Funkcja powinna zwracać wskaźnik na cel, aby umożliwić łańcuchowe wywołania lub dalsze operacje na skopiowanych danych.

Przykład testu:

char tekst1[] = "Hello!";
char tekst2[10];
moja_memcpy(tekst2, tekst1, 6);
printf("%s\n", tekst2);
 

Zadanie 5 (dla chętnych): Odwracanie tablicy

Napisz funkcję:

void odwroc_tablice(int* tab, int rozmiar);
Odwracaj elementy tablicy w miejscu, tzn.  bez tworzenia tablicy pomocniczej.
