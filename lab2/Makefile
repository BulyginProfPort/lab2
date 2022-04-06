all: lab2

list.o: LinkedList/LinkedList.cpp
	g++ -c LinkedList/LinkedList.cpp -o list.o

DynamicArr.o: DynamicArray/DynamicArray.cpp
	g++ -c DynamicArray/DynamicArray.cpp -o DynamicArr.o

matrix.o: Matrix/matrix.cpp
	g++ -c Matrix/matrix.cpp -o matrix.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

lab2: list.o DynamicArr.o matrix.o main.o
	g++ list.o DynamicArr.o matrix.o main.o -o lab2
clean:
	rm -f *.o