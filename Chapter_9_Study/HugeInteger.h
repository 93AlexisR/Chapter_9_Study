#pragma once
//Exercice 9.12 or something
using namespace std;

namespace myInteger {
	class HugeInteger {
	public:

		//private:
		unsigned int stringSize{ 0 };
		short unsigned int yugeInt[40] = { 0 };
		const unsigned short arraySize{ sizeof(yugeInt) / sizeof(*yugeInt) };
		bool signBit{ 1 };
		bool isEmptyVar{ false }; //print function param
		bool isEmpty(void);
		unsigned int sigBits{ 0 };

		unsigned int sigBitCount(void); //returns significant bits
		unsigned int subtract_owedValue(const bool &owedFlag); //helper function for subtraction
		bool isLarger(HugeInteger &otherInt); //returns true if absolute value is bigger
		HugeInteger absVal(void); //returns absolute value
		HugeInteger tempFlipBit(void) { return HugeInteger(yugeInt, !signBit); }
		HugeInteger& minusOne(void);
		HugeInteger& plusOne(void);

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
		HugeInteger multiply(HugeInteger otherInt);
		HugeInteger modulo(HugeInteger otherInt);

		int getCppInt(void);
		HugeInteger& flipBit(void);

		bool isGreater(HugeInteger otherHugeInt);
		bool isEqual(HugeInteger &otherInt);

	};
}