// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed
#include "pch.h"

const bool isAlpha(const std::string& testString) { //returns true if string contains spaces and alphabetical numbers only
	for (unsigned int i = 0; i < testString.length(); i++) {
		if (!isalpha(testString[i]) && (testString[i] != 32)) {
			std::cout << "Erroronous character: '" << testString[i] << "' on position " << 1+i << " for string " << testString;
			return false;
		}

	}
	return true;
}

const bool isAlphaStrict(const std::string& testString) { // returns true if string contains alphabetical chars only
	for (unsigned int i = 0; i < testString.length(); i++) {
		if (!isalpha(testString[i])) {
			std::cout << "Erroronous character: '" << testString[i] << "' on position " << 1+i << " for string " << testString;
			return false;
		}
	}
	return true;
}

const bool isAlphaNum(const std::string& testString) {// returns true if contains alphanum characters and spaces
	for (unsigned int i = 0; i < testString.length(); i++) {
		if (!isalnum(testString[i]) && (testString[i] != 32)) {
			std::cout << "Erroronous character: '" << testString[i] << "' on position " << 1+i << " for string " << testString;
			return false;
		}

	}
	return true;
}

const bool isAlphaNumStrict(const std::string& testString) { //returns true if contains Alphanum + spaces
	for (unsigned int i = 0; i < testString.length(); i++) {
		if (!isalnum(testString[i]) && (testString[i] != 32)) {
			std::cout << "Erroronous character: '" << testString[i] << "' on position " << 1+i << " for string " << testString;
			return false;
		}
	}
	return true;
}






// In general, ignore this file, but keep it around if you are using pre-compiled headers.
