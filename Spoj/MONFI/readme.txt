source: http://pl.spoj.com/problems/MONFI/

MONFI - Montaż filmu

Jaś, bohater niezliczonej liczby matematycznych przygód, postanowił uciec od algorytmicznej codzienności. Porzucił swoje badania nad zagadnieniami optymalizacji, by zająć się tym, co go naprawdę fascynuje – tworzeniem filmów. Jako operator jednej z wielu kamer na imprezach okolicznościowych martwi się jedynie o jakość swoich zdjęć. Niestety, sielanka nie trwała zbyt długo. Dyrektor firmy w celu maksymalizacji przychodu zamierza wydawać możliwie najdłuższe filmy z każdej nakręconej imprezy. Problemem jest jednak wybór takich ujęć, przy których zachowana będzie kolejność wydarzeń i jednocześnie czas trwania filmu będzie największy. Z zadaniem tym mierzy się Janek, lecz nie jest pewny, czy znajduje najlepsze wyniki. Pomóż mu i napisz program, który wyznaczy długość najdłuższego filmu, jaki można zmontować z ujęć nakręconych przez Jasia i jego współpracowników.
Wejście

W pierwszym wierszu znajduje się liczba t - oznaczająca liczbę przypadków testowych (t ≤ 100).

Każdy przypadek testowy składa się z liczby n (1 ≤ n ≤ 105) – oznaczającej liczbę niepodzielnych ujęć nakręconych przez Jasia i jego współpracowników. Następnie n par liczb naturalnych a b (0 ≤ a < b ≤ 109) oznaczających, że do montażu filmu można wykorzystać ujęcie rozpoczynające się w milisekundzie a i kończące się w milisekundzie b.
Wyjście

Dla każdego przypadku testowego jedna liczba naturalna – długość najdłuższego filmu w milisekundach, jaki można zmontować z podanych ujęć.
Przykład

Wejście:

1
3
5 10
4 6
8 12

Wyjście:

6
