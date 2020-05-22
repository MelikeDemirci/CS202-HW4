# Title : Hash Tables
# Author : Melike Demirci
# ID: 21702346
# Section : 2
# Assignment : 4
# Description : makefile



hw4: main.o HashTable.o 
	g++ main.o HashTable.o -o hw4
	rm *.o

main.o: main.cpp
	g++ -c main.cpp

HashTable.o: HashTable.cpp HashTable.h
	g++ -c HashTable.cpp



clean:
	rm hw4