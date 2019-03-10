#include "Employee.h"

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