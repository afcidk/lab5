main: hugeint.o main.o
	g++ -o main hugeint.o main.o
hugeint.o: hugeint.cpp hugeint.h
	g++ -c hugeint.cpp hugeint.h
main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o
