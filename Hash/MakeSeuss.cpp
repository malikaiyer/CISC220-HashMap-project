
#include "makeSeuss.hpp"
#include "hashMap.hpp"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

makeSeuss::makeSeuss(string f1,string f2,bool hash1, bool coll1) {
	ht = new hashMap(hash1,coll1);
	newfile = f2;
	fn = f1;

	readFile();
	writeFile();
}
void makeSeuss::readFile() {
	ifstream infile(fn.c_str(),ios::in);     // open file
	string key = "";
	string value="";
	infile>> key;

	infile >> key;
	// cout << "key: " << key << endl; //this prints
	ht->first = key;

	while (infile >> value) {          // loop getting single characters
		// cout << key <<": " << value << endl; //this prints
		// cout << "numKeys: " << ht->numKeys << endl;
		ht->addKeyValue(key,value);
		key = value;
		value = "";
	}
	// cout << "This loop has been exited!!" << endl;
	ht->addKeyValue(key,value);
	// cout << "key value is the last key value?" << endl;
	cout << endl;
	infile.close();
	// cout <<"we have come this far?" << endl;

	ht->printMap();
	cout << "printMap is done! " << endl;
}
void makeSeuss::writeFile() {
	ofstream outfile(newfile.c_str(),ios::out);
	float hashfloat = (float)ht->hashcoll/(float)ht->numKeys;
	float collfloat =  (float)ht->collisions/(float)ht->numKeys;
	cout << "hashcoll: " << ht->hashcoll << endl;
	cout << "collisions: " << ht->collisions << endl;
	cout << "numKeys: " << ht->numKeys << endl;
	if (ht->hashfn && ht->collfn) {
		outfile << "Collisions using hash 1: "<< hashfloat << ", and collision handling 1: " << collfloat <<endl;
	}
	else if (ht->hashfn) {
		outfile << "Collisions using hash 1: "<< hashfloat << ", and collision handling 2: " << collfloat<<endl;
	}
	else if (ht->collfn) {
		outfile << "Collisions using hash 2: "<< hashfloat << ", and collision handling 1: " << collfloat<<endl;
	}
	else {
		outfile << "Collisions using hash 2: "<< hashfloat << ", and collision handling 2: " << collfloat<<endl;
	}
	outfile<<endl;
	outfile << ht->first << " ";
	// cout << "TESTING FIRST " << ht->first << endl;
	string key = "";
	string value = ht->map[ht->getIndex(ht->first)]->getRandValue();
	// cout << "INDEX OF FIRST VALUE " << ht->first << ": " << ht->getIndex(ht->first) << endl;
	// cout << "IDK WHAT THIS PRINTS PT 2: " <<  ht->map[ht->getIndex(ht->first)] << endl;
	// cout << "TESTING NEXT VAL: " << ht->map[ht->getIndex(ht->first)]->getRandValue() << endl;
	int ct = 0;
	int len = 0;
	while (ct < 500 &&  value != "") {
		key = value;
		outfile << key << " ";
		if (len == 11) {
			outfile << "\n";
			len = 0;
		}
		else len++;
		// cout <<  "ht->getIndex(key): " <<ht->getIndex(key) << endl;
		// cout << "address map: "<<ht->map[ht->getIndex(key)] << endl;
		// cout << "key = " << key << endl;
		value = ht->map[ht->getIndex(key)]->getRandValue();
		
		// cout << ct << ", " << endl;
		ct ++;
	}
	outfile.close();
}


