source: http://pl.spoj.com/problems/PTWPZ091/

Profesor Ciekawski, wybitny reprezentant białostockiego środowiska naukowego, zmienił ostatnimi czasy swoje zainteresowania. Od kilku już miesięcy wędruje po tajemniczych wyspach archipelagu Pitu-Pitu w poszukiwaniu nieznanych dotąd gatunków roślin i zwierząt. Jednymi z ulubieńców profesora są bzykacze brum-brum (łac. bzykus brum-brumus), sympatyczne i wesoło bzykające jaskrawożółte owady, przypominające nieco nasze trzmiele.

Bzykacze są gatunkiem terytorialnym. Każdy osobnik, niezależnie od płci i wieku, zajmuje określone terytorium w kształcie kuli, na przestrzeni którego spija nektar z kwiatów polnych i drzew, paruje się z przedstawicielami płci przeciwnej (o ile terytoria takiej pary zachodzą na siebie), wychowuje potomstwo i oczywiście bzyka w każdej wolnej chwili. Profesor postanowił przeprowadzić dokładniejsze badania na wybranej przez siebie polnej gromadzie bzykaczy. Aby ułatwić sobie zadanie, ma zamiar otoczyć terytorium zajęte przez gromadę prostopadłościenną siatką ochronną umocowaną na gruncie, składającą się z czterech ścian bocznych i ściany górnej. W tym celu precyzyjnie wyznaczył terytorium każdego osobnika. Teraz pozostaje opracować wyniki i obliczyć ilość niezbędnego materiału. I to jest zadanie dla Ciebie. Napisz program, który na podstawie podanych terytoriów bzykaczy wyznaczy minimalną powierzchnię siatki niezbędną do otoczenia całej gromady.
Wejście

Dane podawane są na standardowe wejście. W pierwszym wierszu podana jest liczba N (1<=N<=20) zestawów danych. Dalej podawane są zestawy danych zgodnie z poniższym opisem:
Jeden zestaw danych

Pierwszy wiersz zestawu danych zawiera liczbę całkowitą n (1<=n<=1000) oznaczająca liczbę bzykaczy w badanej gromadzie. W kolejnych n wierszach znajdują się opisy terytoriów bzykaczy. Każdy z takich opisów składa się z czterech liczb całkowitych xi,yi,hi,ri (1<=xi,yi,hi<=1000, 1<=ri<=hi), oddzielonych pojedynczymi spacjami, oznaczających odpowiednio współrzędne x, y i wysokość środka terytorium, oraz jego promień.
Wyjście

Wyniki programu powinny być wypisywane na standardowe wyjście. W kolejnych wierszach należy podać odpowiedzi obliczone dla kolejnych zestawów danych. Wynikiem dla jednego zestawu jest minimalna powierzchnia siatki niezbędnej do otoczenia gromady bzykaczy.
Przykład

dane wejściowe:
2
2
10 20 30 5
10 10 10 10
3
10 50 22 13
60 10 3 1
50 70 30 20

wynik:
3650
21313
