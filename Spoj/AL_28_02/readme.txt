source: http://www.spoj.com/ALGOLIGA/problems/AL_28_02/



Jaś musi wstąpić do 3 kiosków. Każdy z tych kiosków ma kolejkę. W kolejce do pierwszego kiosku jest A osób, do drugiego B osób i do trzeciego C osób. Ponadto w pierwszym kiosku jedna osoba jest obsługiwana w a minut, w drugim kiosku w b minut, a w trzecim kiosku w c minut. Jaś zastanawia się w jakiej kolejności powinien kupować w kioskach, żeby zajęło mu to najmniej czasu. Czy jesteś w stanie mu pomóc ?
Wejście

Liczba zestawów danych T (1 ≤ T ≤ 104).

Każdy zestaw danych składa się z dwóch linii.

W pierwszej linii znajdują się liczby całkowite A, B i C (1 ≤ A, B, C ≤ 109).

W drugiej linii znajdują się liczby całkowite a, b i c (1 ≤ a, b, c, ≤ 109).
Wyjście

Dla każdego zestawu danych wypisz wynik: najmniejszą ilość minut jakie spędzi Jaś kupując i czekając w kioskach.
Przykład

Wejście:
3
3 3 3
4 4 4
1 3 2
2 3 1
1 1 1000000000
1 1 1000000000
Wyjście:
24
12
1000000001000000000

Wyjaśnienie do przykładu 1:
Najpierw Jaś staje w kolejce do kiosku 1.
Czeka 12 minut aż wszystkie osoby w kolejce zostaną obsłużone, potem jest obsługiwany przez kolejne 4 minuty.
Następnie przechodzi do kiosku 2, do którego nie ma już żadnej kolejki.
Jest obsługiwany w 4 minuty.
I w końcu w ostatnim kiosku 3 też jest obsługiwany w 4 minuty.
Razem 24 minuty.
