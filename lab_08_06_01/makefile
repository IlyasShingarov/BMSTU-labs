INCPATH := ./inc/
OUTPATH := ./out/
SRCPATH := ./src/
FUNCTESTSPATH := ./func_tests/
UNITTESTSPATH := ./unit_tests/
CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -Werror -Wpedantic -I$(INCPATH) -g3 -o0
LFLAGS := --coverage -lcheck -lpthread -lrt
.PHONY: clean unit func

app.exe : $(OUTPATH)io.o $(OUTPATH)main.o $(OUTPATH)matrix_normalization.o $(OUTPATH)matrix_arithmetic.o
	$(CC) $^ -lm -o $@
	
unit_tests.exe: $(OUTPATH)check_filter.o $(OUTPATH)filter.o $(OUTPATH)check_sort.o $(OUTPATH)sort.o $(OUTPATH)check_main.o
	$(CC) -o $@ $^ $(LFLAGS)

func: CFLAGS += --coverage
func: $(OUTPATH)io.o $(OUTPATH)main.o
	$(CC) $^ --coverage -o ./app.exe
	bash ./test.sh

$(OUTPATH)main.o: $(SRCPATH)main.c
	$(CC) $(CFLAGS) -c $(SRCPATH)main.c -o $(OUTPATH)main.o

$(OUTPATH)io.o: $(SRCPATH)io.c
	$(CC) $(CFLAGS) -c $(SRCPATH)io.c -o $(OUTPATH)io.o

$(OUTPATH)matrix_normalization.o: $(SRCPATH)matrix_normalization.c
	$(CC) $(CFLAGS) -c $(SRCPATH)matrix_normalization.c -o $(OUTPATH)matrix_normalization.o

$(OUTPATH)matrix_arithmetic.o: $(SRCPATH)matrix_arithmetic.c
	$(CC) $(CFLAGS) -c $(SRCPATH)matrix_arithmetic.c -o $(OUTPATH)matrix_arithmetic.o
#
#$(OUTPATH)sort.o : $(SRCPATH)sort.c
#	$(CC) $(CFLAGS) -c $(SRCPATH)sort.c -o $(OUTPATH)sort.o
#
#$(OUTPATH)filter.o : $(SRCPATH)filter.c
#	$(CC) $(CFLAGS) -c $(SRCPATH)filter.c -o $(OUTPATH)filter.o
#
#$(OUTPATH)check_main.o: $(UNITTESTSPATH)check_main.c
#	$(CC) $(CFLAGS) -c $(UNITTESTSPATH)check_main.c -o $(OUTPATH)check_main.o
#
#$(OUTPATH)check_filter.o: $(UNITTESTSPATH)check_filter.c
#	$(CC) $(CFLAGS) -c $(UNITTESTSPATH)check_filter.c -o $(OUTPATH)check_filter.o
#
#$(OUTPATH)check_sort.o: $(UNITTESTSPATH)check_sort.c
#	$(CC) $(CFLAGS) -c $(UNITTESTSPATH)check_sort.c -o $(OUTPATH)check_sort.o


clean:
	rm -rf *.exe *.gcov ./out/*.o ./out/*.gcno ./out/*.gcda
