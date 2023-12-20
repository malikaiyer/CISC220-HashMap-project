#include <iostream>
#include "makeSeuss.cpp" //need to make this .cpp because it won't run on vscode otherwise
#include "HashMap.cpp" //need to include these files because I use vscode
#include "HashNode.cpp"
#include <time.h>
#include <string>
#include <stdlib.h>

using namespace std;
int main() {
	srand(time(NULL));
	// makeSeuss voice1("DrSeuss.txt","Seussout1.txt",true,true);
	// makeSeuss voice2("DrSeuss.txt","Seussout2.txt",false,true);
	// makeSeuss voice3("DrSeuss.txt","Seussout3.txt",true,false);
	// makeSeuss voice4("DrSeuss.txt","Seussout4.txt",false,false);
//OR
	makeSeuss voice5("GEChap1a.txt","GEout1.txt",true,true);
	makeSeuss voice6("GEChap1a.txt","GEout2.txt",false,true);
	makeSeuss voice7("GEChap1a.txt","GEout3.txt",true,false);
	makeSeuss voice8("GEChap1a.txt","GEout4.txt",false,false);

	

	/*********************TESTING**************************/
	/*Order of function writing: 
		1. int calcHash1(string k)
		2. int coll1(int h, int i, string k);
		3. hashMap(book hash1, bool coll1);
		4. void addKeyValue(string k, string v);
		5. void hashNode::addValue(string v);
		6. int getIndex(string k);
		7. void getClosestPrime();
		8. void hashNode::dblArray();
		9. void reHash();
		10. int calcHash2(string k);
		11. int coll2(int h, int i, string k);
		12. string HashNode:: getRandValue();
	*/

	/*Input File:
		WOULD YOU LIKE GREEN EGGS AND HAM?
		I DO NOT LIKE THEM, SAM I AM.
		I DO NOT LIKE GREEN EGGS AND HAM.
		WOULD YOU LIKE THEM HERE OR THERE?
		I WOULD NOT LIKE THEM HERE OR THERE.
		I WOULD NOT LIKE THEM ANYWHERE.
		I DO NOT LIKE GREEN EGGS AND HAM.
		I DO NOT LIKE THEM, SAM I AM.
		WOULD YOU LIKE THEM IN A HOUSE?
		WOULD YOU LIKE THEN WITH A MOUSE?
		I DO NOT LIKE THEM IN A HOUSE.
		I DO NOT LIKE THEM WITH A MOUSE.
		I DO NOT LIKE THEM HERE OR THERE.
		I DO NOT LIKE THEM ANYWHERE.
		I DO NOT LIKE GREEN EGGS AND HAM.
		I DO NOT LIKE THEM, SAM I AM.

		string strarr[22] = {"WOULD", "YOU", "LIKE", "GREEN", 
		"EGGS", "AND", "HAM", "I", "DO", "NOT", "THEM", "SAM" (*), "AM" (*), 
		"HERE" (*), "OR", "THERE",  "ANYWHERE" (*), "IN" (*), "A", "HOUSE", "WITH", "MOUSE" (*)};
	*/

	//testing calcHash1 (Hash Array Length = 47) (Use all N characters of string as an N-digit base-b number. Choose b to be a prime number)
	// here is what the hashmap would look like:
	/*	Index             Index      
		1:  				23: 
		2					24
		3					25
		4					26: I
		5					27: HOUSE 
		6					28: 
		7: WOULD			29
		8: WITH				30: 
		9: GREEN			31
		10: YOU, SAM		32: THERE, MOUSE	
		11					33: AND
		12					34
		13					35: 
		14: 				36
		15					37
		16: 				38: LIKE, HERE, IN
		17: EGGS			39
		18: A				40: THEM
		19: NOT, AM			41: OR
		20: 				42
		21					43: 
		22					44: DO, ANYWHERE
							45: HAM
							46:
							47: 

	*/ 

	//testing coll1() (quadratic probing)
	// here is what the hashmap would look like after collision probing:
	/*	Index             Index      
		1:  				23: 
		2					24
		3					25
		4					26: I
		5					27: HOUSE 
		6: MOUSE (32+1)%27	28: 
		7: WOULD			29
		8: WITH				30: 
		9: GREEN			31
		10: YOU				32: THERE	
		11: SAM (10+1)%27	33: AND
		12: HERE (38+1)%27	34
		13					35: 
		14: 				36
		15: IN (34+4)%27	37
		16: 				38: LIKE
		17: EGGS			39
		18: A				40: THEM
		19: NOT   			41: OR
		20: AM (19+1)%27	42
		21: ANYWHERE (44+4)	43: 
		22					44: DO
							45: HAM
							46:
							47: 

	*/ 

	//testing hashmap - check to see if the hashmap was actually created

	//testing void addKeyValue(string k, string v);
	//here would be the value string arrays for each of the keys:
	/*
	WOULD: YOU, YOU, NOT, NOT, YOU, YOU, 
	YOU: LIKE, LIKE, LIKE, LIKE, 
	LIKE: GREEM, THEM, , GREEN, THEM, THEM, THEM, GREEN, THEM, , THEM, THEN, THEM, THEM, THEM, THEM, GREEN, THEM
	GREEN: EGGS, EGGS, EGGS, EGGS, 
	EGGS: AND, AND, AND, AND 
	AND: HAM?, HAM., HAM., HAM.
	HAM: I, WOULD, I, 
	I: DO, AM., DO, WOULD, WOULD, DO, DO, AM., DO, DO, DO, DO, DO, DO, AM
	DO: NOT, NOT, NOT, NOT, NOT, NOT, NOT, NOT, NOT, NOT, 
	NOT: LIKE, LIKE, LIKE, LIKE, LIKE, LIKE, LIKE, LIKE, LIKE, LIKE, LIKE, LIKE, 
	THEM: SAM, HERE, HERE, ANYWHERE., SAM, IN, IN, WITH, HERE, ANYWHERE, SAM, 
	SAM: I, I, I
	AM: I, WOULD, 
	HERE: OR, OR, OR
	OR: THERE?, THERE., THERE.
	THERE: I, I, 
	ANYWHERE: I, 
	IN: A, A, 
	A: HOUSE?, MOUSE? HOUSE., NOUSE
	HOUSE: WOULD, 
	WITH: A, A
	MOUSE: I, 
	THEN: WITH, 
	*/


	//TESTING void hashNode::addValue(string v);
	//hnode->addValue("AM"): should add value to the end of the value array in a hashnode

	//testing getIndex("WOULD")
	//returns 7

	//testing getClosestPrime()
	//since map size is 47, this should give 97

	//testing dblarray
	//should just double the size of the array. check arraysize before and after calling the function

	//testing reHash()
	//check when arraysize gets to 70%, check if arraysize is doubled, and check if everything is hashed again

	//calcHash2, coll2, will be tested after it is decided what way the values are going to be hashed and how the 
	//collisions are going to be handled. The reason these functions are written later is because i wanted to check
	// that all the other functions worked first before checking to see which way of hashing would be more efficient, so one
	//calcHash and coll function was enough
	 
	//testing getRandValue()
	//getRandValue()
	//getRandValue()
	//getRandValue()
	//these numbers should be completely random every time this is run

	// makeSeuss voice1("test.txt","testout.txt",true,true);
	// makeSeuss voice1("test2.txt","testout2.txt",true,true);
	
	return 0;

}
