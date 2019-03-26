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

HugeInteger& HugeInteger::copy(HugeInteger otherInt) {
	this->signBit = otherInt.signBit;
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

bool HugeInteger::isLarger(HugeInteger otherInt) {

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
	return false;
}


/*

HugeInteger HugeInteger::add(HugeInteger otherHugeInt) {
	cout << "case ++" << endl;

	unsigned short int tempValues[sizeof(yugeInt) / sizeof(*yugeInt)] = { 0 };

	if (!isLarger(otherHugeInt)) {
		std::cout << "Arranging logic and stuff" << endl;
		return otherHugeInt.add(*this); //rearrange variables for logic to work
	}
	if (!signBit && !otherHugeInt.signBit) { // case (-, -)
		cout << "addition: entering case -, -!" << endl;
		return flipBit(flipBit(*this).add(flipBit(otherHugeInt)));
	}

	else if (signBit && !otherHugeInt.signBit) { //(case +, -)
		cout << "addition: entering case +, -!" << endl;
		print();
		std::cout << std::endl;
		flipBit(otherHugeInt).print();
		return subtract(*this, flipBit(otherHugeInt));
	}

	else if (!signBit && otherHugeInt.signBit) { //(case -, +)
		cout << "addition: entering case -, +!" << endl;
		return flipBit(subtract(flipBit(*this), otherHugeInt));
	}

	else {
		// case (+,+)
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
	}
	return HugeInteger(tempValues);
}

*/


/*


HugeInteger HugeInteger::add(HugeInteger otherHugeInt) {
	cout << "case ++" << endl;

	unsigned short int tempValues[sizeof(yugeInt) / sizeof(*yugeInt)] = { 0 };

	if (!isLarger(otherHugeInt)) {
		std::cout << "Arranging logic and stuff" << endl;
		return otherHugeInt.add(*this); //rearrange variables for logic to work
	}
	if (!signBit && !otherHugeInt.signBit) { // case (-, -)
		cout << "addition: entering case -, -!" << endl;
		return flipBit(flipBit(*this).add(flipBit(otherHugeInt)));
	}

	else if (signBit && !otherHugeInt.signBit) { //(case +, -)
		cout << "addition: entering case +, -!" << endl;
		print();
		std::cout << std::endl;
		flipBit(otherHugeInt).print();
		return subtract(*this, flipBit(otherHugeInt));
	}

	else if (!signBit && otherHugeInt.signBit) { //(case -, +)
		cout << "addition: entering case -, +!" << endl;
		return flipBit(subtract(flipBit(*this), otherHugeInt));
	}

	else {
		// case (+,+)
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
	}
	return HugeInteger(tempValues);
}



HugeInteger subtract(HugeInteger biggerInt, HugeInteger smallerInt) {
	unsigned short int* tempValues = new unsigned short[biggerInt.arraySize] {0};

	if (smallerInt.isLarger(biggerInt)) {
		return subtract(smallerInt, biggerInt); //rearrange variables for logic to work
	}

	bool owedFlag{ false };
	int owedPosition = 0;

	for (int i = biggerInt.arraySize - 1; i > biggerInt.arraySize - biggerInt.stringSize - 1; i--) {
		//cout << "owedFlag = " << owedFlag ? "TRUE" : "FALSE";
		std::cout << std::endl;
		//cout << endl;
		//cout << "owedPosition = " << owedPosition << endl;
		//cout << "yugeInt[" << i << "] = " << yugeInt[i] << endl;

		if (biggerInt.yugeInt[i] < smallerInt.yugeInt[i] && owedFlag == 0) {
			owedFlag = 1;
			owedPosition = i - 1;
			//cout << "Entering yuge < otherHuge and owedPosition = " << owedPosition << endl;
			biggerInt.yugeInt[i] += 10;
		}

		else if (owedFlag == 1 && i == owedPosition) {
			//cout << "entering owedflag and owed position conditional statement" << endl;
			if (biggerInt.yugeInt[i] > 0) {
				//cout << "Entering yugeint[i] > 0" << endl;
				owedFlag = 0;
				biggerInt.yugeInt[i] -= 1;
			}
			else {
				//cout << "carrying over..." << endl;
				biggerInt.yugeInt[i] = 9;
				owedPosition--;
			}

		}
		tempValues[i] = biggerInt.yugeInt[i] - smallerInt.yugeInt[i];
		//cout << "tempValues[" << i << "] =  " << yugeInt[i] << " - " << otherHugeInt.yugeInt[i] << endl;
		//cout << "end of loop " << i << endl << endl << endl;
	}

	return HugeInteger(tempValues, true);
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
	*/



/*

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