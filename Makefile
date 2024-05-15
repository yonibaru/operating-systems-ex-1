CC = gcc
CFLAGS = -Wall
all: stackOverflow undefMem ZeroDivisor poisson part3 libpoisson.so part4 part5 findPhone add2PB

#Part1
stackOverflow: stackOverflow.c
	$(CC) $(CFLAGS) stackOverflow.c -o stackOverflow
undefMem: undefMem.c
	$(CC) $(CFLAGS) undefMem.c -o undefMem
ZeroDivisor: ZeroDivisor.c
	$(CC) $(CFLAGS) ZeroDivisor.c -o ZeroDivisor
#Part2
poisson: Poisson.c
	$(CC) $(CFLAGS) -o poisson Poisson.c -lm
#Part3
libpoisson.so: Poisson.o
	$(CC) -shared -o $@ $^
part3: part3.o libpoisson.so
	$(CC) $(CFLAGS) -o part3 part3.o ./libpoisson.so -lm
part3.o: part3.c 
	$(CC) $(CFLAGS) -fPIC -c part3.c
#Part4
part4: part4.o 
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage -o part4 part4.o
part4.o: part4.c
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage -c part4.c
#Part5
part5: part5.o 
	$(CC) $(CFLAGS) -pg -o part5 part5.o
part5.o: part5.c
	$(CC) $(CFLAGS) -pg -c part5.c
#Part6
add2PB: add2PB.o
	$(CC) $(CFLAGS) -o add2PB add2PB.o
findPhone: findPhone.o
	$(CC) $(CFLAGS) -o findPhone findPhone.o
add2PB.o: add2PB.c
	$(CC) $(CFLAGS) -c add2PB.c
findPhone.o: findPhone.c
	$(CC) $(CFLAGS) -c findPhone.c
#Clean
clean:
	rm -f *.o *.a stackOverflow undefMem ZeroDivisor poisson part3 libpoisson.so part4 part5 add2PB findPhone
