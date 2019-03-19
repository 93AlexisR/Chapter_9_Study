#include "pch.h"
#include "HugeInteger.h"


HugeInteger::HugeInteger(string& charVal, bool newSignBit) {
	signBit = newSignBit;
	stringSize = static_cast<unsigned int>(charVal.size());
	for (unsigned int i = 0; i < arraySize; i++) {
		if (i < arraySize - stringSize) {
			yugeInt[i] = 0;
		}
		else {
			yugeInt[i] = charToInt(charVal[i - (arraySize - stringSize)]);
		}
	}
}

HugeInteger::HugeInteger(string& charVal) {
	HugeInteger(charVal, true);
}


HugeInteger::HugeInteger(void) {
	string tempString{ "0" };
	HugeInteger(tempString);
}


HugeInteger::HugeInteger(unsigned short int newArray[]) {
	HugeInteger(newArray, true);
}

HugeInteger::HugeInteger(unsigned short int newArray[], bool newSignBit) {
	signBit = newSignBit;
	for (unsigned int i = 0; i < arraySize; i++) {
		this->yugeInt[i] = newArray[i];
		//cout << "intConstructor running... i = " << i << " and yugeInt[i] = " << yugeInt[i] << endl;
	}
}

HugeInteger::~HugeInteger(){
}

HugeInteger& HugeInteger::printVal(void) {
	unsigned int startPrint = 0;
	for (unsigned int i = 0; i < arraySize; i++) {
		if (yugeInt[i] != 0) {
			startPrint = i;
			break;
		}
	}
	if (!signBit) {
		cout << "-";
	}
	for (unsigned int i = startPrint; i < arraySize; i++){
			cout << yugeInt[i];
	}
	return *this;
}

HugeInteger HugeInteger::flipBit(HugeInteger flipMyBit) {
	return HugeInteger(flipMyBit.yugeInt, !flipMyBit.signBit);
}



HugeInteger HugeInteger::add(HugeInteger otherHugeInt) {

	if (!otherHugeInt.signBit) { // if 2nd number is negative, subtract instead
		return subtract(otherHugeInt);
	}


	unsigned short int tempValues[sizeof(yugeInt) / sizeof(*yugeInt)] = { 0 };
	
	for (int i = arraySize - 1; i >= 0; i--) { //what the fuck why does unsigned int i not work
		cout << "i is: " << i << endl;
		//cout << "(yugeInt[i] + otherHugeInt.yugeInt[i]) is equal to: " << static_cast<unsigned int>(yugeInt[i] + otherHugeInt.yugeInt[i]) << endl;
		if ((yugeInt[i] + otherHugeInt.yugeInt[i]) > 9){
			if (i == 0) {
				cout << "HugeInteger overflow" << endl;
				abort();
			}
			else{
				cout << "tempValues[" << i << "] before the carry over = " << tempValues[i] << endl;
				cout << "yugeInt[i] + tempValues[i] + otherHugeInt.yugeInt[i] - 10 is eq. to " << 
					tempValues[i] << " + " << otherHugeInt.yugeInt[i] << " + " << yugeInt[i] << " - 10" << endl;
				tempValues[i] += (yugeInt[i] + otherHugeInt.yugeInt[i] - 10);
				tempValues[i-1] = 1;
				cout << "tempValues[" << i << "] after the carry over = " << tempValues[i] << endl;
				cout << "tempValues[" << i-1 << "] after the carry over = " << tempValues[i-1] << endl;

			}
		}
		else { 
			tempValues[i] += yugeInt[i] + otherHugeInt.yugeInt[i]; 
		}
	}
	return HugeInteger(tempValues);
}

HugeInteger HugeInteger::subtract(HugeInteger otherHugeInt) {

	unsigned short int tempValues[sizeof(yugeInt) / sizeof(*yugeInt)] = { 0 };
	
	if (!isLarger(otherHugeInt)) {
		return otherHugeInt.subtract(*this); //rearrange variables for logic to work 
	}
	
	else if (signBit && otherHugeInt.signBit) { // if both numbers are positive
		bool owedFlag = 0; //determines if we need to carry over a -1 operation to the next pos
		//flag is necessary as the data type of yugeInt is unsigned 
		
		if (yugeInt[0] < otherHugeInt.yugeInt[0]) {
			cout << "HugeInteger overflow (SUBSTRACTION OPERATION)" << endl;
			abort();
		}
		
		for (unsigned int i = arraySize - 1; i > 0; i--) {
			if (yugeInt[i] < otherHugeInt.yugeInt[i]) {
				owedFlag == 1;
			}
			if (owedFlag == 1) {
				if (yugeInt[i] > 0) {
					owedFlag = 0;
					yugeInt[i] -= 1;
				}
				else {
					yugeInt[i] = 9;
				}
			}
			tempValues[i] = yugeInt[i] - otherHugeInt.yugeInt[i];
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
		return flipBit(flipBit(*this).add(otherHugeInt)); //adds both values and sticks a minus sign in front
	}
}

