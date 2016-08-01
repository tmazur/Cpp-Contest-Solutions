source: http://pl.spoj.com/problems/MWP8_1J/

MWP8_1J - Polygonia

Sigma i Pi są najbogatszymi mieszkańcami Polygonii. Posiadają oni n działek, które jak przystało na tę krainę mają kształt wielokątów wypukłych. Nasi bohaterowie postanowili jeszcze bardziej pokazać swoją potęgę. Sigma i Pi zamierzają wykupić ziemię pomiędzy posiadanymi przez nich działkami, tak aby powstała jedna duża posiadłość. Działka ta oczywiście musi mieć kształt wielokąta wypukłego. Oprócz tego naszym bohaterom zależy na tym, aby nie wykupić więcej ziemi niż jest to potrzebne do spełnienia poprzedniego założenia.

Twoim zadaniem jest obliczenie ile ziemi muszą wykupić Sigma i Pi by zrealizować swój plan.
Wejście

W pierwszej linii wejścia znajduje się jedna liczba całkowita n oznaczająca liczbę działek posiadanych przez naszych bohaterów. W kolejnych liniach znajdują się opisy działek. W pierwszym wierszu definicji działki znajduje się jedna liczba całkowita m określająca liczbę wierzchołków wielokąta opisującego działkę. W kolejnych m liniach znajdują się współrzędne x, y ∈ [0;109] wierzchołków wielokąta. Wierzchołki podawane są zgodnie z ruchem wskazówek zegara. Gwarantujemy, że wszystkie działki są wielokątami wypukłymi zaś suma wierzchołków wszystkich posiadłości nie przekracza 2500.
Wyjście

Na wyjściu należy wypisać minimalną powierzchnię ziemi jaką powinni kupić Sigma i Pi, aby połączyć wszystkie swoje działki w jedną będącą również wielokątem wypukłym. Automatyczny sędzia sprawdza wyniki z dokładnością do 6 miejsc po przecinku.
Przykład

Wejście:

3
4
1 3
1 5
3 5
3 3
6
2 7
3 8
4 8
5 7
4 6
3 6
6
4 2
7 5
8 4
8 2
7 1
5 1

Wyjście:

16.000000
