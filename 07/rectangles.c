#include "base.h"
#include "stdlib.h"

typedef struct draw_options_s {
    bool has_border;
    String fill_pattern;
} DrawOptions;

typedef struct rectangle_s {
    // todo
    int x;
    int y;
    int w;
    int h;
} Rectangle;


/* Gibt ein DrawOptions Struct zurück, das dafür sorgt dass Rechtecke nur durch
 * Rauten und ohne Rahmen skizziert werden.
 */
DrawOptions make_draw_options_flat() {
    return (DrawOptions){
        .has_border = false,
        .fill_pattern = "#",
    };
}

/* Gibt ein DrawOptions Struct zurück, das dafür sorgt dass Rechtecke mit einem
 * Rahmen skizziert werden. Die Füllung des Rechtecks wird durch den String
 * "fill" bestimmt, der ständig wiederholend in das Rechteck geschrieben wird.
 */
DrawOptions make_draw_options_fill(String fill) {
    require("fill is a non-empty string", s_length(fill) > 0);

    return (DrawOptions){
        .has_border = true,
        .fill_pattern = fill,
    };
}

DrawOptions make_draw_options_range(char from, char to) {
    DrawOptions options;
    options.has_border = false;

options.fill_pattern = malloc(3 * sizeof(char));
options.fill_pattern[0] = from;
options.fill_pattern[1] = to;
options.fill_pattern[2] = '\0';

    return options;
}

Rectangle make_rectangle(int x, int y, int w, int h) {
    if (x < 0 || y < 0 || w <= 0 || h <= 0) {
        fprintf(stderr, "Ungültige Rectangle-Parameter!\n");
        exit(EXIT_FAILURE);  // oder return eines Fehlerwerts
    } {
    Rectangle r = {x, y, w, h};
    return r;
    }
}

bool intersects(Rectangle a, Rectangle b) {
    if (a.x + a.w <= b.x) return false;
    if (b.x + b.w <= a.x) return false;
    if (a.y + a.h <= b.y) return false;
    if (b.y + b.h <= a.y) return false;
    return true;
}

void print_rectangle(Rectangle rect, DrawOptions options) {
    String pat = options.fill_pattern;
    int plen = s_length(pat);

    // 1. vertikale Einrückung
    for (int i = 0; i < rect.y; i++) {
        putchar('\n');
    }

    // 2. obere Rahmenlinie
    if (options.has_border) {
        for (int i = 0; i < rect.x; i++) putchar(' ');        // horizontale Einrückung
        putchar('+');
        for (int i = 0; i < rect.w - 2; i++) putchar('-');
        putchar('+');
        putchar('\n');
    }

    // 3. Innenbereich
    for (int row = 0; row < rect.h; row++) {
        for (int i = 0; i < rect.x; i++) putchar(' ');        // horizontale Einrückung

        if (options.has_border) {
            putchar('|');
            for (int col = 0; col < rect.w - 2; col++) {
                putchar(pat[(row + col) % plen]);
            }
            putchar('|');
        } else {
            // Flat: nur Muster (für flat ist pattern = "#")
            for (int col = 0; col < rect.w; col++) {
                putchar(pat[(row + col) % plen]);
            }
        }

        putchar('\n');
    }

    // 4. untere Rahmenlinie
    if (options.has_border) {
        for (int i = 0; i < rect.x; i++) putchar(' ');
        putchar('+');
        for (int i = 0; i < rect.w - 2; i++) putchar('-');
        putchar('+');
        putchar('\n');
    }
}

void test_intersects(void) {
    test_equal_i(intersects(
        make_rectangle(0, 0, 10, 10),
        make_rectangle(32, 32, 10, 10)
    ), false);

    test_equal_i(intersects(
        make_rectangle(100, 100, 32, 16),
        make_rectangle(50, 32, 50, 10)
    ), false);

    test_equal_i(intersects(
        make_rectangle(50, 32, 50, 10),
        make_rectangle(100, 100, 32, 16)
    ), false);

    test_equal_i(intersects(
        make_rectangle(16, 16, 16, 16),
        make_rectangle(16, 16, 4, 4)
    ), true);

    test_equal_i(intersects(
        make_rectangle(16, 16, 16, 16),
        make_rectangle(8, 20, 32, 4)
    ), true);

    test_equal_i(intersects(
        make_rectangle(16, 16, 16, 16),
        make_rectangle(20, 8, 4, 32)
    ), true);
}

int main(void) {
    test_intersects();

    print_rectangle(make_rectangle(0, 0, 9, 5), make_draw_options_fill("0"));
    puts("===");
    print_rectangle(make_rectangle(3, 3, 10, 7), make_draw_options_fill("Hamza_und_Timo"));
    puts("===");
    print_rectangle(make_rectangle(5, 2, 4, 6), make_draw_options_fill("*_*"));
    puts("===");
    print_rectangle(make_rectangle(1, 2, 4, 4), make_draw_options_flat());
    puts("===");
    print_rectangle(make_rectangle(2, 2, 6, 4), make_draw_options_range('A', 'Z'));
    puts("===");
    print_rectangle(make_rectangle(0, 0, 12, 3), make_draw_options_range('0', '9'));

    return 0;
}

/* Beispielausgaben:

print_rectangle(make_rectangle(0, 0, 9, 5), make_draw_options_fill(" "));
+-------+
|       |
|       |
|       |
+-------+

print_rectangle(make_rectangle(3, 3, 10, 5), make_draw_options_fill("123"));



   +--------+
   |12312312|
   |31231231|
   |23123123|
   +--------+

print_rectangle(make_rectangle(5, 2, 4, 6), make_draw_options_fill(":_:"));


     +--+
     |:_|
     |::|
     |_:|
     |:_|
     +--+

print_rectangle(make_rectangle(1, 2, 4, 4), make_draw_options_flat());


 ####
 ####
 ####
 ####

*/