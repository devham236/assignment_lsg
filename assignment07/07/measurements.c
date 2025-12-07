#include "base.h"

typedef enum {
    m,
    t,
    k
} Tech;

typedef enum {
    TAge,
    TTech,
    TTime
} Tag;

typedef struct statistics_s {
    // todo
    Tech tech;
    int age;
    double time;
    
} Statistics;

Statistics make_statistics() {
    // todo
    Statistics stats;

    stats.tech = 0;
    stats.age = 0;
    stats.time = 0.0;

    return stats;
}

void print_statistics(Statistics s) {
    // todo
    printf("Eingesetztes Gerät der Versuchsperson (Maus(m)/Touchscreen(t)/Tastatur(k)): %d\n", s.tech);
    printf("Alter der Versuchsperson: %d\n", s.age);
    printf("Benötigte Zeit um Eingabe zu tätigen: %.2f\n", s.time);
}

Statistics compute_statistics(String table) {
    // todo
    Statistics stats;

    printf("%s\n", table);

    return stats;
}

int main(void) {
    String table = s_read_file("measurements.txt");
    Statistics statistics = compute_statistics(table);
    print_statistics(statistics);
    return 0;
}
