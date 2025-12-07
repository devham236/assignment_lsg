#include "base.h"

typedef struct {
    char mouse;
    char touchscreen;
    char keyboard;
} Tech;

typedef struct {
    int age
} Age;

typedef struct {
    double time;
} Time;

typedef enum {
    TAge,
    TTech,
    TTime
} Tag;

typedef struct statistics_s {
    // todo
    union stats
    {
        Tech tech;
        Age age;
        Time time;
    };
    
} Statistics;

Statistics make_statistics() {
    // todo
    Statistics stats;

    return stats;
}

void print_statistics(Statistics s) {
    // todo
}

Statistics compute_statistics(String table) {
    // todo
    Statistics stats;

    return stats;
}

int main(void) {
    String table = s_read_file("measurements.txt");
    Statistics statistics = compute_statistics(table);
    print_statistics(statistics);
    return 0;
}
