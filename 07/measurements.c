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
    Statistics stats = make_statistics(); // leere 'Statistics' Struktur wo alle Elemente 0 sind.

    int len = s_length(table);
    int pos = 0; // Wandert durch die gesamte Textdatei bzw. String

    int count_total = 0; // Anzahl aller Datensätze
    double sum_age = 0.0; // Summer aller Alterswerte
    double sum_age_sq = 0.0; // Summe aller Quadrate um Standardabweichung zu benutzen

    int count_m = 0;            //|        
    int count_t = 0;            //|
    int count_k = 0;            //|
                                //| =====> Anzahl der Einträge für bestimmtes Gerät (count_m, count_t, count_k) und Summe der Zeiten
    double sum_m = 0.0;         //|
    double sum_t = 0.0;         //|
    double sum_k = 0.0;         //|

    while (pos < len) {
        if (pos >= len) { // Schleife wird beendet, wenn wir das Ende des Strings erreichen
            break;
        }

        // 76-87 überspringt Leerzeichen, speichert Startposition, liest Zeilen bis zum nächsten Leerzeichen, schneidet den Substring aus dem Text und wandelt den Substring in ein Int
        while (pos < len && s_get(table, pos) <= ' ') {                 
            pos++;                                                      
        }                                                               
        
        int start = pos;                                                

        while (pos < len && s_get(table, pos) > ' ') {                  
            pos++;                                                      
        }                                                               

        String age_str = s_sub(table, start, pos);                      
        int age = i_of_s(age_str);                                      


        // 91-100 übersprint Leerzeichen, liest einzelnes Zeichen aus (m, t, k) um Gerätetyp zu lesen
        while (pos < len && s_get(table, pos) <= ' ') {
            pos++;
        }

        if (pos >= len) {
            break;
        }

        char device = s_get(table, pos);
        pos++;


        // 104-115 Leerzeichen übersrpingen, Start merken, bis zum nächsten Leerzeichen lesen, Substring extrahieren und in double umwandeln um Zeitwert für Gerätetyp zu lesen
        while (pos < len && s_get(table, pos) <= ' ') {
            pos++;
        }

        start = pos;

        while (pos < len && s_get(table, pos) > ' ') {
            pos++;
        }

        String time_str = s_sub(table, start, pos);
        double time = d_of_s(time_str);


        //119-121 Zählt alle Datensätze, sammelt alle Einträge für Alter um Summe zu berechnen, und macht dasselbe für die Quadrate um Standardabweichung
        count_total++;
        sum_age += age;
        sum_age_sq += (double)age * age;


        //125-136 Überprüfen welcher Gerätetyp vorliegt und dann Counter für den Typen erhöhen und dann die Summe des Typen mit dem Zeitwert zu addieren. Braucht man später um Mittelwert von jedem gerätetyp zu berechnen
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


    // 141-153 Altersstatistik berechnen. Durchschnittsalter und Standardabweichung
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


    // 157-176 Durschnittliche Zeit von Maus, Touchscreen und Tastatur berechnen, also Summe von Typ / Anzahl von Typ
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
