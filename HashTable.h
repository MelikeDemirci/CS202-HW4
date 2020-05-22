/**
* Author : Melike Demirci
* ID: 21702346
* Section : 2
* Assignment : 4
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
using namespace std;

enum CollisionStrategy { LINEAR, QUADRATIC, DOUBLE };

class HashTable {

public:
	HashTable(const int tableSize, const CollisionStrategy option );
    ~HashTable();
    bool insert( const int item );
    bool remove( const int item );
    bool search( const int item, int& numProbes );
    void display();
    void analyze( double& numSuccProbes, double& numUnsuccProbes );
    bool isUnique(const int item);

protected:
    int hPrimary( const int key);
    int h1( const int key, const int i);
    int h2( const int key);

private:
    int tableSize;
    int* hTable;
    int *locType; //Occupied = 1, Empty = 0, Deleted = -1
    CollisionStrategy option;
};

#endif
