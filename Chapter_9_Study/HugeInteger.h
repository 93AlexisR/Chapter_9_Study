#pragma once
//Exercice 9.12 or something
using namespace std;

namespace myInteger {
	class HugeInteger {
	private:
		unsigned int stringSize{ 0 };
		short unsigned int yugeInt[100] = { 0 };
		const unsigned short arraySize{ sizeof(yugeInt) / sizeof(*yugeInt) };
		bool signBit{ 1 }; //positive by default
		bool isEmptyVar{ false }; //print function param
		bool isEmpty(void);
		unsigned int sigBits{ 0 };

		unsigned int sigBitCount(void); //returns significant bits
		unsigned int subtract_owedValue(const bool &owedFlag); //helper function for subtraction
		bool isLarger(HugeInteger &otherInt); //returns true if absolute value is bigger
		HugeInteger tempFlipBit(void) { return HugeInteger(yugeInt, !signBit); }

	public:
		HugeInteger(string& myVal);
		HugeInteger(unsigned short int newArray[], bool newSignBit);
		HugeInteger(void);
		~HugeInteger();

		void print(void);
		string printString(void);

		void copy(HugeInteger otherInt);
		void operator=(HugeInteger otherInt) { copy(otherInt); }

		HugeInteger add(HugeInteger biggerInt);
		HugeInteger operator+(HugeInteger otherInt) { return add(otherInt); }
		HugeInteger subtract(HugeInteger biggerInt);
		HugeInteger operator-(HugeInteger otherInt) { return subtract(otherInt); }
		HugeInteger multiply(HugeInteger otherInt);
		HugeInteger operator*(HugeInteger otherInt) { return multiply(otherInt); }
		HugeInteger modulo(HugeInteger otherInt);
		HugeInteger operator%(HugeInteger otherInt) { return modulo(otherInt); }
		HugeInteger absVal(void); //returns absolute value



		HugeInteger& minusOne(void);
		HugeInteger& plusOne(void);

		int getCppInt(void);
		HugeInteger& flipBit(void);

		bool isGreater(HugeInteger otherHugeInt);
		bool isEqual(HugeInteger &otherInt);

	};
}