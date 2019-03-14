#pragma once
//Exercice 9.12 or something
using namespace std;
class HugeInteger
{
private:
	int yugeInt[40] = { 0 };
	bool signBit{ 1 };
public:
	HugeInteger(void);
	HugeInteger(string& myVal);
	~HugeInteger();

	HugeInteger add(HugeInteger otherHugeInt);
};

