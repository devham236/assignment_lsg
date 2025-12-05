#include "base.h"

typedef enum Tag {
    TAge,
    TTech,
    TTime
} Tag;

typedef struct statistics_s {
    // todo
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
