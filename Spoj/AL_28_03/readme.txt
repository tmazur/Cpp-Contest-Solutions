source: http://www.spoj.com/ALGOLIGA/problems/AL_28_03/



Farmer Jaś obudził się dziś i odkrył, że na jego polu UFO wycięło znaki. Pole Jasia jest kwadratem o boku N składającym się z N*N kwadratów jednostkowych. Znaki wycięte przez UFO również są kwadratami obejmującymi jeden lub kilka kwadratów jednostkowych. Wycięte kwadraty nie stykają się ani bokiem, ani wierzchołkiem. Jaś postanowił pozwać UFO do sądu dlatego potrzebna jest mu informacja, jakie jest pole powierzchni największego z wyciętych przez UFO kwadratów.

Pomóż mu.
Wejście

W pierwszym wierszu znajduje się liczba całkowita T (1 ≤ T ≤ 100) będąca liczbą zestawów danych.

Każdy zestaw danych opisany jest w następujący sposób.

W pierwszej linii znajduje się liczba całkowita N (1 ≤ N ≤ 100).

W każdej z kolejnych N linii znajduje się N znaków. Jeśli znak to '.' to znaczy, że dane pole zostało wycięte, a jeśli znak to '#' to pole nie zostało wycięte.
Wyjście

Dla każdego zestawu danych wypisz pole powierzchni największego z wyciętych kwadratów. Jeśli żaden kwadrat nie został wycięty, a farmer Jaś po prostu ma wysoką gorączkę, wypisz 0.
Przykład

Wejście:
2
5
#####
..###
..###
###..
.##..
10
##.#...##.
.###...###
####...##.
..########
..###.#.#.
##########
.#.#....##
####....##
##.#....#.
.###....##

Wyjście:
4
16
