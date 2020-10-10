INCPATH := ./inc/
OUTPATH := ./out/
SRCPATH := ./src/
FUNCTESTSPATH := ./func_tests/
UNITTESTSPATH := ./unit_tests/
CC := gcc
CFLAGS := -std=c99 -Wall -Wextra -Werror -Wpedantic --coverage -g3 -I$(INCPATH)
OBJS := io.o sort.c
.PHONY: clean unit func

app.exe : $(OUTPATH)io.o $(OUTPATH)sort.o $(OUTPATH)filter.o $(OUTPATH)main.o
	$(CC) --coverage $^ -o $@

$(OUTPATH)main.o: $(SRCPATH)main.c
	$(CC) $(CFLAGS) -c $(SRCPATH)main.c -o $(OUTPATH)main.o

$(OUTPATH)io.o: $(SRCPATH)io.c
	$(CC) $(CFLAGS) -c $(SRCPATH)io.c -o $(OUTPATH)io.o

$(OUTPATH)sort.o : $(SRCPATH)sort.c
	$(CC) $(CFLAGS) -c $(SRCPATH)sort.c -o $(OUTPATH)sort.o

$(OUTPATH)filter.o : $(SRCPATH)filter.c
	$(CC) $(CFLAGS) -c $(SRCPATH)filter.c -o $(OUTPATH)filter.o

clean:
	rm -rf *.exe ./out/*.o ./out/*.gcno ./out/*.gcda
