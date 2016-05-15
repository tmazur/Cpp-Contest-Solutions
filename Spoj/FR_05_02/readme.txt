source: http://www.spoj.com/FRAKTAL/problems/FR_05_02/

FR_05_02 - Moc hasła

Profesor Algobit zajmuje się szkoleniami na temat zabezpieczeń systemów informatycznych. Właśnie zakończył prowadzić kurs dla początkujących i przechodzi do sprawdzenia zdobytej wiedzy przez kursantów. Jedno z pytań brzmi następująco: "Podaj przykładowe hasło, które spełnia normy bezpieczeństwa systemu informatycznego". Z racji tego, że kursanci odpowiadają na pytania przy pomocy komputera, wykładowca używa do sprawdzania odpowiedzi specjalnej aplikacji, która sprawdza moc hasła.

Właśnie kończysz ten kurs i chcesz jak najlepiej wypaść na jego zaliczeniu, napisz więc program, który sprawdzi, czy podane hasło jest silne.

Uznajemy, że hasło jest silne jeśli ma co najmniej osiem znaków oraz zawiera znaki z każdej z czterech następujących kategorii:

    Wielkie litery: A, B, C, ..
    Małe litery: a, b, c, ...
    Cyfry: 0, 1, 2, ...
    Symbole występujące na klawiaturze (wszystkie znaki na klawiaturze niezdefiniowane jako litery lub cyfry) oraz spacje.

Wejście

W pierwszym wierszu jedna liczba określająca liczba haseł do przeanalizowania (n < 1001).

W kolejnych n wierszach hasło do przeanalizowania. Każde hasło jest złożone z co najwyżej 1000 znaków.
Wyjście

Na wyjściu powinny pojawić się tylko silne hasła w kolejności występowania na wejściu.
Przykład

Wejście:
3
pass1234
P@$$1234
Pa$$1234

Wyjście:
Pa$$1234
