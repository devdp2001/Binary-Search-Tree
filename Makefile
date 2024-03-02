main: Main.o BinaryTree.o
	g++ -o main Main.o BinaryTree.o

Main.o: Main.cpp
	g++ -c -g -Wall -std=c++14 -pedantic-errors Main.cpp

BinaryTree.o: BinaryTree.h BinaryTree.cpp
	g++ -c -g -Wall -std=c++14 -pedantic-errors BinaryTree.cpp
