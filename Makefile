CC = gcc
CFLAGS = -Wall -Wextra

all: math_matrix

math_matrix: math_matrix.o functions.o
	$(CC) $(CFLAGS) -o math_matrix math_matrix.o functions.o

math_matrix.o: math_matrix.c functions.h
	$(CC) $(CFLAGS) -c math_matrix.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm -f math_matrix *.o