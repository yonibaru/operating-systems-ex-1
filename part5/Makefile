CC = gcc
CFLAGS = -Wall -g
all: main
# Creating Executables
main: main.o 
	$(CC) $(CFLAGS) -pg -o main main.o
# Build object files
main.o: main.c
	$(CC) $(CFLAGS) -pg -c main.c
# Clean build files
clean:
	rm -f *.o *.a main