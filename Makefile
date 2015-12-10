add: main.o stack.o fraction.o
	c++ -g -o calc main.o stack.o fraction.o

stack.o: stack.cpp stack.h
	c++ -g -c stack.cpp

fraction.o: fraction.cpp fraction.h
	c++ -g -c fraction.cpp

main.o: main.cpp fraction.h stack.h
	c++ -g -c main.cpp

clean:
	rm *.o
	rm calc