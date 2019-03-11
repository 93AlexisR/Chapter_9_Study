#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "pch.h"




class Employee {
public:
	Employee(const std::string& firstName, const std::string& lastName);
	Employee(void);
	~Employee();

	Employee& setFirstName(const std::string& firstName);
	Employee& setLastName(const std::string& lastName);

	const std::string getFirstName(void) { return firstName; } 
	const std::string getLastName(void) { return lastName; }
	const std::string getName(void); //returns full name
	const static unsigned int getCount(void) { return count; }

	//static member function

private:
	std::string firstName;
	std::string lastName;
	static unsigned int count; //should be static

};



#endif EMPLOYEE_H
