#include "pch.h"
#include "Account.h"

Account::~Account() {
	std::cout << "\nDestructor running!";
}

Account& Account::withdraw(unsigned int withdrawal) {
	if (balance >= static_cast<int>(withdrawal) || !(typeid(unsigned int) == typeid(withdrawal))) { // check if withrawal is an unsigned int
		balance -= withdrawal;
	}
	else {
		std::cout << "Insufficient funds or invalid amount." << std::endl;
	}
	return *this;
}

int Account::getBalance() {
	return balance;
}

Account& Account::deposit(int moneys) {
	if (moneys > 0) {
		balance += moneys;
	}
	return *this;
}

Account& Account::setName(std::string accountName) { //ENSURE ALL ALPHA and spaces
	bool isValid = 1;
	for (unsigned int i = 0; i < accountName.length(); i++) {
		if (!isalpha(accountName[i]) && (accountName[i] != 32)) {
			std::cout << "Erroronous character: '" << accountName[i] << "' on position " << i << " for name " << accountName;
			getline(std::cin, accountName);
			isValid = 0;
			break;
		}
	}
	if (isValid = 1) {
		name = accountName;
	}
	return *this;
}

std::string Account::getName() const {
	return name;
}