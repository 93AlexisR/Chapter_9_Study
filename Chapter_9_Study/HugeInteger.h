#pragma once
//Exercice 9.12 or something
using namespace std;
class HugeInteger
{
private:
	
	bool signBit{ 1 };
	unsigned int arraySize{ sizeof(yugeInt) / sizeof(*yugeInt) };
	unsigned int stringSize{ 0 };
	

protected:
	short unsigned int yugeInt[40] = { 0 };
	short unsigned int getPosVal(unsigned int position);

public:

	HugeInteger(void);
	HugeInteger(string& myVal);
	HugeInteger(int myVal[]);

	~HugeInteger();

	HugeInteger& printVal(void);
	HugeInteger add(HugeInteger otherHugeInt);
	HugeInteger subtract(HugeInteger otherHugeInt);

	bool isLarger(HugeInteger otherVal);
	bool isPos(void);
	bool isNeg(void) { return !isPos(); }

};

