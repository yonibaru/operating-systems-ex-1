CC = gcc
CFLAGS = -Wall
all: stackOverflow undefMem ZeroDivisor
stackOverflow: stackOverflow.c
	$(CC) $(CFLAGS) stackOverflow.c -o stackOverflow
undefMem: undefMem.c
	$(CC) $(CFLAGS) undefMem.c -o undefMem
ZeroDivisor: ZeroDivisor.c
	$(CC) $(CFLAGS) ZeroDivisor.c -o ZeroDivisor
clean:
	rm -f stackOverflow undefMem ZeroDivisor
