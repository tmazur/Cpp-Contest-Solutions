source: http://www.spoj.com/ALGOLIGA/problems/AL_30_05/

Sieć kolejowa w Bajtocji spełnia prostą zasadę: z dowolnego miasta można dostać się do każdego z pozostałych miast tylko jednym sposobem.

Bajtek i Bitek to dwaj starzy przyjaciele, którzy postanowili wspólnie wybrać się pociągiem na wycieczkę do Bajtogrodu - stolicy kraju. Ponieważ nie chcą tracić czasu i pieniędzy na niepotrzebną jazdę, przyjaciele umówili się tak, że każdy wyjedzie ze swojego miasta w kierunku stolicy i spotkają się w najbliższym mieście, które leży na trasie każdego z nich (takim miastem może być dopiero Bajtogród). Dalej pojadą już razem i pewnie miło spędzą czas na wspominaniu dawnych czasów.

Przyjaciół interesuje to, w którym mieście się spotkają.
Wejście

W pierwszej linii liczba miast n (1 ≤ n ≤ 200000).

W każdej z kolejnych n−1 linii dwie liczby oznaczające numery miast połączonych bezpośrednio linią kolejową. Miasta numerowane są od 1 do n, a stolica ma numer 1.

Następnie liczba zapytań q (1 ≤ q ≤ 200000).

W kolejnych q lniach po dwie liczby całkowite oznaczające numery miast, w których mieszkają przyjaciele.
Wyjście

Dla każdego zapytania, w oddzielnej linii numer miasta, w którym spotkają się przyjaciele na drodze do stolicy.
Przykład

Wejście:
5
1 2
2 3
5 2
4 1
3
3 5
5 4
3 3

Wyjście:
2
1
3
