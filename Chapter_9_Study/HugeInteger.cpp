#include "pch.h"
#include "HugeInteger.h"
using namespace std;

HugeInteger& HugeInteger::setValues(string& charVal, bool signBit) { //essential
	this->signBit = signBit;
	stringSize = static_cast<unsigned int>(charVal.size());
	if (!this->signBit) {
		for (unsigned int i = 0; i < arraySize; i++) {
			if (i < (arraySize - stringSize)) { // initialize to 0 until non-zero value is expected
				yugeInt[i] = 0;
			}
			else {
				//cout << "charVal[" << i << "] = " << charToInt(charVal[i - (arraySize - stringSize)]) << endl;
				yugeInt[i] = charToInt(charVal[i - (arraySize - stringSize)]);
			}
		}
		return *this;
	}
	else {
		for (unsigned int i = 0; i < arraySize; i++) {
			if (i < (arraySize - stringSize)) { // initialize to 0 until non-zero value is expected
				yugeInt[i] = 0;
			}
			else {
				//cout << "charVal[" << i << "] = " << charToInt(charVal[i - (arraySize - stringSize)]) << endl;
				yugeInt[i] = charToInt(charVal[i - (arraySize - stringSize)]);
			}
		}
	}
	return *this;
}

HugeInteger::HugeInteger(string& charVal, bool signBit) { //essential
	setValues(charVal, signBit);
}

HugeInteger& HugeInteger::setValues(string& charVal) { //essential
	if (charVal[0] == '-') {
		charVal[0] = '0';
		setValues(charVal, false);
	}
	else {
		setValues(charVal, true);
	}	
	return *this;
}

HugeInteger::HugeInteger(string& charVal) { //essential for user
	setValues(charVal);
}

HugeInteger::HugeInteger(void) { //default
	string tempString{ "0" };
	setValues(tempString, true);
}



HugeInteger& HugeInteger::setValues(unsigned short int newArray[], bool signBit) {
	this->signBit = signBit;
	//cout << "this->signBit = signBit = " << signBit << endl;
	for (unsigned int i = 0; i < arraySize; i++) {
		this->yugeInt[i] = newArray[i];
		//cout << "yugeInt[" << i << "] = " << yugeInt[i] << endl;
	}
	return *this;
}

HugeInteger::HugeInteger(unsigned short int newArray[], bool signBit) {
	setValues(newArray, signBit);
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


HugeInteger::~HugeInteger(){
	//cout << "I am destructoring" << endl;
}

void HugeInteger::print(void) {
	cout << printString();
}

string HugeInteger::printString(void) {
	string tempString;
	unsigned short indexMod = 0;
	if (!signBit) {
		indexMod = 1;
		tempString.resize(arraySize + indexMod);
		tempString[0] = '-';
		//cout << tempString.size() << endl;
	}
	else {
		tempString.resize(arraySize);
	}

	
	for (int i = 0; i < arraySize; i++) {
		if (!signBit && i == 0) {
			i++;
		}
		//cout << "yugeInt[" << i << "] = " << yugeInt[i] << endl;	
		if (yugeInt[i] != 0) {
			for (unsigned int j = i; j < arraySize; j++) {
				//cout << "we are inside 2nd loop at [" << j << "]" << endl;
				if (!signBit && j == 1) {
				//	cout << "j++" << endl;
					j++;
				}
				//cout << "tempString[" << j << " - " << i <<
				//	" + " << +indexMod << "] = " << yugeInt[j - 2 * indexMod] << endl;
				tempString[j - i + indexMod] = intToChar(yugeInt[j]);
			}
			break;
		}
	}
	return tempString;
}



HugeInteger HugeInteger::add(HugeInteger otherHugeInt) {
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
		return HugeInteger(tempValues, true);
	}

}

bool HugeInteger::isLarger(HugeInteger otherValue) {
	bool areBothNeg = false;
	if (signBit != otherValue.signBit) {
		if (signBit && !otherValue.signBit) {
			return true;
		}
		else {
			return false;
		}
	}
	if (!signBit && !otherValue.signBit) {
		areBothNeg = true;
	}

	for (unsigned int i = 0; i < arraySize; i++) {
		//cout << "lvalue[" << i << "] = " << yugeInt[i] << " >? rightValue[" << i << "] =  " << otherValue.yugeInt[i] << endl;
		if (yugeInt[i] > otherValue.yugeInt[i]) {
			//cout << "break at i = " << i << endl;
			if (areBothNeg) {
				return false;
			}
			return true;
		}
		else if (yugeInt[i] < otherValue.yugeInt[i]) {
			return false;
		}
	}
	return false;
}

const bool HugeInteger::isPos(void) {
	if (signBit == true) {
		return signBit;
	}
	else {
		return !signBit;
	}
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
}


/*
HugeInteger::HugeInteger(const HugeInteger &flipMyBit) {
	setValues(flipMyBit, flipMyBit.signBit);
}
HugeInteger& setValues(HugeInteger flipMyBit, bool signBit) {

}
*/


HugeInteger flipBit(HugeInteger flipMyBit) {
	//cout << "we're flipping stuff" << endl;
	return HugeInteger(flipMyBit, !flipMyBit.signBit);
}
HugeInteger::HugeInteger(HugeInteger flipMyBit, bool signBit) {
	setValues(flipMyBit.yugeInt, signBit);
}


