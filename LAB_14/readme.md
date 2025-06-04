Integracja kodu asemblerowego z C + analiza wydajności

 1. Cel laboratorium

Przećwiczenie sposobu integracji gotowego kodu asemblerowego z kodem w języku C.
Porównanie czasu wykonania funkcji napisanej w języku C z funkcją napisaną w asemblerze dla dużych danych wejściowych.
 2. Treść zadania

a. Integracja gotowej funkcji asemblerowej

Skorzystaj z poniższego kodu i zapisz go w pliku asmfunc.s:

.global array_sum                 # Udostępniamy funkcję globalnie (dla linkera)
.type array_sum, @function       

array_sum:
    pushq %rbp                   # Zapisujemy bazowy wskaźnik stosu — przygotowanie do stworzenia ramki stosu
    movq %rsp, %rbp              # Ustawiamy nową ramkę stosu (standardowa procedura wejścia do funkcji)

    movq %rdi, %r8               # rdi — pierwszy argument (wskaźnik na tablicę int) kopiujemy do r8
    movq %rsi, %r9               # rsi — drugi argument (długość tablicy) kopiujemy do r9

    xorl %eax, %eax              # Ustawiamy rejestr eax (32-bitowa suma) na 0
                                 # W nim będziemy gromadzić sumę elementów

    xorq %rcx, %rcx              # Zerujemy licznik pętli (indeks i)

.loop:
    cmpq %r9, %rcx               # Porównujemy aktualny indeks i (rcx) z długością tablicy (r9)
    jge .end                     # Jeśli i >= długość, kończymy pętlę (wykonaliśmy sumę)

    movl (%r8,%rcx,4), %edx      # Wczytujemy arr[i] do edx — 4 bajty na element (int)
                                 # Adres: arr + i*4

    addl %edx, %eax              # Dodajemy bieżący element do sumy

    incq %rcx                    # i++ — przechodzimy do następnego indeksu

    jmp .loop                    # Skok na początek pętli, by kontynuować

.end:
    popq %rbp                    # Przywracamy bazowy wskaźnik stosu (wychodzimy z ramki)
    ret                          # Zwracamy z funkcji — wynik znajduje się w eax



W pliku main.c:
Zadeklaruj dużą tablicę, np. int* arr = malloc(1000000 * sizeof(int)); i wypełnij ją wartościami 1.
Wywołaj funkcję array_sum z asemblera i zapisz wynik.
Zmierz czas wykonania funkcji przy pomocy funkcji clock() z biblioteki time.h.
 b. Samodzielna implementacja funkcji w języku C

Napisz samodzielnie funkcję w języku C:
     int array_sum_c(int* arr, int len);
         Funkcja powinna sumować elementy tablicy przekazanej jako argument.

 c. Porównanie czasów wykonania

Zmierz czas wykonania funkcji array_sum_c (napisanej przez Ciebie) i porównaj go z czasem działania funkcji array_sum z asemblera.
Odpowiedz na pytania (odpowiedzi zapisz w sprawozdaniu):
Która funkcja działa szybciej?
Czy różnica jest znacząca?
Jakie mogą być przyczyny różnic w wydajności?
 3. Przykładowy szkielet kodu main.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
extern int array_sum(int* arr, int len);     // funkcja z asemblera
int array_sum_c(int* arr, int len);          // funkcja studenta w języku C
 
int main() {
   // ......
    clock_t start, end;
    double time_asm, time_c;
 
    start = clock();
    int result_asm = array_sum(arr, len);
    end = clock();
    time_asm = (double)(end - start) / CLOCKS_PER_SEC;
 
    //...
 
    printf("Wynik ASM: %d, czas: %f s\n", result_asm, time_asm);

    //...
 
    free(arr);
    return 0;
}
 4. Stwórz plik kompilacji Makefile, który:

skompiluje main.c do pliku obiektowego main.o
skompiluje asmfunc.s do asmfunc.o
połączy obie części w program wykonywalny main
Upewnij się, że w kompilacji używasz flagi -no-pie, np.:

main: main.o asmfunc.o
     gcc -no-pie -o main main.o asmfunc.o
Flagi nie tworzą programu jako Position-Independent Executable (PIE)", tylko jako tradycyjny plik wykonywalny ze stałymi adresami kodu