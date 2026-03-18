* [ ] Aufgabe 1 arrayBubbleSort
  * Array mit bubbleSort sortieren
* [ ] Aufgabe 2 arrayAnalyzer
  * 2D-Matrix mit Buchstaben und - gegeben, Anzahl der gegebenen chars pro Spalte in 1D-Array speichern Eingabe 2D Array, a a - a a --> 3 b - - - --> 0 --> [3,0] Rückgabe Array
* [ ] Aufgabe 3 polynoms
  * (Original-Formulierung war sehr kompliziert und abschreckend, sinngemäß war folgendes gefordert): implementieren Sie die Funktion "void derive\*polynoms(int \*polynoms, int \_results)", die Ableitung der Polynome aus dem polynoms-Array in das results-Array schreibt. Hört sich erstmal schrecklich kompliziert anschauen wir uns an, was die eigentlich von uns wollen: ein Array { 1, 2, 3 } bspw. soll "übersetzt" bedeuten f(x) = 1 \_ x⁰ + 2 \_ x¹ + 3 \_ x². Leitet man das ab, erhält man f'(x) = 2 \_ x⁰ + 6 \* x¹. Das results-Array soll also für results[0] die 2 enthalten und für results[1] die 6. Angegeben waren noch weitere Testfälle, die allesamt aber ähnlich waren. Kann mich an keinen "komplizierten" Testfall erinnern. Im Endeffekt war das ein 3-Zeiler - [ ] wenn man sich von der zunächst kompliziert erscheinenden Aufgabenstellung nicht abschrecken ließ. Zusatzbemerkungen: als Editor musste kWrite eingesetzt werden. Als Desktop- Umgebung wurde GNOME 3 (Linux) verwendet. Die Kompilierung erfolgte mittels Makefiles. Die gesamte Klausur war lösbar, ohne dass man selbst irgendeine prog1lib-Funktion verwenden musste.
* [ ] Aufgabe 4 intOption

Struktur zurückgeben die den kleinsten Wert aus dem Intervall enthält. In einem Intervall [from, to] den kleinsten Integer Wert finden für den i == 3 ist oder (je nach Angabe f oder g im Testfall) i >= 1000 und zurückgeben. Gegeben waren in den Testfällen (P p, int from, int to), wobei p f oder b war. from = Untere Grenze des Intervalls, to = obere Grenze des Intervalls. Einmal von from bis to durchlaufen und falls p == f ist, sollte als IntOption op = {true, i) wenn f(i) == 3 ist zurückgegeben werden, falls p == f und g(i) >= 1000 sollte IntOption op = {true, i) zurückgegeben werden. Falls keine Zahl gefunden werden konnte sollte {false, 0} zurückgegeben werden.

Bsp Testfall: (f, 0, 4) liefert {true, 3} (f, 10, 20) liefert {false, 0} (g, 999, 10000) liefert {true, 1000}

* [ ] Aufgabe 5 col_prod

Berechne das Produkt jeder Spalte einer Matrix und gib das Ergebnis als Array zurück. Das Array soll dynamisch erzeugt werden.

int\* col_prod(int\* a, int rows, int cols) {}

void test(void) {

```
int a[3][3] = {

    { 1, 2, 3 },

    { -1, -2, -3 },

    { 3, 4, 5 },

};
```

int test[3] = {-3, -16, -45}

}