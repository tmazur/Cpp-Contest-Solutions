source: http://www.spoj.com/ALGOLIGA/problems/AL_30_04/

Jasio bardzo żałuje, że już od kilku lat nie może wziąć udziału w Internetowym Turnieju Programów Walczących, który to konkurs był swego czasu organizowany przez Koło Naukowe Informatyków Uniwersytetu Warszawskiego. Chłopiec postanowił więc sam zorganizować podobne zawody dla siebie oraz kolegów i koleżanek z klasy.

Jako grę, w której rywalizować będą programy napisane przez dzieci, Jasio wybrał starą chińską grę "Nim". Pewną liczbę kamieni rozkłada się w kilku stosach. Gracze wykonują ruchy na zmianę. W jednym ruchu gracz musi zabrać dowolną (niezerową) liczbę kamieni z jednego wybranego stosu. Wygrywa ten, kto zabiera ostatni kamień.

Wybór gry był może trochę niezbyt szczęśliwy, bo zwycięzcę można przewidzieć już na podstawie początkowego ułożenia kamieni, ale jak na początek dobre i to.

Twoim zadaniem będzie napisać program, który na podstawie początkowej sytuacji wyznaczy ruch gwarantujący (oczywiście przy zastosowaniu właściwej strategii w dalszym ciągu gry) zwycięstwo graczowi, który rozpoczyna grę.
Wejście

W pierwszej linii liczba stosów s (1 ≤ s ≤ 106).

W drugiej linii s liczb ai oznaczających liczby kamieni w kolejnych stosach (1 ≤ ai ≤ 106).
Wyjście

Dwie liczby całkowite oznaczające numer stosu i liczbę kamieni, które z tego stosu należy zabrać, aby zapewnić sobie zwycięstwo. Jeśli jest wiele wygrywających posunięć, można wybrać dowolne. Jeśli nie ma ruchu gwarantującego wygraną należy na wyjściu wypisać "0 0".
Przykład 1

Wejście:
3
5 2 4

Wyjście:
2 1

Przykład 2

Wejście:
4
5 2 4 3

Wyjście:
0 0
