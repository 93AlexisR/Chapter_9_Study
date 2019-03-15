#include "pch.h"
#include "HugeInteger.h"


HugeInteger::HugeInteger(void) {
}

HugeInteger::HugeInteger(string& charVal) {
	stringSize = static_cast<unsigned int>(charVal.size());
	for (unsigned int i = 0; i < arraySize; i++) {
		if (i < arraySize - stringSize) {
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
		cout << "intConstructor running... i = " << i << " and yugeInt[i] = " << yugeInt[i] << endl;
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
	for (unsigned int i = startPrint; i < arraySize; i++){
			cout << yugeInt[i];
	}
	return *this;
}

unsigned short int HugeInteger::getPosVal(unsigned int i) {
	if (i < arraySize) {
		return yugeInt[i];
	}
	else {
		cout << "getPosVal(unsigned int) failed" << endl;
		abort();
		return 0;
	}
}


HugeInteger HugeInteger::add(HugeInteger otherHugeInt) {
	int tempValues[sizeof(yugeInt) / sizeof(*yugeInt)] = { 0 };
	for (int i = arraySize - 1; i >= 0; i--) { //what the fuck why does unsigned int i not work
		cout << "i is: " << i << endl;
		//cout << "(yugeInt[i] + otherHugeInt.yugeInt[i]) is equal to: " << static_cast<unsigned int>(yugeInt[i] + otherHugeInt.yugeInt[i]) << endl;
		if ((yugeInt[i] + otherHugeInt.yugeInt[i]) > 9){
			if (i = 0) {
				cout << "HugeInteger overflow" << endl;
				abort();
			}
			else{
				tempValues[i] += (otherHugeInt.yugeInt[i] - 10);
				tempValues[i-1] = 1;
				cout << "carrying over... yuge[i-1] is " << tempValues[i-1] << 
					"and [i] is " << tempValues[i] << endl;

			}
		}
		else { 
			tempValues[i] = yugeInt[i] + otherHugeInt.yugeInt[i]; 
		}
	}
	return HugeInteger(tempValues);
}