source: http://www.spoj.com/FRAKTAL/problems/FR_05_11/

FR_05_11 - Podbiegi

Podbiegi

Jasiu trenuje dzisiaj kilkuminutowe podbiegi. W tym celu zaplanował sobie trasę z kolejnymi wysokościami chwilowego postoju na odpoczynek. Zauważył jednak, że w niektórych przypadkach, jeśli zmieni kolejność punktów wysokości postoju, to liczba podbiegów będzie większa, a na tym mu najbardziej zależy. Znając ciąg wartości wysokości, przegrupuj kolejność interwałów biegowych tak, aby uzyskać maksymalną liczbę podbiegów.


Wejście
W pierwszym wierszu wejścia znajduje się liczba całkowita d (1 ≤ d ≤ 1000) oznaczająca liczbę przypadków testowych. Dla każdego przypadku, w pierwszym wierszu znajduje się liczba całkowita n (2 ≤ n ≤ 1000) oznaczająca liczbę punktów postoju. W wierszu drugim danych jest n liczb całkowitych ai (0 ≤ ai ≤ 1000) oznaczających wartości wysokości postoju.

Wyjście
Dla każdego przypadku testowego należy podać maksymalną liczbę podbiegów, w wyniku optymalnego przegrupowania kolejności wartości wysokości postoju.

Przykład

Wejście
2
4
20 10 30 10
5
20 30 10 0 40

Wyjście
2
4

Wyjaśnienie: W pierwszym przypadku Jasiu może uzyskać maksymalnie dwa podbiegi zmieniając kolejność wyrazów w ciągu na np. 10 20 10 30 lub 10 10 20 30. W drugim przypadku istnieje tylko jedna kombinacja 0 10 20 30 40, dla której maksymalizujemy liczbę podbiegów do czterech.
