# assignment_lsg
Für jede Aufgabe einen seperaten branch erstellen

## Explanations

### Structs
- Mit structs kannst du einen zusammengesetzten Datentyp erstellen, der mehrere Werte nebeneinander speichert.
- Am besten benutzen wenn du zusammengehörige Daten speichern willst, die unterschiedliche Typen haben, z.B Personen, Einstellungen usw.

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
