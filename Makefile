CFLAGS = -O
CC = g++

pair_cons: pair_cons.o stack.o
	$(CC) $(CFLAGS) pair_cons.o stack.o

stack: basic_stack.o Stack.o
	$(CC) $(CFLAGS) -o basic_stack basic_stack.o stack.o

basic_stack.o: basic_stack.cpp
	$(CC) $(CFLAGS) -c basic_stack.cpp

stack.o: Stack/Stack.cpp
	$(CC) $(CFLAGS) -c Stack/Stack.cpp

pair_cons.o: pair_consecutive.cpp
	$(CC) $(CFLAGS) -o pair_cons.o -c pair_consecutive.cpp

clean:
	rm *.o
	rm a.out

