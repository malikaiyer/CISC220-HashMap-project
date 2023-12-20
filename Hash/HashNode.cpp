#include "hashMap.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

/*******************************************************************************/
/* In the hashNodes, the data includes a key string and a pointer to an array of strings, which is the
values. It also includes the current size of that array of strings, and the number of strings currently in
that array. This is done so that we know when the array gets full, and when that happens we’ll allocate
a longer array on the heap and copy over the values. For me this didn’t happen very often. THIS PART IS
NOT THE HASH MAP. I literally just started at index 0 and copied the string values over.
Also these hashNodes DO NOT have a prev or next (or parent, or left, or right) pointer. These are just
nodes that the hashMap points to.*/
/*******************************************************************************/

hashNode::hashNode(string s){
	keyword = s;
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
	srand(time(NULL));
}
hashNode::hashNode(){
	keyword = "";
	values = new string[100];
	valuesSize = 100;
	currSize = 0;
	srand(time(NULL));
}
hashNode::hashNode(string s, string v){
	keyword = s;
	values = new string[100];
	values[0] = v;
	valuesSize = 100;
	currSize = 1;
}
void hashNode::addValue(string v) {
	// adding a valu to the end of the value array associated 
	// with a key
	
	// cout << "curr value size: " << currSize << ", " << "vals: " << valuesSize << endl;
	values[currSize] = v;
	currSize++;
}
void hashNode::dblArray() {
	// when the value array gets full, you need to make a new 
	// array twice the size of the old one (just double, no 
	//going to next prime) and then copy over the old values 
	//to the new values, then de-allocate the old array.  
	//Again, just copying over, no hash functiosn involved 
	//here.
	string *valuesNew = new string[2*valuesSize];

	for(int i=0; i<valuesSize; i++){
		valuesNew[i] = values[i];
	}

	delete[] values;

	valuesSize = 2*valuesSize;
	values = valuesNew;
}

string hashNode::getRandValue() {
	//Every key has a values array - an array of words that 
	// follow that key in the text document.  You're going to 
	//randomly select one of those words and return it.  That 
	//will be the word that follows your key in your output 
	//function, and it will also be the next key.
	int num = rand()%currSize;
	return values[num];
	
}
