/*
Compile: make people
Run: ./people
make people && ./people
*/

#include "base.h"

// Represents statistics of a people table.
struct Statistics {
	int mean_year;
	int number_males;
	int number_females;
	int number_diverse;
	double mean_height_males; // in m
	double mean_height_females; // in m
	double mean_height_diverse; // in m
	double mean_length_of_names;
};

typedef struct Statistics Statistics;


//Returns substring of s from character i to character j
String s_sub(String s, int i, int j) {
    require_not_null(s); // prüft ob s nicht null ist
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


Statistics make_statistics(void) { // erstellt eine leeres Blatt
	Statistics ps = { 0, 0, 0, 0, 0.0, 0.0, 0.0 };
	return ps;
}

void print_statistics(Statistics s) {
	printf("mean year: %d\n", s.mean_year);
	printf("number males: %d\n", s.number_males);
	printf("number females: %d\n", s.number_females);
	printf("number diverse: %d\n", s.number_diverse);
	printf("mean height males: %.2f\n", s.mean_height_males);
	printf("mean height females: %.2f\n", s.mean_height_females);
	printf("mean height diverse: %.2f\n", s.mean_height_diverse);
	printf("mean length of names: %3.2f characters\n", s.mean_length_of_names);

}

Statistics compute_statistics(String table) {
	Statistics ps = make_statistics();
	int n = s_length(table);
	int i = 0; //aktuelle Position im String
	
	while (s_get(table, i) != '\n') i++; // skip first row
	
		int total_birth_year = 0;
        double total_male_height = 0.0;
        double total_female_height = 0.0;
        double total_diverse_height = 0.0;
        int total_male_name_length = 0;
        int total_female_name_length = 0;
        int total_diverse_name_length = 0;
        int person_count = 0;

        // Hauptschleife
        while (i < n) {

			// start der Zeile
            int line_start = i;
            int line_end = line_start;

            // Ende der Zeile finden
            while (line_end < n && s_get(table, line_end) != '\n') ++line_end;
            String line = s_sub(table, line_start, line_end); // Zeile extrahieren
            i = line_end + 1; // Nächste Zeile 

            // Tabs in der Zeile finden
			int first_tab = -1, second_tab = -1, third_tab = -1;
            for (int j = 0; j < s_length(line); ++j) {
                if (s_get(line, j) == '\t') {
                    if (first_tab == -1) first_tab = j;
                    else if (second_tab == -1) second_tab = j;
                    else {
                        third_tab = j;
                        break;
                    }
                }
            }

            // Ignoriert falls keine 3 Tabs vorhanden sind
            if (first_tab == -1 || second_tab == -1 || third_tab == -1) {
                free(line);
                continue;
            }

            // Felder aus der Zeile extrahieren
            String birth_year_str = s_sub(line, 0, first_tab);
            String gender = s_sub(line, first_tab + 1, second_tab); //+1 to move past tab
            String height_str = s_sub(line, second_tab + 1, third_tab);
            String name = s_sub(line, third_tab + 1, s_length(line));

            // macht aus string int oder double
            int birth_year = i_of_s(birth_year_str);
            double height = d_of_s(height_str);

            // zusammenzählen
            total_birth_year += birth_year;
            person_count++;

            // werte zu geschlechtern
            if (gender[0] == 'm') {
                ps.number_males++;
                total_male_height += height;
                total_male_name_length += s_length(name);
            } else if (gender[0] == 'f') {
                ps.number_females++;
                total_female_height += height;
                total_female_name_length += s_length(name);
            } else if (gender[0] == 'd') {
                ps.number_diverse++;
                total_diverse_height += height;
                total_diverse_name_length += s_length(name);
            }

            // reservier Speicher
            free(birth_year_str);
            free(gender);
            free(height_str);
            free(name);
            free(line);
        }

        // Durchschnittswerte
        ps.mean_year = person_count > 0 ? total_birth_year / person_count : 0;
        ps.mean_height_males = ps.number_males > 0 ? total_male_height / ps.number_males : 0.0;
        ps.mean_height_females = ps.number_females > 0 ? total_female_height / ps.number_females : 0.0;
        ps.mean_height_diverse = ps.number_diverse > 0 ? total_diverse_height / ps.number_diverse : 0.0;
        ps.mean_length_of_names = person_count > 0 ? (double)(total_male_name_length + total_female_name_length + total_diverse_name_length) / person_count : 0.0;

        return ps;
    }


int main(void) {
	String table = s_read_file("people.txt");
	Statistics s = compute_statistics(table);
	print_statistics(s);
	
	/*
	Erwartete Ausgabe:
	
	mean year: 1974
	number males: 445
	number females: 455
	number diverse: 100
	mean height males: 1.79
	mean height females: 1.64
	mean height diverse: 1.61 ?
	mean length of names: 13.20 ?
	*/
	
	return 0;
}
