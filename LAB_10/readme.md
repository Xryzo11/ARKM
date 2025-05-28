Wykonane bez zadań dla chętnych
<br>Oryginalnie napisane w C++, ułomnie przetłumaczone na C

---

Konwersja liczb pomiędzy systemami liczbowymi w języku C

Konwersja liczb całkowitych pomiędzy systemami: dziesiętnym (DEC), binarnym (BIN), ósemkowym (OCT) i szesnastkowym (HEX).

 Zakres materiału:

Reprezentacja liczb w systemach pozycyjnych.
Algorytmy konwersji pomiędzy systemami liczbowymi.
Obsługa typów danych w języku C.
Wykorzystanie tablic, pętli i instrukcji warunkowych.
Treść zadania:

Napisz program w języku C, który umożliwia użytkownikowi konwersję liczby całkowitej pomiędzy systemami liczbowymi:

Dziesiętny (DEC)
Binarny (BIN)
Ósemkowy (OCT)
Szesnastkowy (HEX)
Wymagania funkcjonalne programu:

Program powinien umożliwiać wybór systemu wejściowego (źródłowego) i systemu docelowego (wyjściowego).
Użytkownik podaje liczbę w wybranym systemie źródłowym.
Program dokonuje konwersji do systemu docelowego i wyświetla wynik.
Program powinien umożliwiać wielokrotne wykonywanie konwersji bez konieczności ponownego uruchamiania.
Konwersja przeprowadzana dla liczb, które w postaci binarnej zapisujemy na 8 bitach
Wymagania techniczne:

Obsługa podstawowych błędów (np. nieprawidłowe znaki w liczbie wejściowej).
Własne implementacje konwersji (nie korzystamy z funkcji itoa, strtol, sprintf itp.).
Użycie tablicy znaków do przechowywania reprezentacji liczby w innych systemach.
Czytelny i dobrze sformatowany kod.
Przykładowy interfejs programu (tekstowy):



Pomoc:

Wykorzystaj zamieszczone poniżej funkcję konwertujące pobrane znaki na liczyby i odwrotnie. Kod opiera się na ASCII, wykorzystuje fakt, że znaki alfanumeryczne mają określone kody. Jest to typowy sposób obsługi konwersji znak–cyfra w języku C.



Rozszerzenia (dla chętnych):

Obsługa liczb ujemnych (w systemie dziesiętnym).
Dodanie trybu „wszystkie na raz” – konwersja podanej liczby do wszystkich pozostałych systemów.
Kolorowanie wyników w terminalu (np. ANSI escape codes).
