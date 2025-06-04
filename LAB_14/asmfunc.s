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

    