CC = gcc
LINKER = gcc
CFLAGS = -std=gnu11 -Wall -Wpointer-arith # -Werror -Wfatal-errors
DEBUG = -g

# disable default suffixes
.SUFFIXES:

# pattern rule for compiling .c-file to executable
%: %.c
	cd prog1lib/lib && make
	$(CC) $(CFLAGS) $(DEBUG) $< -L./prog1lib/lib -lprog1 -lm -iquote./prog1lib/lib -o $@

# do not treat "clean" as a file name
.PHONY: clean verify

# remove produced files, invoke as "make clean"
clean: 
	rm -f *.o
	rm -rf *.dSYM
	rm -f *.exe
	rm -f .DS_Store
	cd prog1lib/lib && make clean

verify:
	prog1lib/verify.sh
