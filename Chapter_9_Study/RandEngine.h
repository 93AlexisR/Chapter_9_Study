#pragma once
#include <iostream>
class RandEngine {
private:
	unsigned int theSeed;
	unsigned int unsignedLimit;

public:
	RandEngine(void);
	RandEngine(unsigned int customSeed);
	static void trueTest(void); //function to test ratios of true/false with current settings
	static void rangeTest(void); //test frequencies of random numbers from 1 to 5

	unsigned int trueRand(void); //returns random value from 0 to unsignedLimit
	unsigned int randRange(unsigned int lowerBound, unsigned int upperBound); //return rand value from lowerBound to upperBound (inclusive)
	unsigned int myRand(unsigned int upperBound) { return randRange(1, upperBound); } //return rand value from 1 to upperBound (inclusive)
	bool fiftyFifty(void);

};

void trueTest(void);

