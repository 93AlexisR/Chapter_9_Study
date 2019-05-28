#include "pch.h"
using namespace MyDataTypes;

HugeInteger::HugeInteger(unsigned short int newArray[], bool signBit) {
	this->signBit = signBit;
	for (unsigned int i = 0; i < arraySize; i++) {
		this->yugeInt[i] = newArray[i];
	}
	sigBits = sigBitCount();
}

HugeInteger::HugeInteger(std::string& charVal) {
	std::string tempString = charVal;
	stringSize = static_cast<unsigned int>(charVal.size());
	unsigned int i = 0;

	if (charVal[0] == '-') {
		this->signBit = false;
		stringSize--;
		charVal.erase(charVal.begin());
	}

	if (stringSize > arraySize) {
		std::cout << "Class HugeInteger can only hold" << arraySize << " digits." << std::endl;
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

	if (!signBit) {
		charVal = tempString;
	}
}

HugeInteger::HugeInteger(void) {
	isEmptyVar = true;
	//values already initialized in header
}

HugeInteger::~HugeInteger(){
	//cout << "I am destructoring" << endl;
}

//////////////////

bool HugeInteger::isEmpty(void) {
	for (unsigned int i = 0; i < arraySize; i++) {
		if (yugeInt[i] != 0) {
			isEmptyVar = false;
			return isEmptyVar;
		}
	}
	isEmptyVar = true;
	return isEmptyVar;
}

HugeInteger& HugeInteger::flipBit(void) {
	this->signBit = !(this->signBit);
	return *this;
}

void HugeInteger::copy(HugeInteger otherInt) {
	this->signBit = otherInt.signBit;
	this->sigBits = otherInt.sigBits;
	this->isEmptyVar = otherInt.isEmptyVar;
	for (unsigned int i = 0; i < arraySize; i++) {
		yugeInt[i] = otherInt.yugeInt[i];
	}
}	

void HugeInteger::print(void) {
	std::cout << printString();
}

std::string HugeInteger::printString(void) {
	std::string tempString;
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
		if (i == arraySize) {
			isEmptyVar = true;
		}
	} while (i++ < arraySize);
	if (isEmptyVar) {
		tempString.resize(1);
		tempString[0] = '0';
	}
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
	else {
		for (unsigned int i = 0; i < arraySize; i++) {
			if (yugeInt[i] != otherInt.yugeInt[i]) {
				return false;
			}
		}
	}
	return true;
}


HugeInteger HugeInteger::absVal(void) {
	return HugeInteger(this->yugeInt, true);
}

HugeInteger& HugeInteger::minusOne(void){ //will not work with edge cases, rebuild later
	bool owedFlag = true;
	isEmpty();
	if (isEmptyVar) {
		return *this; //value is 0;
	}
	if (signBit){
		if (yugeInt[arraySize - 1] > 0) {
			yugeInt[arraySize - 1] -= 1;
			isEmpty();
			return *this;
		}
		else{
			yugeInt[arraySize - 1] = 9;
			owedFlag = true;
			for (int i = (arraySize - 2); i > (arraySize - stringSize - 1); i--) {
				if (owedFlag == true) {
					if (yugeInt[i] < 1) {
						yugeInt[i] = 9;
					}
					else {
						yugeInt[i] -= 1;
						owedFlag = false;
					}
				}
			}
		}
	} 
	else {
		std::cout << "not yet coded lol" << std::endl;
		return *this;
	}	
	isEmpty();
	if (isEmptyVar) {
		std::cout << "oh noes, 0!" << std::endl;
	}
	return *this;
}

HugeInteger& HugeInteger::plusOne(void) { //will not work with edge cases, rebuild later
	unsigned short tempArray[40] = { 0 };
	tempArray[39] = 1;
	HugeInteger tempInt(tempArray, true); // basically "int tempInt = 1;"
	copy(add(tempInt));
	return *this;
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
		return false; 
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


HugeInteger HugeInteger::add(HugeInteger otherInt) {
	unsigned short int tempValues[sizeof(yugeInt) / sizeof(*yugeInt)] = { 0 };
	if (signBit) {
		if (!otherInt.signBit) { //(case +, -)
			if (otherInt.isLarger(*this)) { //if value thats neg is larger
				HugeInteger tempInteger;
				otherInt.flipBit();
				tempInteger.copy(otherInt.subtract(*this));
				otherInt.flipBit(); tempInteger.flipBit();
				return tempInteger; //return -(abs(b) - abs(a))
			}
			else {
				HugeInteger tempInteger(otherInt.yugeInt, true);
				return subtract(tempInteger); //*this.subtract(abs(otherInt));
			}
		}
		else { //case +,+
			if ((yugeInt[0] + otherInt.yugeInt[0]) > 9) {
				std::cout << "HugeInteger overflow (more than 40 decimal places)" << std::endl; //don't comment me out
				abort();
			}
			for (int i = (arraySize - 1); i >= 0; i--) {
				if ((yugeInt[i] + otherInt.yugeInt[i] + tempValues[i]) > 9) {
						tempValues[i] += (yugeInt[i] + otherInt.yugeInt[i] - 10);
						tempValues[i - 1] = 1;
				}
				else {
					tempValues[i] += yugeInt[i] + otherInt.yugeInt[i];
				}
			}
			return HugeInteger(tempValues, true);
		}
	}
	else if (!signBit) {
		if (otherInt.signBit) { // case -, +
			if (isLarger(otherInt)) {
				flipBit(); 
				HugeInteger tempInt(subtract(otherInt));
				flipBit(); tempInt.flipBit();
				return tempInt; // return -(abs(a) - abs(b))
			}
			else {
				HugeInteger tempInt;
				flipBit();
				tempInt.copy(otherInt.subtract(*this)); //return b - a
				flipBit();
				return tempInt;
			}
		}
		else { //case -, -
			flipBit(); otherInt.flipBit(); //pretend we're adding two pos nums and return neg
			HugeInteger tempInt(add(otherInt));
			flipBit(); otherInt.flipBit(); tempInt.flipBit();
			return tempInt;
		}
	}
	else {
		return HugeInteger();
	}
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
	bool owedFlag{ false };
	const unsigned int baseTenConstant{ 10 };
	if (!signBit && otherInt.signBit) {
		if (yugeInt[0] + otherInt.yugeInt[0] > 9) {
			std::cout << "HugeInteger overflow (subtract)" << std::endl;
			abort();
		}
	}
	if (signBit) {
		if (!otherInt.signBit) {// case (+,-) or +,-(+)
			HugeInteger tempInt;
			otherInt.flipBit();
			tempInt.copy(add(otherInt));
			otherInt.flipBit();
			return tempInt;
		}
		else { //case +,+ or +,-(+)
			if (otherInt.isGreater(*this)) {
				return otherInt.subtract(*this).flipBit(); //goals
			}
			else {
				//if (!isEqual(otherInt)) not working, fix later
				for (int i = arraySize - 1; i > (arraySize - stringSize - 1); i--) {
					if (yugeInt[i] < (otherInt.yugeInt[i] + subtract_owedValue(owedFlag))) {
						tempValues[i] = (yugeInt[i] + baseTenConstant) - otherInt.yugeInt[i] - subtract_owedValue(owedFlag);
						owedFlag = true;
					}
					else {
						tempValues[i] = yugeInt[i] - otherInt.yugeInt[i] - subtract_owedValue(owedFlag);
						owedFlag = false;
					}
				}
				return HugeInteger(tempValues, true);
			}
		}
	}
	if (!signBit) {
		if (otherInt.signBit) { // case -, 
			HugeInteger tempInt;
			flipBit();
			tempInt.copy(add(otherInt)); //
			tempInt.flipBit(); flipBit();
			return tempInt;
		}
		else { // case -,-
			HugeInteger tempInteger;
			otherInt.flipBit();
			tempInteger.copy(otherInt.add(*this));
			otherInt.flipBit();
			tempInteger.flipBit();
			return tempInteger;
		}
	}
	else {
		return HugeInteger();
	}
}

HugeInteger HugeInteger::multiply(HugeInteger otherInt){
	if (otherInt.isEmpty() || isEmpty()) {
		return HugeInteger(); //return 0;
	}
	if (!isLarger(otherInt)) {
		return otherInt.multiply(*this);
	}
	HugeInteger tempInt;
	HugeInteger myIndex(otherInt); //using other int as an index to add multiple tiimes
	if (!signBit) {
		if (otherInt.signBit) {//case -,+
			flipBit();
			tempInt.copy(multiply(otherInt));
			tempInt.flipBit(); flipBit();
		}
		else {//case --
			flipBit(); otherInt.flipBit();
			tempInt.copy(multiply(otherInt));
			flipBit(); otherInt.flipBit(); 
		}
	}
	else {
		if (!otherInt.signBit) {//case +,-
			otherInt.flipBit();
			tempInt.copy(multiply(otherInt));
			tempInt.flipBit(); otherInt.flipBit();
		}
		else { //case ++
			do {
				tempInt.copy(tempInt.add(*this));
				myIndex.minusOne();
			} while (!myIndex.isEmptyVar);
		}
	}
	return tempInt;
}

HugeInteger HugeInteger::modulo(HugeInteger otherInt) {
	if (otherInt.isEmpty() || isEmpty()) {
		return HugeInteger(); //return 0;
	}
	if (!isLarger(otherInt)) {
		return otherInt.multiply(*this);
	}
	HugeInteger tempInt(*this);
	HugeInteger myIndex; 
	if (!signBit) {
		if (otherInt.signBit) {//case -,+
			flipBit();
			tempInt.copy(multiply(otherInt));
			tempInt.flipBit(); flipBit();
		}
		else {//case --
			flipBit(); otherInt.flipBit();
			tempInt.copy(multiply(otherInt));
			flipBit(); otherInt.flipBit();
		}
	}
	else {
		if (!otherInt.signBit) {//case +,-
			otherInt.flipBit();
			tempInt.copy(multiply(otherInt));
			tempInt.flipBit(); otherInt.flipBit();
		}
		else { //case ++
			do {
				std::cout << "tempInt = " << tempInt.printString() << std::endl;
				tempInt.copy(tempInt.subtract(otherInt));
				//myIndex.plusOne(); //stores division value, useful later
			} while (tempInt.isGreater(otherInt));
		}
	}
	return tempInt;
}


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

