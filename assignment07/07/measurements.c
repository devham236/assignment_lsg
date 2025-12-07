#include "base.h"

typedef enum {
    m,
    t,
    k
} Tech;

typedef struct {
    Tech tech;
} TechStruct;

typedef struct Age{
    int age;
} Age;

typedef struct Time{
    double time;
} Time;

typedef enum {
    TAge,
    TTech,
    TTime
} Tag;

typedef struct statistics_s {
    // todo
    Tech tech;
    Age age;
    Time time;
    
} Statistics;

Statistics make_statistics() {
    // todo
    Statistics stats;

    stats.tech = 0;
    stats.age.age = 0;
    stats.time.time = 0.0;

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
