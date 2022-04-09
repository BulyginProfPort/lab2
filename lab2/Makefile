all: lab2

list.o: LinkedList/LinkedList.cpp
	g++ -c LinkedList/LinkedList.cpp -std=c++11 -g -o list.o

DynamicArr.o: DynamicArray/DynamicArray.cpp
	g++ -c DynamicArray/DynamicArray.cpp -std=c++11 -g -o DynamicArr.o

matrix.o: Matrix/matrix.cpp
	g++ -c Matrix/matrix.cpp -std=c++11 -g -o matrix.o

main.o: main.cpp
	g++ -c main.cpp -std=c++11 -g -o main.o

lab2: list.o DynamicArr.o matrix.o main.o
	g++ list.o DynamicArr.o matrix.o main.o -g -o lab2
clean:
	    rm -f *.o