* [ ] Aufgabe 1 ascendingNumbersinString
  * Schreiben Sie eine Funktion, die überprüft, ob in einem String 4 aufeinanderfolgende aufsteigende Zahlen auftreten. Beispielsweise "as5678e". (main Funktion mit Tests gegeben)
* [ ] Aufgabe 2 wildCardMatch hom
  * Prüfen ob ein string t in einem string s vorkommt. string t kann zudem m '?' als wildchar (beliebiger character) erhalten Bei den Testfällen gab es zudem den Fall dass der String '' geprüft werden musste - mit dem erwarteten Ergebnis true. '' Ist die binäre Null, der String ist damit nicht leer... Dazu die Abfrage t[0] == '\\0'
* [ ] Aufgabe 3 sequencePosition
  * Implementieren Sie die Funktion in sequencePosition(String s, String t). Diese soll die Indexposition des ersten Auftretens von t in s zurückgeben(-1 falls t nicht in s vorkommt). Dabei sind '?' Jokerzeichen(wildcards). Ein ? in t bedeutet, dass das zugehörige Zeichen in s ein beliebiges(einzelnes) Zeichen sein darf.
* [ ] Aufgabe 4 firstEqualsLast
  * firstEqualsLast(String s) Gibt true zurück, wenn das erste und letzte Zeichen im String gleich sind
* [ ] Aufgabe 5 repeatingChar
  * wie oft der gleiche Buchstabe im String vorkommt
* [ ] Aufgabe 6 camelcase hom
  * strings mit xmalloc kopieren über string laufen und alle lowercases in string direkt übergeben, leerzeichen auch, uppercases je nach position übergeben oder zu "_x" transformieren. die zusätzliche größenveränderung beim allocieren natürlich vorher beachten
  * Originalstring nicht verändern
  * Rückgabestring dynmanisch allokieren
  * Hilfsfunktionen
    * is_letter()....
    * is_upper()....
    * is_lower()....
    * to_upper()...
    * to_lower()...
  * Uppercase zu Lowercase
  * nur wenn Uppercase _ untermische und und die innere Buchstabe zu lowercase
  * Beispiele
    * abcd --> abcd
    * Abcd --> Abcd
    * ABCD --> A_b_c_d
    * ABCDEF --> A_b_c_d_e_f
    * ABCD EF --> A_b_c_d E_f
* [ ] Aufgabe 7 removeletters
  * nur mit hilfsfunktionen strings in exakt größen allokierten copy string übertragen, alles was letters sind ignorieren.
  * Zahlen aus String rausschreiben
  * Originalstring nicht verändern
  * Rückgabestring dynmanisch allokieren
  * nur Hilfsfunktionen verwenden und xmalloc
    * is_letter
    * s_length
  * Beispiele
    * " " --> " "
    * "abc " --> " "
    * "1abc" --> "1"
    * "x11" --> "11"
    * "1a2b3c4d" --> "1234"
* [ ] Aufgabe 8 autoCorrectCases
  * ersten Buchstaben eines Wortes groß den Rest klein
    * Eingabe: HELLO WORLD
    * Ausgabe: Hello World
* [ ] Aufgabe 9 reverseString
  * Strings in einer Liste reversen
* [ ] Aufgabe 10 removeChars
  * Chars aus einem String entfernen
* [ ] Aufgabe 11 stringDifference
  * 2 Strings gegeben.
  * Alle chars die in String 1 vorkommen, aber nicht in String 2 in einen neuen allokierten String übergeben
* [ ] Aufgabe 12 countedUpperLower
  * String war gegeben. Sollte abwechselnd zu Upper und Lowercase gemacht werden mit bestimmter Anzahl (Also z.B. 2 Groß, 2 Klein)
* [ ] Aufgabe 13 countString
  * Implementieren Sie die Funktion "int count_target_string(char \*text, char \*string)", die zählt, wie oft "string" in "text" vorkommt. Es darf nur gezählt werden, wenn "string" von Leerzeichen umschlossen wird bzw. wenn es am Ende / am Anfang steht. Gehen Sie davon aus, dass nur Kleinbuchstaben und Leerzeichen vorkommen. Sie dürfen nur selbst programmierte Hilfsfunktionen und strlen() und strncmp() verwenden. Beispiele (Testfälle waren in der .c-Datei bereits programmiert): count_target_string("abc of", "of") -> 1 count_target_string("abcof", "of") -> 0 count_target_string("ofabc", "of") -> 0 count_target_string("of abc", "of") -> 1 count_target_string("abc of abc of", "of") -> 2
* [ ] Aufgabe 14 rot3
  * Verschlüsselung von Buchstaben in einem String (Caesar Alg). Alle Kleinbuchstaben(!) sollten um 5 chars verschoben werden (War so ziemlich das gleiche wie in Assignment 6 glaube ich) Nur s_length/xmalloc/strlen
* [ ] Aufgabe 15 trimString
  * Leerzeichen am Anfang/Ende eines Strings entfernen. Es darf nur s_length/xmalloc/strlen verwendet werden aus der prog1lib (Also kein s_trim)
* [ ] Aufgabe 16 shortestOrder
  * Aus einem String die Länge der kürzesten Folge des Char c finden. Dazu noch Funktion schreiben die herausfindet ob der String mit einer Ziffer beginnt.
* [ ] Aufgabe 17 printStrings
  * Es sind 2 Strings gegeben, wenn der eine in dem anderen vorkommt, soll der String nach dem anderen String ausgegeben werden, sonst der ursprüngliche String. Mit allokieren
* [ ] Aufgabe 18 maxOneChar
  * Prüfen ob String mit : anfängt oder aufhört, maximal 1x: hat, sonst nur aus kleinen Buchstaben besteht und mindestens einen kleinen Buchstaben hat
* [ ] Aufgabe 19 slashRemover
  * Für *buchstabe neuen String allokieren und "*" entfernen und den ersten Buchstaben nach "_" groß Schreiben.
* [ ] Aufgabe 20 ßtoDoubleS
  * ss in einem String mit ß ersetzen. const String sz = „ß“ war gegeben. Anmerkung in der Aufgabe: strlen(ß) = 2. inplace oder neu allokieren, mit strcpy()