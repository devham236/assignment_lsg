# Explanations

### Structs
- Mit structs kannst du einen zusammengesetzten Datentyp erstellen, der mehrere Werte nebeneinander speichert.
- Am besten benutzen wenn du zusammengehörige Daten speichern willst, die unterschiedliche Typen haben, z.B Personen, Einstellungen usw.
- Jedes Element hat seinen eigenen Speicherbereich, alle Elemente existieren also gleichzeitig.

```c
struct Person {
    char name[50];
    int age;
};
```

- Um diesen struct zu verwenden schreibst du das hier:

```c
struct Person p;
```

- Dieses **typedef** veinfacht die Benutzung von diesem struct. Wenn du es also verwenden möchtest, kannst du das "struct" keyword weglassen und direkt den Nmane des structs verwenden.

```c
typedef struct {
    char name[50];
    int age;
} Person;
```

```c
Person p;
```

### Enums

- Mit Enums (Aufzählungen) kannst du Int Werten einen Namen geben.
- Ist gut geeignet um Zustände zu beschreiben

```c
enum Color {
    RED,
    GREEN,
    BLUE
}

// RED = 0, GREEN = 1, BLUE = 2

enum Color f = BLAU;

```

### Unions

- Unions sind ähnlich wie structs, aber alle Elemente teilen sich denselben Speicherbereich.
- Union ist also so groß wie ihr größtes Element.
- Es existiert also immer nur ein Element zur Verwendung.
- Gut geeignet für Variablen die unterschiedliche Typen enthalten sollen, aber nicht gleichzeitig.

```c
union Data {
    int i;
    float f;
    char c;
};

union Data d;
d.i = 42;
d.f = 3.14; 
```
