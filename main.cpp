/**
* Author : Melike Demirci
* ID: 21702346
* Section : 2
* Assignment : 4
*/
#include "HashTable.h"


#include<stdio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char* argv[]){
    int tableSize = atoi(argv[2]);
	int lineC = 0;
	string fileName = (string)argv[1];
    string line;

    ifstream inFile;
    inFile.open((fileName).c_str());
    if (inFile.is_open())
    {
        while ( getline (inFile,line) )
        {
          ++lineC;
        }
    inFile.close();
    }

    int* item = new int[lineC];
    string* op = new string[lineC];

    HashTable hL(tableSize, LINEAR);
    HashTable hQ(tableSize, QUADRATIC);
    HashTable hD(tableSize, DOUBLE);
    int i, p, val;
    double suc, unsuc;


    inFile.open((fileName).c_str());
    if (!inFile) {
        cout << "Unable to open file";
    }
    else{
        for (int i=0; i < lineC; i ++){
            inFile >> op[i];
            inFile >> item[i];

        }
    }

    //Linear
    cout << "***************************************LINEAR****************************************" <<endl;
    for(i = 0; i <lineC; i++){
        val = item[i];
        if(op[i].compare("I") == 0){
            if(hL.insert(val))
                cout << val <<" inserted" << endl;
            else
                cout << val <<" not inserted" << endl;
        }
        else if(op[i].compare("R") == 0){
            if(hL.remove(val))
                cout << val <<" deleted" << endl;
            else
                cout << val <<" not deleted" << endl;
        }
        else{
            if(hL.search(val, p))
                cout << val <<" found after " << p << " probes" << endl;
            else
                cout << val <<" not found after " << p << " probes" << endl;
        }
    }

    cout << endl;
    hL.display();
    hL.analyze(suc, unsuc);
    cout<< "Succ: " << suc << endl;
    cout<< "Unsucc: " << unsuc << endl;
    cout<< "Table Size: " << tableSize << endl;
    cout << endl;

    //Quad
    cout << "***************************************QUAD****************************************" <<endl;
    for(i = 0; i <lineC; i++){
        val = item[i];
        if(op[i].compare("I") == 0){
            if(hQ.insert(val))
                cout << val <<" inserted" << endl;
            else
                cout << val <<" not inserted" << endl;
        }
        else if(op[i].compare("R") == 0){
            if(hQ.remove(val))
                cout << val <<" deleted" << endl;
            else
                cout << val <<" not deleted" << endl;
        }
        else{
            if(hQ.search(val, p))
                cout << val <<" found after " << p << " probes" << endl;
            else
                cout << val <<" not found after " << p << " probes" << endl;
        }
    }

    cout << endl;
    hQ.display();
    hQ.analyze(suc, unsuc);
    cout<< "Succ: " << suc << endl;
    cout<< "Unsucc: " << unsuc << endl;
    cout<< "Table Size: " << tableSize << endl;
    cout << endl;

    //Double
    cout << "***************************************DOUBLE****************************************" <<endl;
    for(i = 0; i <lineC; i++){
        val = item[i];
        if(op[i].compare("I") == 0){
            if(hD.insert(val))
                cout << val <<" inserted" << endl;
            else
                cout << val <<" not inserted" << endl;
        }
        else if(op[i].compare("R") == 0){
            if(hD.remove(val))
                cout << val <<" deleted" << endl;
            else
                cout << val <<" not deleted" << endl;
        }
        else{
            if(hD.search(val, p))
                cout << val <<" found after " << p << " probes" << endl;
            else
                cout << val <<" not found after " << p << " probes" << endl;
        }
    }

    cout << endl;
    hD.display();
    hD.analyze(suc, unsuc);
    cout<< "Succ: " << suc << endl;
    cout<< "Unsucc: " << unsuc << endl;
    cout<< "Table Size: " << tableSize << endl;
    cout << endl;

    delete [] op;//deallocation
    delete [] item;//deallocation

    return 0;
}

