source: http://pl.spoj.com/problems/BAJTST/

W Bajtocji, jak co roku, zorganizowano "Święto Trójkąta". Z tej okazji wiele dzieci bierze udział w zabawie na Placu Ministerstwa Matematyki. Zabawa polega na tym, że każde dziecko losuje w Specjalnej Maszynie Losującej trzy liczby całkowite z zakresu od 10 do 200, a następnie rysuje kredą na placu trójkąt o bokach takiej długości (w centymetrach), jak wylosowane liczby. Każdy uczestnik zabawy wywiązuje się z zadania bezbłędnie i, jeśli jest to wykonywalne, rysuje idealnie swój trójkąt (żeby nie było wątpliwości - wypełniony). Możemy być też pewni, że miejsca na placu nie zabraknie.

 Znając wylosowane liczby i średnie zużycie kredy na metr kwadratowy wypełnionej powierzchni placu oblicz ile kredy zużyto podczas zabawy.
Wejście

Pierwsza linia wejścia zawiera liczbę przypadków testowych t (t≤10).

Pierwsza linia każdego testu zawiera dwie liczby n i k. Odpowiednio: liczbę uczestników zabawy (n≤103) oraz średnie zużycie kredy k w kg/m2 (k≤10). W kolejnych n liniach podane są po trzy liczby całkowite a, b i c - liczby wylosowane przez kolejnych uczestników.
Wyjście

Dla każdego przypadku testowego, w oddzielnej linii, całkowite zużycie kredy w gramach, w zaokrągleniu do najbliższej liczby całkowitej.
Przykład

Wejście:
2
2 1
30 40 50
20 20 20
1 0.5
70    22     33

Wyjście:
77
0
