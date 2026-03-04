/*
Compile: make is_search_tree
Run: ./is_search_tree
Compile & run: make is_search_tree && ./is_search_tree
*/

#include "base.h"

/*
Jede Node bzw. jeder Knoten hat einen Wert, einen linken Kindknoten und einen rechten Kindknoten.
"left" und "right" sind daher auch vom Typ her ein Node pointer.
Man muss hier pointer verwenden weil du bei einem normalen Node struct als Typ, eine unendliche Rekursion hast und dadurch unendlich viel Speicher belegen würdest.
Der Compiler würde dann schauen, ein "Node" hat ein int (4 Byte) und zwei weitere Nodes, jedes dieser zwei Nodes hat ein int und zwei weitere Nodes. Diese zwei Nodes haben wieder jeweils ein int und zwei weiter nodes usw.
Pointer haben eine feste Größe und es ist egal worauf er zeigt, es ist nur eine Adresse.
Compiler weiß dann, ein Node hat ein int (4 Byte) und zwei Adressen (ungefähr 8 Byte jeweils).

*/
typedef struct Node
{
	int value;
	struct Node *left;
	struct Node *right;
} Node;

/*
Zunächst wird Speicher für einen Knoten reserviert (xmalloc), das Ergebnis von diesem xmalloc Befehl ist die Adresse dieses Knoten, den wir dann in "Node *node" speichern.
Der Compiler weiß dann durch den Typ "Node*", dass am Ende dieser Adresse ein struct vom Typ Node liegt, obwohl "node" nur ein Pointer auf eine Adresse ist und dadurch kann man mit "node->left" und "node->right" auf die einzelnen Member der Node Instanz zugreifen.
*/
Node *new_node(Node *left, int value, Node *right)
{
	Node *node = xmalloc(sizeof(Node));
	node->left = left;
	node->value = value;
	node->right = right;
	return node;
}

void free_node(Node *node)
{
	if (node)
	{
		free_node(node->left);
		free_node(node->right);
		node->left = NULL;
		node->right = NULL;
		free(node);
	}
}

void print_node(Node *node)
{
	if (node == NULL)
	{
		printf("E");
	}
	else
	{
		printf("Node(");
		print_node(node->left);
		printf(", %d, ", node->value);
		print_node(node->right);
		printf(")");
	}
}

int min_int(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}

int max_int(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

/*
Das Tree struct hat nur "root" Node als Member, also die Wurzel des Baumes.
root ist ein Node pointer, also ein Pointer der auf eine Adresse zeigt, wo etwas liegt das vom Typ her eine "Node" Struktur ist.
*/
typedef struct
{
	Node *root;
} Tree;

/*
Ähnlich wie bei new_node musst du für einen neuen Baum, erstmal Speicher reservieren. Tree ist ein struct mit nur einem Node pointer "root".
Der erste übergebene Node pointer bildet dann deine Wurzel.
"value" von Node wir dann zu "root" vom Tree.
*/
Tree *new_tree(Node *root)
{
	Tree *tree = xmalloc(sizeof(Tree));
	tree->root = root;
	return tree;
}

void free_tree(Tree *tree)
{
	if (tree)
	{
		free_node(tree->root);
		tree->root = NULL;
		free(tree);
	}
}

void print_tree(Tree *tree)
{
	printf("Tree: ");
	if (tree)
		print_node(tree->root);
	printf("\n");
}

/** Returns true if this is a search tree. Returns false otherwise.
 * May need a helper method. */
bool is_search_tree(Tree *tree)
{
	return true;
}

/*
Pre-Order, In-Order und Post-Order kennst du schon von DUA. Wenn das print vor den rekursiven Aufrufen steht
dann ist es Pre-Order, wenn es zwischen den Aufrufen steht dann ist es In-Order und wenn es nach den Aufrufen steht dann ist es Post-Order.

Rekursive Funktionen rufen sich selber auf, speichern pausierte Funktionsaufrufe im "Call Stack" und brauchen immer eine Abbruchbedingung.
Zum Beispiel:
new_node(new_node(NULL, 10, NULL), 20, new_node(NULL, 30, NULL)) würde einen Knoten erstellen der so aussieht:

		20
	   /  \
	 10    30
	/  \  /  \
   N   N N    N

- Die Funktion wird für den Knoten 20 aufgerufen
- node ist nicht NULL
- print_in_order(node->left) wird ausgeführt, also "gehe zur 10, links von der 20"
- Die 20 pausiert jetzt und wartet

- Neue Instanz der Funktion mit dem Knoten 10 startet
- node ist nicht NULL
- print_in_order(node->left) wird ausgeführt, also "gehe zum linken NULL von 10"
- Die 10 pausiert und wartet

- Funktion startet mit NULL
- node ist gleich NULL
- Die Funktion macht "return", wird also beendet.

- Wir sind jetzt wieder zurück bei der Funktionsinstanz mit der 10
- print Befehl wird ausgeführt und die 10 wird ausgegeben.
- print_in_order(node->right) wird ausgeführt, also "gehe zum rechten NULL von 10"
- Der Aufruf von NULL returned wieder und man ist zurück bei der 10
- Der Aufruf mit der 10 ist jetzt beendet

- Wir sind jetzt wieder bei der Funktionsinstanz mit der 20
- print Befehl wird ausgeführt und die 20 wird ausgegeben.
- print_in_order(node->right) wird ausgeführt, also "gehe zur 30, rechts von der 20"
- Die 20 pausiert wieder und wartet.

- Funktion startet mit der 30
- node ist nicht NULL
- print_in_order(node->left) wird ausgeführt, also "gehe zu NULL, links von der 30"
- Kommt direkt wieder zurück, weil node == NULL ist.
- print Befehl wird ausgeführt und die 30 wird ausgegeben.
- print_in_order(node->left) wird ausgeführt, also "gehe zu NULL, rechts von der 30"
- Kommt direkt wieder zurück
- Aufruf mit 30 ist beendet

- Wir sind wieder bei der 20
- Hier kommt auch nichts mehr
- Gesamter Funktionsaufruf beendet
*/

void print_in_order(Node *node)
{
	if (node == NULL)
	{
		return;
	}

	print_in_order(node->left);

	printf("%d, ", node->value);

	print_in_order(node->right);
}

void test()
{
	Tree *t = new_tree(NULL);
	test_equal_b(is_search_tree(t), true);
	free_tree(t);

	t = new_tree(new_node(NULL, 100, NULL));
	test_equal_b(is_search_tree(t), true);
	free_tree(t);
	/*
		100
		/ \
	NULL   NULL
	*/

	t = new_tree(new_node(new_node(NULL, 99, NULL), 100, new_node(NULL, 101, NULL)));
	test_equal_b(is_search_tree(t), true);
	free_tree(t);
	/*
		100
		/ \
	  99   101
	 /  \  /  \
	 N  N  N  N
	*/

	t = new_tree(new_node(new_node(NULL, 101, NULL), 100, new_node(NULL, 99, NULL)));
	test_equal_b(is_search_tree(t), false);
	free_tree(t);
	/*
		100
		/ \
	 101    99
	 /  \  /  \
	 N  N  N  N
	*/

	t = new_tree(new_node(new_node(NULL, 101, NULL), 100, new_node(NULL, 199, NULL)));
	test_equal_b(is_search_tree(t), false);
	free_tree(t);
	/*
		100
		/ \
	 101   199
	 /  \  /  \
	 N  N  N  N
	*/

	t = new_tree(new_node(new_node(new_node(NULL, 6, NULL), 7, new_node(NULL, 9, NULL)), 8, NULL));
	test_equal_b(is_search_tree(t), false);
	free_tree(t);
	/*
		 8
		/ \
	   7    N
	 /  \  /  \
	 6   9  N  N
	/ \  /\
   N   N N N
	*/

	t = new_tree(new_node(new_node(NULL, 11, NULL), 100, new_node(NULL, 99, NULL)));
	test_equal_b(is_search_tree(t), false);
	free_tree(t);
	/*
		100
		/ \
	  11   99
	 /  \  /  \
	 N  N  N  N
	*/

	t = new_tree(new_node(new_node(new_node(NULL, 25, NULL), 50, new_node(NULL, 75, NULL)), 100, new_node(new_node(NULL, 125, NULL), 150, new_node(NULL, 175, NULL))));
	test_equal_b(is_search_tree(t), true);
	free_tree(t);

	t = new_tree(new_node(new_node(new_node(NULL, 55, NULL), 50, new_node(NULL, 75, NULL)), 100, new_node(new_node(NULL, 125, NULL), 150, new_node(NULL, 175, NULL))));
	test_equal_b(is_search_tree(t), false);
	free_tree(t);

	t = new_tree(new_node(NULL, 101, new_node(NULL, 100, NULL)));
	test_equal_b(is_search_tree(t), false);
	free_tree(t);

	t = new_tree(new_node(new_node(NULL, 50, NULL), 100, NULL));
	test_equal_b(is_search_tree(t), true);
	free_tree(t);

	Node *n = new_node(new_node(NULL, 10, NULL), 20, new_node(NULL, 30, NULL));
	print_in_order(n);
	free_node(n);
}

int main(void)
{
	report_memory_leaks(true);
	test();
	return 0;
}
