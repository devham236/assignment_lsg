#include "base.h"

String s_sub(String s, int i, int j) {
    require_not_null(s);
    int n = strlen(s);
    if (i < 0) i = 0;
    if (j > n) j = n;
    if (i >= j || i >= n || j <= 0) {
        char *a = xmalloc(1 * sizeof(char));
        a[0] = '\0';
        return a;
    }
    // assert i < j && i < n && j > 0
    n = j - i;
    char *a = xmalloc((n + 1) * sizeof(char));
    memcpy(a, s + i, n * sizeof(char));
    a[n] = '\0';
    return a;
}

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
    double age;
    double age_sd;
    double time;
} Statistics;

Statistics make_statistics() {
    // todo
    Statistics stats;

    stats.tech = 0;
    stats.age = 0.0;
    stats.age_sd = 0.0;
    stats.time = 0.0;

    return stats;
}

void print_statistics(Statistics s) {
    // todo
    printf("Age (Mean): %22.2f years\n", s.age);
    printf("Age (Std. Dev.): %17.2f years\n", s.age_sd);
    printf("Mean Time (Mouse): %15.2f s\n", s.tech);
    printf("Mean Time (Touchscreen): %9.2f s\n", s.tech);
    printf("Mean Time (Keyboard): %12.2f s\n", s.tech);
}

Statistics compute_statistics(String table) {
    // todo
    int table_length = s_length(table);
    int i = 0;
}

int main(void) {
    String table = s_read_file("measurements.txt");
    Statistics statistics = compute_statistics(table);
    print_statistics(statistics);
    return 0;

    /* 
        Erwartete Ausgabe:
        Age (Mean):                     37.33 years
        Age (Std. Dev.):                11.14 years
        Mean Time (Mouse):              16.00 s
        Mean Time (Touchscreen):        12.86 s
        Mean Time (Keyboard):           22.40 s
    */
}
