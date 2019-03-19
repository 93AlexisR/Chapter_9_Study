#include "RandEngine.h"
#include "PCH.h"

unsigned int RandEngine::theSeed = static_cast<unsigned int>(time(NULL)); //adds some chaos by making the variable static

RandEngine::RandEngine(void) {
	unsigned int i = 4000000000;
	unsigned int b;
	while (true) {//test to find largest unsigned int-ish
		b = i;
		i += 1111;
		if (i < b) {
			unsignedLimit = b / 2;
			break;
		}
	}
}

RandEngine::RandEngine(unsigned int customSeed){
	theSeed = customSeed;
	RandEngine();
}


unsigned int RandEngine::trueRand(void) {
	while (theSeed > 10000) {
		theSeed /= 9;
	}
	theSeed *= 11111 % unsignedLimit;
	return theSeed;
}

bool RandEngine::fiftyFifty(void) {
	return static_cast<bool>(trueRand() % 2);
}

void RandEngine::trueTest(void) {
	RandEngine myEngine;
	unsigned int trueCounter{ 0 };
	unsigned int falseCounter{ 0 };
	for (unsigned int i = 0; i < 546; i++) {
		if (myEngine.fiftyFifty()) {
			trueCounter++;
		}
		else {
			falseCounter++;
		}
	}

	long double ratio = static_cast<long double>(trueCounter) / static_cast<long double>(falseCounter);
	std::cout << "falseCounter: " << falseCounter << std::endl
		<< "trueCounter: " << trueCounter << std::endl
		<< "ratio false to true is: " << ratio << std::endl;
}

unsigned int RandEngine::randRange(unsigned int lowerBound, unsigned int upperBound) {
	unsigned int range = upperBound - lowerBound;
	return lowerBound + trueRand() % ++range;
}

void RandEngine::rangeTest(void) {
	RandEngine tempEngine;
	unsigned int frequencyCount[5] = { 0,0,0,0,0 };
	for (unsigned int i = 0; i < 1000000; i++) {
		switch (tempEngine.myRand(5)) {
		case 1:
			frequencyCount[0]++;
			break;
		case 2:
			frequencyCount[1]++;
			break;
		case 3:
			frequencyCount[2]++;
			break;
		case 4:
			frequencyCount[3]++;
			break;
		case 5:
			frequencyCount[4]++;
			break;
		default:
			break;
		}
	}
	for (unsigned int v = 0; v < 5; v++) {
		std::cout << "Frequency of " << v + 1 << ": " << frequencyCount[v] << " ("
			<< 100.0 * static_cast<double>(frequencyCount[v]) /
			static_cast<double>((frequencyCount[0] + frequencyCount[1]
				+ frequencyCount[2] + frequencyCount[3]
				+ frequencyCount[4])) << "%)" << std::endl;
	}
}
