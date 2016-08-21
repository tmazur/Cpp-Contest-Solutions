source: http://pl.spoj.com/problems/MWP4_3B/

Runda finałowa budzi na ogół najwięcej emocji wśród uczestników konkursu, w końcu oprócz czystej przyjemności rozwiązywania zadań można zdobyć cenne nagrody. Niestety sprawa wygląda zupełnie inaczej dla organizatorów - zmuszeni są siedzieć 5 godzin na niewygodnych krzesłach, gapiąc się w monitory... Nic więc dziwnego, że usypiają po określonym czasie. Jedyne co potrafi wyrwać z letargu i uchronić przed uśnięciem organizatorów to zgłoszenia ze statusem AC (oraz początek i koniec zawodów). Za każdym razem kiedy takie zgłoszenie dociera na serwer organizatorzy rozbudzają się i wpadają w stan niesamowitej euforii który trwa nieskończenie krótką chwilę. Gdy emocje już opadną organizatorzy znów zaczynają błogo przysypiać. Profesora, który patronuje konkursowi, niezwykle interesuje czy studenci (jak to mają w zwyczaju) niczego nie kombinowali. Po zakończeniu imprezy zebrał wszystkie zgłoszenia i poprosił Ciebie abyś napisał program, który obliczy czy w trakcie finału, organizatorom zdarzyło się przysnąć. Jeżeli odpowiedź brzmi TAK program powinien wypisać ile czasu spali (jeżeli zasnęli więcej niż jeden raz wypisz czas najdłuższej drzemki). Zakładamy, że finał rozpoczął się o godzinie 9:00 i trwał do godziny 14:00.
Wejście

W pierwszej linii wejścia znajduje się dokładnie jedna liczba całkowita Z (1 ≤ Z ≤ 10000) określająca liczbę zestawów danych.

Pierwszą linię każdego zestawu danych stanowi liczba S (1 ≤ S ≤ 1800) opisująca liczbę zgłoszeń jakie wysłane zostały przez finalistów. W drugiej linii każdego zestawu znajduje się czas po jakim organizatorzy zasypiają (w przypadku gdy nie ma zgłoszenia ze statusem AC, po którym należy zacząć liczyć ten czas od nowa) zapisany w formacie hh:mm:ss. W kolejnych S liniach znajdują się opisy zgłoszeń: godzina o jakiej zgłoszenie napłynęło (również w formacie hh:mm:ss) i jego wynik. Możliwe rezultaty zgłoszenia to CE, RE, TLE, WA oraz AC.
Wyjście

Dla każdego zestawu danych należy wypisać w osobnej linii czas najdłuższej drzemki w formacie hh:mm:ss albo 0 w przypadku gdy organizatorom nie dane było pospać.
Przykład

Wejście:

1
8
00:55:20
09:32:21 WA
09:40:35 TLE
09:50:40 AC
11:35:32 TLE
12:35:20 AC
12:42:34 TLE
13:27:13 WA
13:55:30 AC

Wyjście:

01:49:20
