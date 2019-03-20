#pragma once
//Exercice 9.12 or something
using namespace std;
class HugeInteger
{
private:
	
	unsigned int arraySize{ sizeof(yugeInt) / sizeof(*yugeInt) };
	unsigned int stringSize{ 0 };
protected:
	short unsigned int yugeInt[40] = { 0 };
	bool signBit{ 1 };
	HugeInteger(unsigned short int myVal[]);
	HugeInteger(string& charVal, bool newSignBit);
	HugeInteger(unsigned short int newArray[], bool newSignBit);



public:

	HugeInteger(void);
	HugeInteger(string myVal);
	void print(void);
	~HugeInteger();
	HugeInteger flipBit(HugeInteger flipMyBit);
	HugeInteger flipBit(void) { return flipBit(*this); }

	string printString(void);
	HugeInteger add(HugeInteger otherHugeInt);
	HugeInteger subtract(HugeInteger otherHugeInt);


	bool isLarger(HugeInteger otherHugeInt);
	bool isPos(void);
};

