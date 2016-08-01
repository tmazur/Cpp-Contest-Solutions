source: http://pl.spoj.com/problems/EIE4/

EIE4 - Eksploracje i ekstrapolacje: Poukładane

Same wyliczenia podstawowych miar to jednak trochę za mało przy poważniejszych analizach i szybko poproszono Cię o implementację kolejnej funkcjonalności, mianowicie narzędzia do porządkowania i prezentacji danych z plików CSV. Ma być ono zrealizowane według poniższej specyfikacji (i to na wczoraj)!
Wejście

W pierwszej linii każdego pliku rozdzielone spacjami kolejno:

r - wartość True/False wskazująca, czy mają być drukowane numery wierszy;

h - wartość True/False określająca, czy należy wyświetlić nagłówek;

e - napis definiujący w jaki sposób prezentować pola z brakującymi danymi;

d - znak określający w jaki sposób rozdzielone są dane.

W drugiej linii rozdzielone znakiem d nagłówki odpowiadające kolumnom danych. Można założyć, że nagłówków nigdy nie brakuje.

W kolejnych liniach dane rozdzielone znakami d.

Znaki d nie pojawiają się nigdy w samych danych. Iloczyn liczby kolumn oraz liczby wierwszy nie przekracza miliona.
Wyjście

Ramka danych, która w zależności od parametrów wyświetlana jest z nagłówkiem i liczbami wierszy lub bez. Każda kolumna powinna mieć szerokość dobraną wedle najszerszej danej. Wszystkie kolumny powinny być rozdzielone dwoma spacjami, braki w danych zastąpione napisem e. Dane równamy do prawej. Linie zawsze kończymy znakiem nowej linii.
Przykład

Input:
True True N/A ,
ID,DATE,USER,RESULT,TIME,MEM,LANG
13394870,2015-01-10 21:43:39,aakash,accepted,0.16,1341M,JAVA
13392496,2015-01-10 15:37:50,Utkarsh,wrong answer,0.00,7.5M,PYTH 2.7
13391470,2015-01-10 13:21:17,Utkarsh,wrong answer,0.00,7.5M,PYTH 2.7
13391442,2015-01-10 13:13:40,Utkarsh,wrong answer,0.00,7.5M,PYTH 2.7
13390989,2015-01-10 12:01:18,aakash,wrong answer,0.16,1341M,JAVA
13390787,2015-01-10 11:38:27,aakash,wrong answer,0.16,1341M,JAVA
13390774,2015-01-10 11:37:04,aakash,wrong answer,0.10,1341M,JAVA
13390718,2015-01-10 11:29:55,aakash,runtime error (NZEC),0.10,1341M,JAVA
13390707,2015-01-10 11:29:02,aakash,compilation error,,,JAVA
13390699,2015-01-10 11:28:00,aakash,runtime error (NZEC),0.11,1341M,JAVA
13390691,2015-01-10 11:27:06,aakash,compilation error,,,JAVA
13390438,2015-01-10 10:59:55,aakash,runtime error (NZEC),0.14,1341M,JAVA
13390423,2015-01-10 10:58:15,aakash,compilation error,,,C++ 4.3.2
13389991,2015-01-10 09:52:26,aakash,runtime error (NZEC),0.15,1341M,JAVA
13272813,2014-12-26 15:28:37,Bijoy Rahman Arif,wrong answer,0.00,2.2M,C
13272302,2014-12-26 15:01:17,Bijoy Rahman Arif,wrong answer,0.00,2.2M,C
13271177,2014-12-26 14:11:06,Bijoy Rahman Arif,wrong answer,0.00,2.2M,C
13271154,2014-12-26 14:07:42,Bijoy Rahman Arif,wrong answer,0.00,2.2M,C
13270804,2014-12-26 13:21:45,Bijoy Rahman Arif,wrong answer,0.00,2.2M,C
13270641,2014-12-26 13:01:45,Bijoy Rahman Arif,wrong answer,0.01,2.2M,C

Output:
          ID                 DATE               USER                RESULT  TIME    MEM       LANG
 1  13394870  2015-01-10 21:43:39             aakash              accepted  0.16  1341M       JAVA
 2  13392496  2015-01-10 15:37:50            Utkarsh          wrong answer  0.00   7.5M   PYTH 2.7
 3  13391470  2015-01-10 13:21:17            Utkarsh          wrong answer  0.00   7.5M   PYTH 2.7
 4  13391442  2015-01-10 13:13:40            Utkarsh          wrong answer  0.00   7.5M   PYTH 2.7
 5  13390989  2015-01-10 12:01:18             aakash          wrong answer  0.16  1341M       JAVA
 6  13390787  2015-01-10 11:38:27             aakash          wrong answer  0.16  1341M       JAVA
 7  13390774  2015-01-10 11:37:04             aakash          wrong answer  0.10  1341M       JAVA
 8  13390718  2015-01-10 11:29:55             aakash  runtime error (NZEC)  0.10  1341M       JAVA
 9  13390707  2015-01-10 11:29:02             aakash     compilation error   N/A    N/A       JAVA
10  13390699  2015-01-10 11:28:00             aakash  runtime error (NZEC)  0.11  1341M       JAVA
11  13390691  2015-01-10 11:27:06             aakash     compilation error   N/A    N/A       JAVA
12  13390438  2015-01-10 10:59:55             aakash  runtime error (NZEC)  0.14  1341M       JAVA
13  13390423  2015-01-10 10:58:15             aakash     compilation error   N/A    N/A  C++ 4.3.2
14  13389991  2015-01-10 09:52:26             aakash  runtime error (NZEC)  0.15  1341M       JAVA
15  13272813  2014-12-26 15:28:37  Bijoy Rahman Arif          wrong answer  0.00   2.2M          C
16  13272302  2014-12-26 15:01:17  Bijoy Rahman Arif          wrong answer  0.00   2.2M          C
17  13271177  2014-12-26 14:11:06  Bijoy Rahman Arif          wrong answer  0.00   2.2M          C
18  13271154  2014-12-26 14:07:42  Bijoy Rahman Arif          wrong answer  0.00   2.2M          C
19  13270804  2014-12-26 13:21:45  Bijoy Rahman Arif          wrong answer  0.00   2.2M          C
20  13270641  2014-12-26 13:01:45  Bijoy Rahman Arif          wrong answer  0.01   2.2M          C

Uwagi

W zadaniu włączony jest sędzia dokładny!
