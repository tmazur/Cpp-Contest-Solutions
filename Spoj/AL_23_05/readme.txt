Source: http://www.spoj.com/ALGOLIGA/problems/AL_23_05/

Łazik

Jasiu, znany konstruktor robotów, właśnie skończył pracę nad nowym łazikiem, a wykorzystał do jego produkcji popularny mikrokomputer Raspberry Pi o ogromnych możliwościach. Łazik został zaprogramowany tak, że przemieszcza się z lewego górnego rogu do prawego dolnego rogu pewnego terenu z przeszkodami, poruszając się w kierunku wschodnim lub południowym w metryce miasto. Mapa terenu z przeszkodami została załadowana do pamięci komputera w postaci diagramu, gdzie znak kropki oznacza możliwość poruszania się, a znak x to przeszkoda, którą należy ominąć. Łazik wykorzystując algorytm przeszukiwania w głąb, bez problemu odnajduje drogę od startu do mety, o ile jest to możliwe. Dlatego nie musisz wyznaczać jego trasy. Twoje zadanie jest inne, musisz napisać program, który wyznaczy liczbę różnych dróg, jakie może pokonać łazik przemieszczając się z lewego górnego rogu do prawego dolnego, poruszając się tylko w kierunku wschód lub południe i omijając przeszkody. Ponieważ w niektórych przypadkach liczba ta jest bardzo duża, wystarczy, że podasz jej resztę z dzielenia przez 1000000009.

Wejście
W pierwszym wierszu wejścia znajduje się liczba całkowita d (1 ≤ d ≤ 1000) oznaczająca liczbę przypadków testowych. Każdy przypadek opisują w pierwszym wierszu jedna liczba całkowita n (2 ≤ n ≤ 1000) oznaczająca wymiar kwadratowego diagramu. Dalej podanych jest n wierszy, każdy po n znaków opisujących diagram według specyfikacji podanej w treści zadania. Punkt startu i mety jest wolny od przeszkody.
Pliki wejściowe nie przekraczają 3MB.

Wyjście
Dla każdego przypadku testowego należy podać liczbę różnych dróg, jakie może przebyć łazik, modulo 1000000009.

Przykład

Wejście

3
3
...
..x
.x.
3
...
...
...
5
.....
.x...
..x..
...x.
.....


Wyjście
0
6
10