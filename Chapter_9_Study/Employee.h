#pragma once
#include "pch.h"

class Account {
public:

	explicit Account(std::string accountName) // if given a string then it will create account with name passed by argument
		: name{ accountName } { 	// explicit because it only takes 1 parameter only
		setName(accountName);
	}
	~Account();

	Account(std::string accountName, int initBalance)
		: name(accountName) {
		balance = initBalance;
	}

	void withdraw(unsigned int);
	void withdraw(std::string);

	void setName(std::string);
	std::string getName() const;

	void deposit(int);
	void deposit(std::string);

	int getBalance(void);

private:
	std::string name;
	int balance{ 0 };
};
