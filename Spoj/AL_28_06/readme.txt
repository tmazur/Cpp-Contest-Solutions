source: http://www.spoj.com/ALGOLIGA/problems/AL_28_06/

Jaś zaczął ostatnio grać w gry RPG. Gra, którą aktualnie stara się przejść wymaga od Jasia stoczenia po kolei N walk z różnymi przeciwnikami. Każda walka polega na naprzemiennym wykonywaniu ataków. Raz atakuje przeciwnik Jasia, a raz Jaś (przeciwnik zawsze zaczyna). Podczas każdego ataku, atakowany ma pewną określoną szansę na unik. Szansa ta jest określona dla każdego przeciwnika oraz dla Jasia. Jeśli zaatakowany został Jaś oraz nie udało mu się wykonać uniku, to otrzymuje on 1 punkt obrażeń. Natomiast jeśli Jaś atakuje i jego atak sięgnie celu to natychmiast pokonuje on przeciwnika, oraz przechodzi do następnego, lub kończy grę jeśli nie ma już żadnego przeciwnika do pokonania.

Jaś chce wiedzieć jaka jest oczekiwana liczba obrażeń, które otrzyma on po stoczeniu wszystkich walk. Czy jesteś w stanie odpowiedzieć na to pytanie?
Wejście

W pierwszej linii znajduje się liczba zestawów danych T (1 ≤ T ≤ 1000).

W pierwszej linii każdego zestawu danych znajdują się dwie liczby, liczba całkowita N oraz liczba rzeczywista podana z dokładnością do 2 miejsc po przecinku d (1 ≤ N ≤ 1000, 0 ≤ d ≤ 1) oznaczające kolejno liczbę przeciwników oraz szansę na to, że Jaś wykona unik będąc atakowanym.

W drugiej linii każdego zestawu danych znajduje się N liczb rzeczywistych podanych z dokładnością do 2 miejsc po przecinku a1, ..., an (0 ≤ ai < 1). Liczba ai oznacza, że i-ty przeciwnik ma ai szansę na wykonanie uniku, przy czym zauważ, że żaden przeciwnik nie ma 100% szans na wykonanie uniku.
Wyjście

Dla każdego zestawu danych należy wypisać jedną liczbę z dokładnością do 6 miejsc po przecinku będącą oczekiwaną liczbą obrażeń otrzymanych przez Jasia po stoczeniu N walk.
Przykład

Wyjście:
4
2 0.00
0.80 0.80
5 0.80
0.10 0.20 0.30 0.40 0.50
1 1.00
0.99
3 0.50
0.50 0.50 0.50
Wyjście:
10.000000
1.491270
0.000000
3.000000
