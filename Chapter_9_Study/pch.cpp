// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "pch.h"

Account::~Account() {
	std::cout << "\nDestructor running!";
}

void Account::withdraw(unsigned int withdrawal) {
	if (balance >= static_cast<int>(withdrawal) || !(typeid(unsigned int) == typeid(withdrawal))) { // check if withrawal is an unsigned int
		balance -= withdrawal;
	}
	else {
		std::cout << "Insufficient funds or invalid amount." << std::endl;
	}
}

void Account::withdraw(std::string withdrawal) {
	int intMoney = 0;
	std::stringstream money(withdrawal);
	money >> intMoney;
	if (balance >= intMoney && intMoney > 0) {
		balance -= intMoney;
	}
	else {
		std::cout << "Insufficient funds or invalid amount." << std::endl;
	}
}

int Account::getBalance() {
	return balance;
}

void Account::deposit(int moneys) {
	if (moneys > 0) {
		balance += moneys;
	}
	//else, explode
}

void Account::deposit(std::string moneys) {
	int intMoney = 0;
	std::stringstream money(moneys);
	money >> intMoney;
	if (intMoney > 0) {
		balance += intMoney;
	}
}

void Account::setName(std::string accountName) { //ENSURE ALL ALPHA and spaces
	while (true) {
		bool nameFlag = 0;
		for (unsigned int i = 0; i < accountName.length(); i++) {
			if (!isalpha(accountName[i]) && (accountName[i] != 32)) {
				std::cout << "Erroronous character: '" << accountName[i] << "' on position " << i << " for name " << accountName << ".\nPlease try again: ";
				getline(std::cin, accountName);
				nameFlag = 1;
				break;
			}
		}
		if (nameFlag == 0) {
			//cout << "we breaking out!\n";
			break;
		}
	}
	name = accountName;
}

std::string Account::getName() const {
	return name;
}




//this pointer use example 9.14
Time& Time::setTime(unsigned int hour, unsigned int minute, unsigned int second) {
	if ((hour >= 0 && hour < 24) && (minute >= 0 && minute < 60) && (second >= 0 && second < 60)) {
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}
	else {
		throw std::invalid_argument(
			"Hour, minute and/or second is out of range");
	}
}

Time& Time::setHour(unsigned int hour) {
	if (hour >= 0 && hour < 24) {
		this->hour = hour;
	}
	else {
		throw std::invalid_argument(
			"Hour must be 0-24");
	}
	return *this;
}

Time& Time::setMinute(unsigned int minute) {
	if (minute >= 0 && minute < 24) {
		this->minute = minute;
	}
	else {
		throw std::invalid_argument(
			"Minute must be 0-60");
	}
	return *this;
}
Time& Time::setSecond(unsigned int second) {
	if (second >= 0 && second < 24) {
		this->second = second;
	}
	else {
		throw std::invalid_argument(
			"Second must be 0-60");
	}
}

//get functions
unsigned int Time::getHour(void) const {
	return this->hour;
}
unsigned int Time::getMinute(void) const {
	return this->minute;
}
unsigned int Time::getSecond(void) const {
	return this->second;
}







// In general, ignore this file, but keep it around if you are using pre-compiled headers.
