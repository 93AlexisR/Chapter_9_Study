#include "pch.h"
#include "Employee.h"

//define and initialize static data member at global namespace scope
//unsigned int Employee::count{ 0 };


Employee::Employee(const std::string& firstName1, const std::string& lastName) {
	this->setFirstName(firstName1).setLastName(lastName);
	count++;
	//std::cout << "The name set is: " << getName() << std::endl;
	
}

Employee::Employee(void){
	std::string myString = "Jonathan";
	std::string hisString = "Smither";
	Employee::Employee(myString, hisString); 
}

Employee::~Employee() {
	count--;
}

Employee& Employee::setFirstName(const std::string& firstName) {
	if (isAlphaStrict(firstName)) {
		this->firstName = firstName;
	}
	return *this;
}
Employee& Employee::setLastName(const std::string& lastName) {
	if (isAlphaStrict(lastName)) {
		this->lastName = lastName;
	}
	return *this;
}

const std::string Employee::getName(void) {
	std::ostringstream output; //whats ostringstream
	output << getFirstName() << " " << getLastName();
	return output.str();
} //returns full name

//static member function
//static unsigned int Employee::getCount(void);

