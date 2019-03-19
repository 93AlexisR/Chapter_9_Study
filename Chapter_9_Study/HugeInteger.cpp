#include "pch.h"
#include "HugeInteger.h"


HugeInteger::HugeInteger(void) {
}

HugeInteger::HugeInteger(string& charVal) {
	stringSize = static_cast<unsigned int>(charVal.size());
	for (unsigned int i = 0; i < arraySize; i++) {
		if (i < (arraySize - stringSize) ) { 
			yugeInt[i] = 0;
		}
		else{
			yugeInt[i] = charToInt(charVal[i - (arraySize - stringSize)]);
		}
	}
}

HugeInteger::HugeInteger(int newArray[]) {
	for (unsigned int i = 0; i < arraySize; i++) {
		this->yugeInt[i] = newArray[i];
		//cout << "intConstructor running... i = " << i << " and yugeInt[i] = " << yugeInt[i] << endl;
	}
}

HugeInteger::~HugeInteger(){
}

HugeInteger& HugeInteger::printVal(void) {
	for (unsigned int i = 0; i < arraySize; i++) {
		if (yugeInt[i] != 0) {
			for (unsigned int j = i; j < arraySize; j++) {
				cout << yugeInt[j];
			}
			break;
			return *this;
		}
	}
	return *this;
}

unsigned short int HugeInteger::getPosVal(unsigned int i) {
	if (i < arraySize) {
		return yugeInt[i];
	}
	else {
		cout << "getPosVal(unsigned int) failed because position is invalid (> 39)" << endl;
		abort();
		return 0;
	}
}


HugeInteger HugeInteger::add(HugeInteger otherHugeInt) {
	int tempValues[sizeof(yugeInt) / sizeof(*yugeInt)] = { 0 };
	for (int i = arraySize - 1; i >= 0; i--) { //what the fuck why does unsigned int i not work
		//cout << "i is: " << i << endl;
		//cout << "(yugeInt[i] + otherHugeInt.yugeInt[i]) is equal to: " << static_cast<unsigned int>(yugeInt[i] + otherHugeInt.yugeInt[i]) << endl;
		if ((yugeInt[i] + otherHugeInt.yugeInt[i]) > 9){
			if (i == 0) {
				cout << "HugeInteger overflow (more than 40 decimal places)" << endl; //don't comment me out
				abort();
			}
			else{
				//cout << "tempValues[" << i << "] before the carry over = " << tempValues[i] << endl;
				//cout << "yugeInt[i] + tempValues[i] + otherHugeInt.yugeInt[i] - 10 is eq. to " << 
				//	tempValues[i] << " + " << otherHugeInt.yugeInt[i] << " + " << yugeInt[i] << " - 10" << endl;
				tempValues[i] += (yugeInt[i] + otherHugeInt.yugeInt[i] - 10);
				tempValues[i-1] = 1;
				//cout << "tempValues[" << i << "] after the carry over = " << tempValues[i] << endl;
				//cout << "tempValues[" << i-1 << "] after the carry over = " << tempValues[i-1] << endl;

			}
		}
		else { 
			tempValues[i] += yugeInt[i] + otherHugeInt.yugeInt[i]; 
		}
	}
	return HugeInteger(tempValues);
}


bool HugeInteger::isLarger(HugeInteger otherValue) {
	for (unsigned int i = 0; i < arraySize; i++) {
		cout << "lvalue[" << i << "] = " << yugeInt[i] << " >? rightValue[" << i << "] =  " << otherValue.yugeInt[i] << endl;
		if (yugeInt[i] > otherValue.yugeInt[i]) {
			cout << "break at i = " << i << endl;
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
	int tempValues[sizeof(yugeInt) / sizeof(*yugeInt)] = { 0 };
	for (unsigned int i = 0; i < arraySize; i++) { 
		//cout << "i is: " << i << endl;
		//cout << "(yugeInt[i] + otherHugeInt.yugeInt[i]) is equal to: " << static_cast<unsigned int>(yugeInt[i] + otherHugeInt.yugeInt[i]) << endl;
		if ((yugeInt[i] < otherHugeInt.yugeInt[i])) {
			if (i == 0) {
				cout << "HugeInteger overflow (more than 40 decimal places)" << endl;
				abort();
			}
			else {
				//cout << "tempValues[" << i << "] before the carry over = " << tempValues[i] << endl;
			//	cout << "yugeInt[i] + tempValues[i] + otherHugeInt.yugeInt[i] - 10 is eq. to " <<
			//		tempValues[i] << " + " << otherHugeInt.yugeInt[i] << " + " << yugeInt[i] << " - 10" << endl;
				tempValues[i] += (yugeInt[i] + otherHugeInt.yugeInt[i] - 10);
				tempValues[i - 1] = 1;
			//	cout << "tempValues[" << i << "] after the carry over = " << tempValues[i] << endl;
			//	cout << "tempValues[" << i - 1 << "] after the carry over = " << tempValues[i - 1] << endl;

			}
		}
		else {
			tempValues[i] += yugeInt[i] + otherHugeInt.yugeInt[i];
		}
	}
	return HugeInteger(tempValues);
}
