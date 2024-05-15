CC = gcc
CFLAGS = -Wall -g
all: add2PB findPhone
# Creating Executables
add2PB: add2PB.o
	$(CC) $(CFLAGS) -o add2PB add2PB.o
findPhone: findPhone.o
	$(CC) $(CFLAGS) -o findPhone findPhone.o
# Build object files
add2PB.o: add2PB.c
	$(CC) $(CFLAGS) -c add2PB.c
findPhone.o: findPhone.c
	$(CC) $(CFLAGS) -c findPhone.c
# Clean build files
clean:
	rm -f *.o *.a add2PB findPhone