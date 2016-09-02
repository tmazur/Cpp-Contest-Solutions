source: http://www.spoj.com/ALGOLIGA/problems/AL_29_05/



Twoim zadaniem jest stworzenie modułu systemu DOS, który będzie podpowiadał użytkownikowi jakie polecenia są dostępne w systemie. Komponent ten powinien umożliwiać wykonanie 3 typów operacji:

    add b - dodaje polecenie b do bazy dostępnych poleceń
    remove b - usuwa polecenie b z bazy dostępnych poleceń
    list b - wyświetla listę dostępnych poleceń, których prefiksem jest b

Wynik operacji list b powinien być następujący:

b: p1 p2 ...

gdzie p1, p2, ... to polecenia o prefiksie b podane w kolejności alfabetycznej. W przypadku gdy liczba znalezionych komend jest większa niż m wypisujemy tylko m pierwszych w kolejności alfabetycznej zaś na końcu listy dopisujemy and c other(s). Wartością c jest liczba pominiętych poleceń o prefiksie b.
Wejście

W pierwszej linii wejścia znajdują się dwie liczby całkowite x ∈ [1;105] oraz m ∈ [1;8] oznaczające odpowiednio liczbę operacji do wykonania oraz maksymalną liczbę poleceń wyświetlanych dla operacji list.

W kolejnych x liniach znajdują się działania do wykonania zgodne z formatem podanym w treści zadania. Parametrem każdej z operacji jest pojedynczy wyraz składający się z małych liter alfabetu angielskiego, którego długość nie przekracza 8 znaków. Gwarantujemy, że w przypadku operacji add komenda b nie jest aktualnie dodana do bazy, zaś w przypadku operacji remove polecenie b na pewno znajduje się w bazie.
Wyjście

Dla każdego polecenia list b należy wypisać listę poleceń o prefiksie b zgodnie z formatem podanym w treści zadania.
Przykład

Wejście:

20 3
add copy
add move
add dir
add chkdsk
list c
list d
list m
remove chkdsk
add chdir
list ch
list attr
add attrib
list attr
add chcp
add chkdsk
list chd
list ch
list c
remove chcp
list c

Wyjście:

c: chkdsk copy
d: dir
m: move
ch: chdir
attr:
attr: attrib
chd: chdir
ch: chcp chdir chkdsk
c: chcp chdir chkdsk and 1 other(s)
c: chdir chkdsk copy
