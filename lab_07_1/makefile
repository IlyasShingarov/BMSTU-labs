INCPATH := ./inc/
OUTPATH := ./out/
SRCPATH := ./src/
FUNCTESTSPATH := ./func_tests/
UNITTESTSPATH := ./unit_tests/
CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -Werror -Wpedantic -I$(INCPATH) --coverage
.PHONY: clean unit func

app.exe : $(OUTPATH)io.o $(OUTPATH)sort.o $(OUTPATH)filter.o $(OUTPATH)main.o
	$(CC) $^ --coverage -o $@

unit: $(OUTPATH)check_filter.o $(OUTPATH)filter.o #$(OUTPATH)check_sort.o $(OUTPATH)check_main.o
	$(CC) -o unit.exe $(OUTPATH)filter.o $(OUTPATH)check_filter.o -lcheck --coverage
	#./unit.exe

func: app.exe
	./test.sh

$(OUTPATH)main.o: $(SRCPATH)main.c
	mkdir -p $(OUTPATH)
	$(CC) $(CFLAGS) -c $(SRCPATH)main.c -o $(OUTPATH)main.o

$(OUTPATH)io.o: $(SRCPATH)io.c
	mkdir -p $(OUTPATH)
	$(CC) $(CFLAGS) -c $(SRCPATH)io.c -o $(OUTPATH)io.o

$(OUTPATH)sort.o : $(SRCPATH)sort.c
	mkdir -p $(OUTPATH)
	$(CC) $(CFLAGS) -c $(SRCPATH)sort.c -o $(OUTPATH)sort.o

$(OUTPATH)filter.o : $(SRCPATH)filter.c
	mkdir -p $(OUTPATH)
	$(CC) $(CFLAGS) -c $(SRCPATH)filter.c -o $(OUTPATH)filter.o

$(OUTPATH)check_filter.o: $(UNITTESTSPATH)check_filter.c
	mkdir -p $(OUTPATH)
	$(CC) $(CFLAGS) -c $(UNITTESTSPATH)check_filter.c -o $(OUTPATH)check_filter.o


clean:
	rm -rf *.exe *.gcov ./out/*.o ./out/*.gcno ./out/*.gcda
