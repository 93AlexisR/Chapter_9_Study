#pragma once
#include <iostream>
#include <string>
#include <array>		
#include <sstream> 
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
#include <math.h>
#include <stdexcept>
#include <chrono>
#include "pch.h"
#include "RandEngine.h"
constexpr auto PI_VALUE = 3.141592653589;




const bool isAlpha(const std::string&); //returns true if string contains spaces and alphabetical numbers only
const bool isAlphaStrict(const std::string&); // returns true if string contains alphabetical chars only
const bool isAlphaNum(const std::string&); // returns true if contains alphanum characters and spaces
const bool isAlphaNumStrict(const std::string&); //returns true if contains Alphanum + spaces

const int charToInt(const char& convertMe);
std::string vecToString(const std::vector<char> fakeString);

const char intToChar(const unsigned short int myChar);
const char intToChar(const short int myChar) { return intToChar(static_cast<unsigned short int>(myChar)); }
const char intToChar(const int myChar) { return intToChar(static_cast<unsigned short int>(myChar)); }
const char intToChar(const long int myChar) { return intToChar(static_cast<unsigned short int>(myChar)); }
const char intToChar(const unsigned long int myChar) { return intToChar(static_cast<unsigned short int>(myChar)); }

const unsigned int strToInt (const std::string& myString);