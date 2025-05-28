Wykonane wszystkie polecenia

---

1.      Cele laboratorium:

Zrozumienie różnic w strukturze danych: tablica vs lista jednokierunkowa.
Porównanie kosztu czasowego podstawowych operacji (dodawanie, usuwanie, dostęp).
Praktyczne zaimplementowanie i przetestowanie obu podejść.
Uświadomienie różnic w zarządzaniu pamięcią.
 2.      Wprowadzenie teoretyczne:

Tablica to struktura danych o stałym rozmiarze i ciągłym układzie pamięci. Umożliwia szybki dostęp do elementu przez indeks, ale operacje dodawania lub usuwania wewnątrz tablicy są kosztowne.

Lista jednokierunkowa składa się z węzłów połączonych wskaźnikami. Pozwala na dynamiczne zarządzanie pamięcią i efektywne wstawianie lub usuwanie elementów, ale wymaga przechodzenia przez całą listę przy dostępie do konkretnego elementu.

 

Lista jednokierunkowa w języku C:

Lista jednokierunkowa to struktura danych zbudowana z wielu tzw. węzłów. Każdy węzeł zawiera:

dane (np. liczbę typu int),
wskaźnik do następnego węzła w liście.
Struktura węzła w języku C może wyglądać tak:

typedef struct Node {
    int dane;
    struct Node* nastepny;
} Node;
Tutaj:

dane to pole przechowujące wartość,
nastepny to wskaźnik do kolejnego węzła (lub NULL, jeśli to ostatni element).
Dzięki zastosowaniu typedef, można używać prostszej nazwy Node zamiast struct Node.

Tworzenie nowego węzła odbywa się dynamicznie:

 

Node* nowy = (Node*)malloc(sizeof(Node));
nowy->dane = 5;
nowy->nastepny = NULL;
 

Lista jednokierunkowa pozwala na dynamiczne dopasowanie rozmiaru do potrzeb programu, ale jest mniej efektywna przy losowym dostępie do elementów (trzeba przejść od początku listy).

"Pusta" komórka tablicy:

W języku C tablica nie ma wbudowanego mechanizmu, który odróżnia "zajęte" i "puste" komórki. Dlatego trzeba to rozwiązać samodzielnie:

Jeśli pracujesz na tablicy typu int, możesz zainicjalizować wszystkie komórki wartością np. -1 (lub inną umowną, która oznacza "brak danych").

for (int i = 0; i < ROZMIAR_TABLICY; i++) {
 tablica[i] = -1; // wartość oznaczająca pustą komórkę
} 
Alternatywnie możesz trzymać zmienną rozmiar, która informuje, ile komórek jest aktualnie zajętych. Nowe dane wpisujesz do tablica[rozmiar], a później zwiększasz rozmiar o 1.

int tablica[1000];
int rozmiar = 0; // liczba aktualnie zajętych pozycji
 
Nie używaj nieprzypisanych wartości w tablicach lokalnych bez inicjalizacji, ponieważ mogą zawierać losowe dane.

 

Zadania do wykonania:

Zadanie 1: Dodawanie elementu na koniec

Przygotuj tablicę o wystarczająco dużym rozmiarze (np. 100000 elementów), aby zmieścić wszystkie dane bez konieczności dynamicznej zmiany jej wielkości.
Napisz funkcję dodającą liczbę na koniec tablicy poprzez umieszczenie jej na pierwszej wolnej pozycji.
Napisz funkcję dodającą liczbę na koniec listy jednokierunkowej.
Zmierz czas dodania 1000, 10000 i 100000 elementów dla każdej struktury.
 

Zadanie 2: Wstawianie elementu w środek

Wstaw element na środek tablicy (np. w indeksie rozmiar / 2).
Wstaw element w środek listy (czyli po rozmiar / 2 węzłach).
Zmierz czas operacji.
 

Zadanie 3: Dostęp do elementu o danym indeksie

Wyszukaj i wypisz element o konkretnym indeksie (np. 5000) z tablicy i listy.
Porównaj czas dostępu.
 

Zadanie 4: Usuwanie elementu

Usuń element z końca, środka i początku tablicy.
Usuń element z końca, środka i początku listy.
Oceń i opisz różnice(może być w kodzie programu jako rezultat porównania).
 

Pomiar czasu dostępu:

#include <time.h>
clock_t start, end;
double czas;
 
start = clock();
//operacja
end = clock();

czas = (double)(end - start) / CLOCKS_PER_SEC;
printf("Czas: %f sekundy\n", czas);
