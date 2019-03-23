#pragma once
//Exercice 9.12 or something
using namespace std;
class HugeInteger{
public:
//private:
	unsigned int stringSize{ 0 };
	const unsigned short arraySize{ sizeof(yugeInt) / sizeof(*yugeInt) };

//protected:


	HugeInteger& setValues(string& charVal, bool newSignBit);
	HugeInteger& setValues(unsigned short int newArray[], bool newSignBit);
	HugeInteger& setValues(const HugeInteger &otherInt);
	HugeInteger& setValues(string& charVal);
	HugeInteger& setValues(HugeInteger &otherInt);
	HugeInteger& setValues(HugeInteger flipMyBit, bool signBit);
	HugeInteger& setValues(unsigned short tempValues[]);

	short unsigned int yugeInt[40] = { 0 };
	bool signBit{ 1 };
	HugeInteger(string& charVal, bool newSignBit);
	HugeInteger(unsigned short int newArray[], bool newSignBit);
	HugeInteger(void);
	HugeInteger(string& myVal);
	HugeInteger(const HugeInteger &otherInt);
	HugeInteger(HugeInteger flipMyBit, bool newBit);
	HugeInteger(unsigned short tempValues[]);
	//HugeInteger flipBitMethod(void) { return HugeInteger(this->yugeInt, this->signBit);}




	~HugeInteger();


	friend HugeInteger flipBit(HugeInteger flipMyBit); 

	void print(void);
	string printString(void);

	HugeInteger add(HugeInteger biggerInt);
	friend HugeInteger subtract(HugeInteger otherHugeInt, HugeInteger smallerInt);
	//constexpr unsigned int getArraySize(void) { return arraySize; }

	bool isLarger(HugeInteger otherHugeInt);
	const bool isPos(void);

};
