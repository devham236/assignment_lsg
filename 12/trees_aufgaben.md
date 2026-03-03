* [ ] Aufgabe 1 treePrint
  * Knoten auf der Konsole ausgeben, die sowohl über einen linken, als auch einen rechten Nachfolger verfügen und deren rechter Nachfolger größer ist als der linke Nachfolger. Nehmen Sie dabei an, dass der Baum unsortiert ist.
* [ ] Aufgabe 2 equalChildNodes
  * Schreiben Sie eine Methode, die überprüft, ob ein Child-Node in einem Binärbaum den gleichen Wert hat wie sein Parent-Node. Sie dürfen dazu eine Hilfsmethode schreiben. (Restliche Funktionalität des Binärbaums und Tests gegeben)
* [ ] Aufgabe 3 changingSign
  * Schreiben Sie eine Methode, die zurückgibt, wie häufig es Child- und Parent-Nodes gibt, bei denen sich das Vorzeichen unterscheidet.
* [ ] Aufgabe 4 zeroSumTree
  * Überprüft, ob Knotensumme im Baum == 0, also alle Knoten haben 0 als value oder komplett leer.
* [ ] Aufgabe 5 monoTree
  * Prüfe ob ein Binärbaum monoton ist (parent < children)
* [ ] Aufgabe 6 sumInnerNodes
  * Summe aller internen Knoten die Kindknoten haben
* [ ] Aufgabe 7 sumRightNodes
  * Summe aller rechten Nachfolger
* [ ] Aufgabe 8 heightTree
  * Berechne die Tiefe eines Baumes.
* [ ] Aufgabe 9 arithmeticTree
  * Ergebnis eines arithmetischen Baumes berechnen. Im Knoten stehen Zahlen oder Operatoren
* [ ] Aufgabe 10 donkeys
  * Gewichte gleichmäßig auf Eselrücken verteilen
    * Tasche rechts, links
* [ ] Aufgabe 11 quadSumTree
  * Linkes Kinder mit Rechtem tauschen und den Value quadrieren und in einen neuen Baum speichern
* [ ] Aufgabe 12 iterSumTree
  * Summe eines Baumes iterativ berechnen, groben Algorithmus aufschreiben
* [ ] Aufgabe 13 sumWithoutLeafs
  * Summe aus Tree bilden ohne die Blätter (left and right==NULL)
* [ ] Aufgabe 14 innerNodeSum
  * Berechnen der Summe von inneren Tree Nodes
* [ ] Aufgabe 15 treeToList
  * Baum in zwei Listen sortieren per Pointer. Alles kleiner als Grenze=Klein. Rest=Groß
* [ ] Aufgabe 16 childParentDifference
  * Durch einen Baum gehen und zählen wie oft Kinder einen anderen Wert als Elternknoten hatten (Rekursiv)
* [ ] Aufgabe 17 treeLevel
  * [ ] Implementieren Sie die Funktion "int levels(Tree \*tree)", die zurückgibt, wie hoch ein Baum ist. Dabei hat ein leerer Baum (tree == NULL) die Höhe 0, ein Baum ohne Nachfolger (tree->left == NULL && tree->right == NULL) die Höhe 1 usw. Die Implementierung sollte auch für asymmetrische Bäume gelten. Wenn ich mich richtig erinnere, gab es keine min/max stack/queue Hilfsfunktionen - [ ] die musste man ggf. selbst implementieren.
  * [ ] (Nicht mehr ganz sicher, ungefähr so): implementieren Sie eine Funktion "void count_leaves_per_level(Tree \*tree, int level, int \*results)", die die Anzahl an Blättern einer n-ten Ebene zählt und diesen Wert dann in das n-te Element des übergebenen results-Arrays schreibt. Als Blatt zählen Knoten, die keine Nachfolger haben. In den Testfällen gab es symmetrische, asymmetrische und leere Bäume.
* [ ] Aufgabe 18 sortTree
  * Binärbaum geordnet ausgeben. Also erst den Linken dann den Rechten Teil -->inOrderPrint.
* [ ] Aufgabe 19 sumTree
  * Summe in einem Tree bilden. Es dürfen nur alle Knoten gerechnet werden die mindestens einen Nachfolger haben (Wenn z.B. t->right noch mind. einen Nachfolger ungleich NULL hat -> mitrechnen
* [ ] Aufgabe 20 sameParentChildValue
  * Anzahl der Knoten in einem Baum die den selben Wert wie ihre Eltern haben
* [ ] Aufgabe 21 greatestPathValue
  * Aus einem Tree den Pfad mit dem größten Wert ausgeben
* [ ] Aufgabe 22 lowLevelLeaf
  * Das Leaf mit dem niedrigsten Level in einer Baumstruktur berechnen