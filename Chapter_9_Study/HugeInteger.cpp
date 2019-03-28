#include "pch.h"
#include "HugeInteger.h"
using namespace std;

HugeInteger::HugeInteger(unsigned short int newArray[], bool signBit) {
	this->signBit = signBit;
	for (unsigned int i = 0; i < arraySize; i++) {
		this->yugeInt[i] = newArray[i];
	}
	sigBits = sigBitCount();
}

/*HugeInteger::HugeInteger(const char charList[]) { // TODO
	stringSize = sizeof(charList);
	cout << stringSize;
	for (unsigned int i = 0; i < stringSize; i++) {
		if (&charList[i] == nullptr) {
			cout << "[" << i << "] " << charList[i] << endl;
		}
	}
	cout << "stringSize = " << stringSize << endl;
	string newString;
	newString.resize(stringSize);
	cout << newString.size() << endl;
	{
		unsigned int i = 0;
		for (auto v : newString) {
			newString[v] = charList[i];
			i++;
		}
	}

	if (stringSize > (arraySize + 1)) {
		cout << "Class HugeInteger can only hold" << arraySize << " digit." << endl;
		abort();
	}

	if (charList[0] == '-') {
		this->signBit = false;
		yugeInt[0] = '0';
	}


	for (unsigned int i = 0; i < arraySize-1; i++) {
		std::cout << i << std::endl;

		if (i < (arraySize - stringSize)) { // initialize to 0 until non-zero value is expected
			yugeInt[i] = 0;
		}
		else {
			
			yugeInt[i] = charToInt(newString[i - (arraySize - stringSize)]);
			cout << yugeInt[i];
		}
	}

	cout << endl;
}
*/

HugeInteger::HugeInteger(string& charVal) {
	stringSize = charVal.size();
	unsigned int i = 0;

	if (charVal[0] == '-') {
		this->signBit = false;
		stringSize--;
		charVal.erase(charVal.begin());
	}

	if (stringSize > arraySize) {
		cout << "Class HugeInteger can only hold" << arraySize << " digits." << endl;
		abort();
	}

	do{	
		if (i < (arraySize - stringSize)) { // initialize to 0 until non-zero value is expected
			yugeInt[i] = 0;
		}
		else {
			yugeInt[i] = charToInt(charVal[i - (arraySize - stringSize)]);
		}
	} while (++i < arraySize);

	sigBits = sigBitCount();
}

HugeInteger::HugeInteger(void) {
	//values already initialized in header
}

HugeInteger::~HugeInteger(){
	//cout << "I am destructoring" << endl;
}

//////////////////

HugeInteger flipBit(HugeInteger flipMyBit) {
	return HugeInteger(flipMyBit.yugeInt, !flipMyBit.signBit);
}

HugeInteger& HugeInteger::copy(HugeInteger otherInt) {
	this->signBit = otherInt.signBit;
	this -> sigBits = otherInt.sigBits;
	for (unsigned int i = 0; i < arraySize; i++) {
		this->yugeInt[i] = yugeInt[i];
	}
	return *this;
}

void HugeInteger::print(void) {
	cout << printString();
}

string HugeInteger::printString(void) {
	string tempString;
	unsigned int i = 0;
	unsigned short indexMod = 0;
	if (!signBit) {
		indexMod = 1;
		i++;
	}
	tempString.resize(arraySize + indexMod);
	do{
		if (!(yugeInt[i] == 0)) { // start printing when non-zero values exist
			for (unsigned int j = i; j < arraySize; j++) {
				tempString[j - i + indexMod] = intToChar(yugeInt[j]);
			}
			if (!signBit) {
				tempString[0] = '-';
			}
			break;
		}
	} while (i++ < arraySize);
	return tempString;
}

unsigned int HugeInteger::sigBitCount(void){
	for (unsigned int v = 0; v < arraySize; v++) {
		if (yugeInt[v] != 0) {
			return (arraySize - v);
		}
	}
	return 0;
}

bool HugeInteger::isEqual(HugeInteger &otherInt) {
	if (signBit != otherInt.signBit) {
		return false;
	}
	for (unsigned int i = 0; i < arraySize; i++) {
		if (yugeInt[i] != otherInt.yugeInt[i]) {
			return false;
		}
	}
	return true;
}


HugeInteger HugeInteger::absVal(void) {
	return HugeInteger(this->yugeInt, true);
}

bool HugeInteger::isLarger(HugeInteger &otherInt) { //const
	for (unsigned int i = 0; i < arraySize; i++) {
		if (yugeInt[i] > otherInt.yugeInt[i]) {
			return true;
		}
	}
	return false;
} //returns true if absolute value is bigger


bool HugeInteger::isGreater(HugeInteger otherInt) {
	if (isEqual(otherInt)) {
		return false;
	}
	if (signBit != otherInt.signBit) {
		if (signBit && !otherInt.signBit) {
			return true;
		}
		else {
			return false;
		}
	}
	bool areBothNeg = false;
	if (!signBit && !otherInt.signBit) {
		areBothNeg = true;
	}
	if ( !areBothNeg && (sigBits < otherInt.sigBits) ) {
		return false; //rearranging variables for logic purposes
	}
	else {
		return true;
	}
	if (areBothNeg && (sigBits < otherInt.sigBits)) {
		return true;
	}
	return isLarger(otherInt);
}



////////////////////////////helper functions above


HugeInteger HugeInteger::add(HugeInteger otherHugeInt) {

	unsigned short int tempValues[sizeof(yugeInt) / sizeof(*yugeInt)] = { 0 };

	/*
	if (!signBit && !otherHugeInt.signBit) { // case (-, -)
		cout << "addition: entering case -, -!" << endl;
		return flipBit(flipBit(*this).add(flipBit(otherHugeInt)));
	}



	else if (!signBit && otherHugeInt.signBit) { //(case -, +)
		cout << "addition: entering case -, +!" << endl;
		return flipBit(subtract(flipBit(*this), otherHugeInt));
	}
	*/

	if (signBit && !otherHugeInt.signBit) { //(case +, -)
		cout << "addition: entering case +, -!" << endl;
		HugeInteger tempInteger(otherHugeInt.yugeInt, true);
		return subtract(tempInteger);
	}
	for (int i = (arraySize - 1); i >= 0; i--) {
		if ((yugeInt[i] + otherHugeInt.yugeInt[i]) > 9) {
			if (i == 0) {
				std::cout << "HugeInteger overflow (more than 40 decimal places)" << endl; //don't comment me out
				abort();
			}
			else {
				tempValues[i] += (yugeInt[i] + otherHugeInt.yugeInt[i] - 10);
				tempValues[i - 1] = 1;
			}
		}
		else {
			tempValues[i] += yugeInt[i] + otherHugeInt.yugeInt[i];
		}
	}
	return HugeInteger(tempValues, true);
}

unsigned int HugeInteger::subtract_owedValue(const bool &owedFlag) {
	if (owedFlag) {
		return 1;
	}
	else {
		return 0;
	}
}

HugeInteger HugeInteger::subtract(HugeInteger otherInt) {
	unsigned short tempValues[40] = { 0 };
	bool areBothNeg{ false };


	if (otherInt.sigBits > sigBits) {
		return otherInt.subtract(*this);
	}
	else if ((otherInt.sigBits == sigBits) && !signBit) {
		areBothNeg = true;
		if (yugeInt[0] + otherInt.yugeInt[0] > 9) {
			cout << "HugeInteger overflow (subtract)" << endl;
			abort();
		}
	}

	//case +,+
	//logic if the rvalue is larger than the right 
	if (!isLarger(otherInt)) {
		cout << "case you just coded works" << endl;
		HugeInteger tempInt(otherInt.yugeInt, true);
		return tempInt.subtract(*this);
	}

	bool owedFlag{ false };
	const unsigned int baseTenConstant{ 10 };

	for (int i = arraySize - 1; i > (arraySize - stringSize - 1); i--) {
		if (yugeInt[i] < (otherInt.yugeInt[i] + subtract_owedValue(owedFlag))) {
			tempValues[i] = (yugeInt[i] + baseTenConstant) - otherInt.yugeInt[i] - subtract_owedValue(owedFlag);
			owedFlag = true;
		}
		else{
			tempValues[i] = yugeInt[i] - otherInt.yugeInt[i] - subtract_owedValue(owedFlag);
			owedFlag = false;
		}
	}
	return HugeInteger(tempValues, true);
}



/*

	else if (signBit && otherHugeInt.signBit) { // if both numbers are positive
		bool owedFlag = 0; //determines if we need to carry over a -1 operation to the next pos
		unsigned int owedPosition = 0; //flag is necessary as the data type of yugeInt is unsigned
		std::cout << "We have entered case (+, +)! in subtract " << endl;

		if (yugeInt[0] < otherHugeInt.yugeInt[0]) {
			std::cout << "HugeInteger overflow (SUBSTRACTION OPERATION)" << endl; //false
			abort();
		}
	}

	}



	else if (signBit && !otherHugeInt.signBit) {
		return add(HugeInteger(otherHugeInt.yugeInt, true)); //lvalue is pos then it gets added smth
	}

	else if (!signBit && !otherHugeInt.signBit) {//
		return flipBit(flipBit(*this).subtract(flipBit(otherHugeInt))); //pretend theyre both case 0,0 and return value with neg sign
	} // logic if go

	else { // case !signBit && otherHugeInt.signBit
		return flipBit(*this).subtract(otherHugeInt); //adds both values and sticks a minus sign in front
	}





HugeInteger& HugeInteger::setValues(HugeInteger flipMyBit, bool signBit) {

	return *this;
}

HugeInteger::HugeInteger(const HugeInteger &flipMyBit) {
	setValues(flipMyBit, signBit);
}

HugeInteger::HugeInteger(HugeInteger flipMyBit, bool signBit) {
	setValues(flipMyBit, signBit);
}

HugeInteger flipBit(HugeInteger flipMyBit) {
	//cout << "we're flipping stuff" << endl;
	return HugeInteger(flipMyBit, !flipMyBit.signBit);
}

HugeInteger::HugeInteger(unsigned short tempValues[]) {
	setValues(tempValues);
}

HugeInteger& HugeInteger::setValues(const HugeInteger &otherInt) {
	this->signBit = otherInt.signBit;
	for (unsigned int i = 0; i < arraySize; i++) {
		this->yugeInt[i] = otherInt.yugeInt[i];
	}
	return *this;
}

HugeInteger& HugeInteger::setValues(HugeInteger &otherInt) {
	this->signBit = otherInt.signBit;
	for (unsigned int i = 0; i < arraySize; i++) {
		this->yugeInt[i] = otherInt.yugeInt[i];
	}
	return *this;
}
	*/


int HugeInteger::getCppInt(void) {
	int tempInt{ 0 };

	for (int i = arraySize - 1; i >= (arraySize - sigBits); i--) {
		tempInt += static_cast<int>(this->yugeInt[i])*pow(10, (arraySize-1)-i);
	}
	
	if (signBit) {
		return tempInt;
	}
	else {
		return -tempInt;
	}
}