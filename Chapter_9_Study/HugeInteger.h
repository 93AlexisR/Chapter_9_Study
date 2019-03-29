#pragma once
//Exercice 9.12 or something
using namespace std;
class HugeInteger{
public:

//private:
	unsigned int stringSize{ 0 };
	short unsigned int yugeInt[40] = { 0 };
	const unsigned short arraySize{ sizeof(yugeInt) / sizeof(*yugeInt) };
	bool signBit{ 1 }; 
	bool isEmpty{ false }; //print function param
	unsigned int sigBits{ 0 };

	unsigned int sigBitCount(void); //returns significant bits
	unsigned int subtract_owedValue(const bool &owedFlag); //helper function for subtraction
	bool isLarger(HugeInteger &otherInt); //returns true if absolute value is bigger
	HugeInteger absVal(void); //returns absolute value
	HugeInteger flipBit(void) { return HugeInteger(yugeInt, !signBit);}

//protected:
	void copy(HugeInteger otherInt);
	HugeInteger(unsigned short int newArray[], bool newSignBit);

//public:
	HugeInteger(string& myVal);
	HugeInteger(void);
	~HugeInteger();

	void print(void);
	string printString(void);

	HugeInteger add(HugeInteger biggerInt);
	HugeInteger subtract(HugeInteger biggerInt);

	int getCppInt(void);
	friend HugeInteger flipBit(HugeInteger flipMyBit);

	bool isGreater(HugeInteger otherHugeInt);
	bool isEqual(HugeInteger &otherInt);

};
