#include "pch.h"
#include "HugeInteger.h"


HugeInteger::HugeInteger(string& charVal, bool newSignBit) {
	signBit = newSignBit;
	stringSize = static_cast<unsigned int>(charVal.size());
	if (!signBit) {
		//cout << "entering !signBit" << endl;
		stringSize--;
		for (unsigned int i = 0; i < arraySize; i++) {
			if (i < (arraySize - stringSize)) { // initialize to 0 until non-zero value is expected
				yugeInt[i] = 0;
			}
			else {
				//cout << "charVal[" << i << "] = " << charToInt(charVal[i - (arraySize - stringSize)]) << endl;
				//yugeInt[i] = charToInt(charVal[i - (arraySize - stringSize)]);
			}
		}
		return;
	}
	else if (signBit) {
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
}

HugeInteger::HugeInteger(string charVal) {
	if (static_cast<unsigned int>(charVal[0]) == 45) {
		charVal[0] = 48;
		//cout << "This is a negative number!"  << endl;
		*this = HugeInteger(charVal, false);
	}
	else {
		*this = HugeInteger(charVal, true);
	}
}


HugeInteger::HugeInteger(void) {
	string tempString{ "0" };
	*this = HugeInteger(tempString, true);
}


HugeInteger::HugeInteger(unsigned short int newArray[]) {
	*this = HugeInteger(newArray, true);
}

HugeInteger::HugeInteger(unsigned short int newArray[], bool newSignBit) {
	signBit = newSignBit;
	for (unsigned int i = 0; i < arraySize; i++) {
		this->yugeInt[i] = newArray[i];
		//cout << "yugeInt[" << i << "] = " << yugeInt[i] << endl;
	}
}

HugeInteger::~HugeInteger(){
	//cout << "I am destructoring" << endl;
}

void HugeInteger::print(void) {
	cout << printString();
}

string HugeInteger::printString(void) {
	string tempString;
	for (unsigned int i = 0; i < arraySize; i++) {
			//cout << "yugeInt[" << i << "] = " << yugeInt[i] << endl;
			if (yugeInt[i] != 0) {
				tempString.resize(arraySize-i);
				for (unsigned int j = i; j < arraySize; j++) {
					//cout << "tempString[" << j << " - " << i << "] = " << yugeInt[j] << endl;
					tempString[j-i] = intToChar(yugeInt[j]);
				}
				break;
			}
		}
	return tempString;
}


HugeInteger HugeInteger::flipBit(HugeInteger flipMyBit) {
	return HugeInteger(flipMyBit.yugeInt, !flipMyBit.signBit);
}

HugeInteger HugeInteger::add(HugeInteger otherHugeInt) {
	unsigned short int tempValues[sizeof(yugeInt) / sizeof(*yugeInt)] = { 0 };
	if (!isLarger(otherHugeInt)) {
		return otherHugeInt.add(*this); //rearrange variables for logic to work 
	}
	if (!signBit && !otherHugeInt.signBit) { // case (-, -)
		return flipBit(flipBit(*this).add(flipBit(otherHugeInt)));
	}
	else if (signBit && !otherHugeInt.signBit) { //(case +, -)
		return subtract(flipBit(otherHugeInt));
	}
	else if (!signBit && otherHugeInt.signBit) { //(case -, +)
		return flipBit(flipBit(*this).subtract(otherHugeInt));
	}
	else{ // case (+,+)
		for (int i = arraySize - 1; i >= 0; i--) { //what the fuck why does unsigned int i not work
		//cout << "i is: " << i << endl;
		//cout << "(yugeInt[i] + otherHugeInt.yugeInt[i]) is equal to: " << static_cast<unsigned int>(yugeInt[i] + otherHugeInt.yugeInt[i]) << endl;
			if ((yugeInt[i] + otherHugeInt.yugeInt[i]) > 9) {
				if (i == 0) {
					std::cout << "HugeInteger overflow (more than 40 decimal places)" << endl; //don't comment me out
					abort();
				}
				else {
					//cout << "tempValues[" << i << "] before the carry over = " << tempValues[i] << endl;
					//cout << "yugeInt[i] + tempValues[i] + otherHugeInt.yugeInt[i] - 10 is eq. to " << 
					//	tempValues[i] << " + " << otherHugeInt.yugeInt[i] << " + " << yugeInt[i] << " - 10" << endl;
					tempValues[i] += (yugeInt[i] + otherHugeInt.yugeInt[i] - 10);
					tempValues[i - 1] = 1;
					//cout << "tempValues[" << i << "] after the carry over = " << tempValues[i] << endl;
					//cout << "tempValues[" << i-1 << "] after the carry over = " << tempValues[i-1] << endl;

				}
			}
			else {
				tempValues[i] += yugeInt[i] + otherHugeInt.yugeInt[i];
			}
			std::cout << tempValues[i] << endl;
		}
		return HugeInteger(tempValues);
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

bool HugeInteger::isPos(void) {
	if (signBit == true) {
		return signBit;
	}
	else {
		return !signBit;
	}
}

HugeInteger HugeInteger::subtract(HugeInteger otherHugeInt) {

	unsigned short int tempValues[sizeof(yugeInt) / sizeof(*yugeInt)] = { 0 };
	
	if (!isLarger(otherHugeInt)) {
		return otherHugeInt.subtract(*this); //rearrange variables for logic to work 
	}
	
	else if (signBit && otherHugeInt.signBit) { // if both numbers are positive
		bool owedFlag = 0; //determines if we need to carry over a -1 operation to the next pos
		unsigned int owedPosition = 0; //flag is necessary as the data type of yugeInt is unsigned 
		std::cout << "We have entered case (+, +)! " << endl;
		
		if (yugeInt[0] < otherHugeInt.yugeInt[0]) {
			std::cout << "HugeInteger overflow (SUBSTRACTION OPERATION)" << endl; //false
			abort();
		}
		
		for (unsigned int i = arraySize - 1; i > arraySize - stringSize -1 ; i--) {
			//cout << "owedFlag = " << owedFlag ? "TRUE" : "FALSE";
			//cout << endl;
			//cout << "owedPosition = " << owedPosition << endl;
			//cout << "yugeInt[" << i << "] = " << yugeInt[i] << endl;

			if (yugeInt[i] < otherHugeInt.yugeInt[i] && owedFlag == 0) {
				owedFlag = 1;
				owedPosition = i-1;
				//cout << "Entering yuge < otherHuge and owedPosition = " << owedPosition << endl;
				yugeInt[i] += 10;
			}

 			if ( owedFlag == 1 && i == owedPosition) {
				//cout << "entering owedflag and owed position conditional statement" << endl;
				if (yugeInt[i] > 0) {
					//cout << "Entering yugeint[i] > 0" << endl;
					owedFlag = 0;
					yugeInt[i] -= 1;
				}
				else {
						//cout << "carrying over..." << endl;
						yugeInt[i] = 9;
						owedPosition--;
				}

			}
			tempValues[i] = yugeInt[i] - otherHugeInt.yugeInt[i];
			cout << "tempValues[" << i << "] =  " << yugeInt[i] << " - " << otherHugeInt.yugeInt[i] << endl;
			cout << "end of loop " << i << endl << endl << endl;
		}

		return HugeInteger(tempValues, true);

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
}

