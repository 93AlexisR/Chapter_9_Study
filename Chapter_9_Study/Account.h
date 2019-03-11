#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "pch.h"
#pragma once



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

	Account& deposit(int);
	Account& setName(std::string);
	Account& withdraw(unsigned int);
	


	std::string getName() const;

	

	int getBalance(void);

private:
	std::string name;
	int balance{ 0 };
};

#endif ACCOUNT_H