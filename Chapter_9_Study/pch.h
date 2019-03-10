// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H
constexpr auto PI_VALUE = 3.141592653589;
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

// TODO: add headers that you want to pre-compile here'

/*
conventional software engineering wiston says that to use an object of a calss, the client code needs
to know only
	- What member functions to call
	- What arguments to provide to each member function
	- What return type to expect from each member function

*/

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


class Time {
public:
	Time(void)
		:hour(0), minute(0), second(0) {
		//empty body
	}

	Time(unsigned int hours, unsigned int minutes, unsigned int seconds)
		: hour(hours), minute(minutes), second(seconds) {
		//do notha
	}

	~Time() {
		hour = 0;
		minute = 0;
		hour = 0;
	}

	Time& setTime(unsigned int hours, unsigned int minutes, unsigned int seconds);
	Time& setHour(unsigned int);
	Time& setMinute(unsigned int);
	Time& setSecond(unsigned int);

	unsigned int getHour(void) const;
	unsigned int getMinute(void) const;
	unsigned int getSecond(void) const;
	std::string toUniversalString() const;
	std::string toStandardString() const;

private:
	unsigned int hour{ 0 };
	unsigned int minute{ 0 };
	unsigned int second{ 0 };
};


#endif //PCH_H
