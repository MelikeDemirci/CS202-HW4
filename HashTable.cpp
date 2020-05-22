/**
* Author : Melike Demirci
* ID: 21702346
* Section : 2
* Assignment : 4
*/

#include "HashTable.h"
#include <cstdlib>

HashTable::HashTable(const int tableSize, const CollisionStrategy option ){
    this->tableSize = tableSize;
    hTable = new int[tableSize];
    this->option = option;

    for(int i = 0 ; i<tableSize ; i++)
	{
		hTable[i] = -1; //initialize all hash table as -1
	}

	locType = new int[tableSize];
	for(int i=0;i<tableSize ;i++)
	{
		locType[i] = 0; //set all location as empty
	}
}//end HashTable

HashTable::~HashTable(){
    if(hTable)
        delete [] hTable;

    if(locType)
        delete [] locType;
}//end ~HashTable

bool HashTable::insert( const int item ){
    int index = hPrimary(item);

    if(!isUnique(item)){
        cout << "Item already exist in table" << endl;
    }
    else{
        if(locType[index] != 1){
            hTable[index] = item; //insert item
            locType[index] = 1; //set location as occupied
            return true;
        }
        else{//look for the item
            for(int i = 1; i < tableSize; i++){
                index = h1(item, i);
                if(locType[index] != 1){ //if empty or deleted location is found
                    hTable[index] = item;
                    locType[index] = 1; //set location as occupied
                    return true;
                }
            }
        }
    }

    return false;
}//end insert

int HashTable::hPrimary( const int key){ //primary hash function
    int k = 0;
    if(key < 0)
        k = (tableSize + (key%tableSize)) % tableSize;
    else
        k = key;
    return (k%tableSize);
}//end hPrimary

int HashTable::h2( const int key){ //reverse function as secondary hash function
    int r = 0;
    int num = key;
    bool neg = false;
    //flag to check if number is negative
    if(key<0){
        neg = true;
        num = abs(num);
    }

    while(num>0)
    {
        r = r*10 + num%10;
        num = num/10;
    }

    if(neg)
        r = r *(-1);

    return r;
}//end h2


int HashTable::h1( const int key, const int i){
    if(option == LINEAR){
        return (hPrimary(key) + i) % tableSize;
    }
    else if(option == QUADRATIC){
        return (hPrimary(key) + (i*i)) % tableSize;
    }
    else if(option == DOUBLE){
        return (hPrimary(key) + (i*h2(key))) % tableSize;
    }
}//end h1

bool HashTable::remove( const int item ){

    int index = hPrimary(item);
    //Item is at the first place
    if(hTable[index] == item){
        hTable[index] = -1;
        locType[index] = -1; //set location as deleted
        return true;
    }
    else if(locType[index] == 0)
        return false;
    else{//look for the item
        for(int i = 1; index < tableSize; i++){ //loop as TableSize
			index = h1(item, i);
            if(hTable[index] == item){
                hTable[index] = -1;
                locType[index] = -1; //set location as deleted
                return true;
            }
			else if(locType[index] == 0) //if empty location is reached
			{
				return false;
			}
        }
    }
    return false;
} // end remove

bool HashTable::search (const int item, int& numProbes ){
    numProbes = 1;
    int index = 0;
    int first = hPrimary(item);
    //Item is at the first place
    if(hTable[first] == item)
        return true;
    else if(locType[first] == 0)
        return false;
    else{//look for the item
        for(int i = 1; i < tableSize; i++){ //loop
			numProbes++;
			index = h1(item, i);
			if(hTable[index] == item) //if item found
			{
                return true;
			}
			else if(locType[index] == 0)
                return false;
        }
    }
    return false;
}//end search

void HashTable::display(){
    for(int i = 0; i < tableSize; i++){
        if(locType[i] != 1){
            cout << i << ":" << endl;
        }
        else{
            cout << i << ":" << "\t" << hTable[i]<< endl;
        }
    }
}//end display

void HashTable::analyze( double& numSuccProbes, double& numUnsuccProbes ){
    int prb = 0;
    int numItem = 0;
    //successful search
    numSuccProbes = 0;
    numUnsuccProbes = 0;
    for(int i = 0; i < tableSize; i++){
        if(locType[i] == 1){ //look at occupied locations
            search(hTable[i], prb); //search for the item
            numSuccProbes += prb;
            numItem++;
        }
    }
    numSuccProbes = numSuccProbes/(double)numItem;

    //Unsuccessful search
    if(option == DOUBLE)
    numUnsuccProbes = -1;
    else{
        for(int i = 0; i < tableSize; i++){
            if(!search(i, prb)){
                numUnsuccProbes += prb;
            }
            else{
                int j = i;
                while(search(j, prb)){
                    j += tableSize;
                }
                numUnsuccProbes += prb;
            }
        }
    numUnsuccProbes = numUnsuccProbes/(double)tableSize;
    }

}

bool HashTable::isUnique(const int item){
    for(int i = 0; i < tableSize; i++){
        if((locType[i] == 1) && (item == hTable[i]))
            return false;
    }
    return true;
}
