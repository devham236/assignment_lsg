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

typedef struct statistics_s {
    double age;
    double age_sd;

    double mean_m;
    double mean_t;
    double mean_k;

} Statistics;

Statistics make_statistics() {
    // todo
    Statistics s;
    s.age = 0;
    s.age_sd = 0;
    s.mean_m = 0;
    s.mean_t = 0;
    s.mean_k = 0;
    return s;
}

void print_statistics(Statistics s) {
    // todo
    printf("Age (Mean): %22.2f years\n", s.age);
    printf("Age (Std. Dev.): %17.2f years\n", s.age_sd);
    printf("Mean Time (Mouse): %15.2f s\n", s.mean_m);
    printf("Mean Time (Touchscreen): %9.2f s\n", s.mean_t);
    printf("Mean Time (Keyboard): %12.2f s\n", s.mean_k);
}

Statistics compute_statistics(String table) {
    // todo
    Statistics stats = make_statistics();

    int len = s_length(table);
    int pos = 0;

    int count_total = 0;
    double sum_age = 0.0;
    double sum_age_sq = 0.0;

    int count_m = 0;
    int count_t = 0;
    int count_k = 0;

    double sum_m = 0.0;
    double sum_t = 0.0;
    double sum_k = 0.0;

    while (pos < len) {

        while (pos < len && s_get(table, pos) <= ' ') {
            pos++;
        }

        if (pos >= len) {
            break;
        }

        int start = pos;

        while (pos < len && s_get(table, pos) > ' ') {
            pos++;
        }

        String age_str = s_sub(table, start, pos);
        int age = i_of_s(age_str);

        while (pos < len && s_get(table, pos) <= ' ') {
            pos++;
        }

        if (pos >= len) {
            break;
        }

        char device = s_get(table, pos);
        pos++;

        while (pos < len && s_get(table, pos) <= ' ') {
            pos++;
        }

        start = pos;

        while (pos < len && s_get(table, pos) > ' ') {
            pos++;
        }

        String time_str = s_sub(table, start, pos);
        double time = d_of_s(time_str);

        count_total++;
        sum_age += age;
        sum_age_sq += (double)age * age;

        if (device == 'm') {
            count_m++;
            sum_m += time;
        }
        else if (device == 't') {
            count_t++;
            sum_t += time;
        }
        else if (device == 'k') {
            count_k++;
            sum_k += time;
        }
    }

    if (count_total > 0) {
        stats.age = sum_age / count_total;

        double mean_sq = sum_age_sq / count_total;
        double variance = mean_sq - stats.age * stats.age;

        if (variance > 0.0) {
            stats.age_sd = sqrt(variance);
        }
        else {
            stats.age_sd = 0.0;
        }
    }

    if (count_m > 0) {
        stats.mean_m = sum_m / count_m;
    }
    else {
        stats.mean_m = 0.0;
    }

    if (count_t > 0) {
        stats.mean_t = sum_t / count_t;
    }
    else {
        stats.mean_t = 0.0;
    }

    if (count_k > 0) {
        stats.mean_k = sum_k / count_k;
    }
    else {
        stats.mean_k = 0.0;
    }

    return stats;
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
