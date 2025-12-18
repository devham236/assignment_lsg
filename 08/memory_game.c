/*
Compile: make memory_game
Run: ./memory_game 2 3
Compile & run: make memory_game && ./memory_game 2 3
*/

#include "base.h"
#include "clrscr.h"

#ifdef _WIN32
	#define WIN_TESTS true
	#define LINUX_TESTS false
#elif __linux__
	#define LINUX_TESTS true
	#define WIN_TESTS false
#else
	#define WIN_TESTS false
	#define LINUX_TESTS false
#endif

// Represents the state of the memory game.
typedef struct {
    char *cards; // array of cards, each card is one character, row-wise
    int ncards; // number of cards in array
    int rows; // number of rows of the board
    int cols; // number of columns of the board
    int points; // number of points the player has earned
    int turns; // number of card turns the player has made
} Board;

// Shuffles the array.
void shuffle(char *a, int n) {
    // a) todo: explain
    for (int i = n - 1; i > 0; i--) {
        int r = rand() % (i + 1); // zufälliger Index zwischen 0 und i
        char c = a[r];            // a[r] merken
        a[r] = a[i];              // a[i] an Position r
        a[i] = c;                 // gemerkten Wert an Position i
    }
}

// Initializes the board with shuffled cards. Empty places are represented as ' '.
// Open places are represented as the respective character, e.g., 'A'.
// Hidden places are represented as negative characters, e.g., -'A'. 
// The cards are initially hidden (negative). 
// Only initializes the elements of the cards array. Assumes that cards points to 
// an existing array and that ncards, rows, cols, points, and turns are already set.

    // b) todo: implement
    // access to board elements: b->ncards, b->cards[i], b->rows, b->cols
void init_cards(Board *b) {
    int pairs = b->ncards / 2;
    for (int i = 0; i < pairs; i++) {
        char card = 'A' + i; // Karten: A, B, C, ...
        b->cards[2*i] = -card;
        b->cards[2*i + 1] = -card;
    }
    if (b->ncards % 2 != 0) { // ungerade Zahl von Feldern
        b->cards[b->ncards - 1] = ' ';
    }
    shuffle(b->cards, b->ncards);
}
// Prints the board. Hidden cards are shown as '#'. The following shows an output example:
/*
  1 2 3 4           <-- four columns
1   # #             <-- row 1: 1st and 4th card taken, 2nd and 3rd card hidden
2 # D # #           <-- row 2: 2nd card open
3 # # A #           <-- row 3: 3rd card open
1 points, 2 turns   <-- the player got 1 point in 2 turns
*/
// The row and column numbers are printed to facilitate input.
    // c) todo: implement
    // access to board elements: b->ncards, b->cards[i], b->rows, b->cols
// Funktionsprototypen
char get_card(Board *b, int r, int c);
void set_card(Board *b, int r, int c, char x);
void turn_card(Board *b, int r, int c);

void print_board(Board *b) {
  printf("  ");
  for (int c = 0; c < b->cols; c++) printf("%d ", c+1);
  printf("\n");

  for (int r = 0; r < b->rows; r++) {
       printf("%d ", r+1);
        for (int c = 0; c < b->cols; c++) {
            char val = get_card(b, r, c);
            if (val == ' ')
                printf("  ");
            else if (val < 0)
                printf("# ");
            else
                printf("%c ", val);
        }
        printf("\n");
    }

    printf("%d points, %d turns\n", b->points, b->turns);
}


// Returns the array index of row r, column c. Stops the program if r or c are not valid.
    // d) todo: implement
    // access to board elements: b->rows, b->cols
int array_index(Board *b, int r, int c) {
    if (r < 0 || r >= b->rows || c < 0 || c >= b->cols) {
        printf("Invalid index!\n");
        exit(1);
    }
    return r * b->cols + c;
}

// Gets value at row r, column c. Stops the program if r or c are not valid.
// e) todo: implement
char get_card(Board *b, int r, int c) {
    return b->cards[array_index(b, r, c)];
}

// Sets value at row r, column c to x. Stops the program if r or c are not valid.
// e) todo: implement
void set_card(Board *b, int r, int c, char x) {
    b->cards[array_index(b, r, c)] = x;
}

// Turns over card in row r, column c. Stops the program if r or c are not valid.
// e) todo: implement
void turn_card(Board *b, int r, int c) {
    int idx = array_index(b, r, c);
    char val = b->cards[idx];
    if (val != ' ') b->cards[idx] = -val; // umdrehen
}

// Prints a prompt to wait and wait for return key.
void prompt(void) {
    printf("press <return> to continue\n");
    char line[8];
    get_line(line, 8);
}

// Gets user input of the form <row-digit><column-digit> to let the user specify
// the row and column of a card. Example: Input 13 specifies row 0, column 2.
// Because the function returns three values, row and col are pointers to int
// variables to be set by the function. The return value indicates whether the
// position is valid (true) or not (false), given the current board state.
bool read_coords(/*IN*/Board *b, /*OUT*/int *row, /*OUT*/int *col) {
    char line[8];
    get_line(line, 8); // read input from terminal into line array
    int r = line[0] - '1'; // input '1' corresponds to row 0, '2' --> 1, etc.
    int c = line[1] - '1';
    if (r < 0 || r >= b->rows || c < 0 || c >= b->cols || get_card(b, r, c) == ' ') {
        return false; // position not valid
    }
    *row = r;
    *col = c;
    return true; // position valid
}

// Restricts x to the interval [low, high].
// f) todo: implement
int clamp(int x, int low, int high) {
    if (x < low) return low;
    if (x > high) return high;
    return x;
}

// Does a single move. It consists of turning over two cards. If they are equal, 
// they get removed from the board and a point for the collected pair is given 
// to the player. Otherwise, they are turned over again (backside up).
// The input format is: 12<return> to open a card in row 0, column 1.
void do_move(Board *b) { // g) todo: explain
    int r1, c1;
    while (!read_coords(b, &r1, &c1)) {
        printf("Illegal move.\n");
    }
    turn_card(b, r1, c1);
    b->turns++;
    clear_screen();
    print_board(b);

    int r2, c2;
    while (!read_coords(b, &r2, &c2) || (r1 == r2 && c1 == c2)) {
        printf("Illegal move.\n");
    }
    turn_card(b, r2, c2);
    b->turns++;
    clear_screen();
    print_board(b);

    prompt();
    char card1 = get_card(b, r1, c1);
    char card2 = get_card(b, r2, c2);
    assert("Illegal action.\n", card1 > 0 && card2 > 0 && card1 != ' ');
    if (card1 == card2) {
        b->points++;
        set_card(b, r1, c1, ' ');
        set_card(b, r2, c2, ' ');
    } else {
        turn_card(b, r1, c1);
        turn_card(b, r2, c2);
    }
    clear_screen();
    print_board(b);
}

// Tests.
void tests(void) {
    test_equal_i(clamp(1, 2, 4), 2);
    test_equal_i(clamp(2, 2, 4), 2);
    test_equal_i(clamp(3, 2, 4), 3);
    test_equal_i(clamp(4, 2, 4), 4);
    test_equal_i(clamp(5, 2, 4), 4);
    
    // test with a 3x4 board (3 rows, 4 columns)
    char a[3*4];
    Board b = { a, 12, 3, 4, 10, 20 };
    srand(123); // initialize random number generator to fixed seed to always get the same test numbers
    init_cards(&b);
    
    print_board(&b); // ensure that output is equal to testsout1_want.txt

    test_equal_i(array_index(&b, 0, 0), 0);
    test_equal_i(array_index(&b, 0, 1), 1);
    test_equal_i(array_index(&b, 0, 2), 2);
    test_equal_i(array_index(&b, 1, 0), 4);
    test_equal_i(array_index(&b, 1, 1), 5);
    test_equal_i(array_index(&b, 2, 0), 8);
    test_equal_i(array_index(&b, 2, 1), 9);

	if(WIN_TESTS){
		test_equal_i(get_card(&b, 0, 0), -67);
		test_equal_i(get_card(&b, 0, 1), -70);
		test_equal_i(get_card(&b, 0, 2), -66);
		test_equal_i(get_card(&b, 1, 0), -68);
		test_equal_i(get_card(&b, 1, 1), -69);
		test_equal_i(get_card(&b, 2, 0), -65);
		test_equal_i(get_card(&b, 2, 1), -67);
	}else if(LINUX_TESTS){
		test_equal_i(get_card(&b, 0, 0), -67);
		test_equal_i(get_card(&b, 0, 1), -68);
		test_equal_i(get_card(&b, 0, 2), -65);
		test_equal_i(get_card(&b, 1, 0), -66);
		test_equal_i(get_card(&b, 1, 1), -70);
		test_equal_i(get_card(&b, 2, 0), -69);
		test_equal_i(get_card(&b, 2, 1), -66);
	}else{
	    test_equal_i(get_card(&b, 0, 0), -66);
		test_equal_i(get_card(&b, 0, 1), -68);
		test_equal_i(get_card(&b, 0, 2), -67);
		test_equal_i(get_card(&b, 1, 0), -66);
		test_equal_i(get_card(&b, 1, 1), -70);
		test_equal_i(get_card(&b, 2, 0), -65);
		test_equal_i(get_card(&b, 2, 1), -67);
	}

    turn_card(&b, 0, 0);
    turn_card(&b, 0, 2);
    turn_card(&b, 1, 0);
    turn_card(&b, 2, 1);
    
    if(WIN_TESTS){
		test_equal_i(get_card(&b, 0, 0), 67);
		test_equal_i(get_card(&b, 0, 2), 66);
		test_equal_i(get_card(&b, 1, 0), 68);
		test_equal_i(get_card(&b, 2, 1), 67);
	}else if(LINUX_TESTS){
		test_equal_i(get_card(&b, 0, 0), 67);
		test_equal_i(get_card(&b, 0, 2), 65);
		test_equal_i(get_card(&b, 1, 0), 66);
		test_equal_i(get_card(&b, 2, 1), 66);
	}else{
		test_equal_i(get_card(&b, 0, 0), 66);
		test_equal_i(get_card(&b, 0, 2), 67);
		test_equal_i(get_card(&b, 1, 0), 66);
		test_equal_i(get_card(&b, 2, 1), 67);
	}

    print_board(&b); // ensure that output is equal to testsout2_want.txt or if you use Windows that output is equal to testsout2_want_WIN.txt or if you use Linux that output is equal to testsout2_want_LINUX.txt

    set_card(&b, 0, 0, '1');
    set_card(&b, 0, 2, '2');
    set_card(&b, 1, 0, '3');
    set_card(&b, 2, 1, '4');

    test_equal_i(get_card(&b, 0, 0), '1');
    test_equal_i(get_card(&b, 0, 2), '2');
    test_equal_i(get_card(&b, 1, 0), '3');
    test_equal_i(get_card(&b, 2, 1), '4');

    print_board(&b); // ensure that output is equal to testsout3_want.txt

    srand(time(NULL) << 10);
}

// Entry point with command line arguments.
int main(int argc, String argv[]) {
    if (argc != 3) {
        printf("Usage: memory_game <rows> <cols>\n");
        printf("Example: memory_game 2 3\n");
        exit(1);
    }
    
    tests(); 
    prompt();
    
    Board b;
    b.rows = clamp(atoi(argv[1]), 2, 9); // atoi converts strings to integers (if possible)
    b.cols = clamp(atoi(argv[2]), 2, 9);
    printf("creating a memory board with %d rows and %d cols\n", b.rows, b.cols); 
    int pairs = b.rows * b.cols / 2;
    printf("%d pairs\n", pairs);
    b.ncards = 2 * pairs;
    printf("%d cards\n", b.ncards);
    char cards[b.ncards];
    b.cards = cards;
    b.points = 0;
    b.turns = 0;
    init_cards(&b);

    clear_screen();
    print_board(&b);
    while (2 * b.points < b.ncards) {
        do_move(&b);
    }
    
    return 0;
}

/*
Example sequence:
-----------------

  1 2 3
1 # # #
2 # # #
0 points, 0 turns
11

  1 2 3
1 B # #
2 # # #
0 points, 1 turns
12

  1 2 3
1 B C #
2 # # #
0 points, 2 turns
press <return> to continue

  1 2 3
1 # # #
2 # # #
0 points, 2 turns
21

  1 2 3
1 # # #
2 A # #
0 points, 3 turns
22

  1 2 3
1 # # #
2 A C #
0 points, 4 turns
press <return> to continue

  1 2 3
1 # # #
2 # # #
0 points, 4 turns
12

  1 2 3
1 # C #
2 # # #
0 points, 5 turns
22

  1 2 3
1 # C #
2 # C #
0 points, 6 turns
press <return> to continue

  1 2 3
1 #   #
2 #   #
1 points, 6 turns
23

  1 2 3
1 #   #
2 #   A
1 points, 7 turns
21

  1 2 3
1 #   #
2 A   A
1 points, 8 turns
press <return> to continue

  1 2 3
1 #   #
2      
2 points, 8 turns
11

  1 2 3
1 B   #
2      
2 points, 9 turns
13

  1 2 3
1 B   B
2      
2 points, 10 turns
press <return> to continue

  1 2 3
1      
2      
3 points, 10 turns
*/
