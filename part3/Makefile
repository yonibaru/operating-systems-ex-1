CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm

all: main libpoisson.so
# Creating Executables
main: main.o libpoisson.so
	$(CC) $(CFLAGS) -o main main.o ./libpoisson.so $(LDFLAGS)
# Build object files
main.o: main.c 
	$(CC) $(CFLAGS) -c main.c
# Shared Library
libpoisson.so: Poisson.o
	$(CC) -shared -o $@ $^
# Build Object Files
%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Clean build files
clean:
	rm -f *.o *.a main libpoisson.so
