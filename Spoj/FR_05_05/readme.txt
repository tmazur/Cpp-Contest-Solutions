source: http://pl.spoj.com/problems/FR_05_05/

Kombinatoryka jest działem w matematyce, w którym zadania z powodzeniem można rozwiązywać wykorzystując komputer. Dziś, tego pięknego kwietniowego dnia, przygotowałem dla Was jedno z nich. Napisz program, który stwierdzi ile różnych liczb n cyfrowych można zbudować z cyfr {1, 2, 3}, takich, że moduł (wartość bezwzględna) różnicy dwóch sąsiednich cyfr będzie zawsze równy jeden. Wynik przedstaw modulo 101010101.
Wejście

W pierwszym wierszu jedna liczba określająca liczbę zapytań (nie więcej niż milion).

Każde zapytanie składa się z jednej liczby naturalnej n określającej liczbę cyfr danej liczby (1 < n < 1000001).
Wyjście

Dla każdej liczby cyfr określ liczbę różnych liczb jaką można zbudować z cyfr {1, 2, 3}.
Przykład

Wejście:
2
2
3
Wyjście:
4
6

Wyjaśnienie

Dla liczby złożonej z 3 cyfr (drugi przykład) możemy zbudować następujące liczby: 121, 123, 212, 232, 321, 323,
