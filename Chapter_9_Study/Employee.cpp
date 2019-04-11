#include "pch.h"
#include "Employee.h"
using namespace myEmployees;
//define and initialize static data member at global namespace scope
unsigned int Employee::count{ 0 };

Employee::Employee(const std::string& firstName,
	const std::string& lastName,
	const double hourlyRate,
	const double weeklyHours){
	this->setFirstName(firstName).
		setLastName(lastName).
		setHourlyRate(hourlyRate).
		setWeeklyHours(weeklyHours);
	count++;
}

Employee::Employee(void){
	count++; //since destructor will be called after the below call since the scope ends
	Employee::Employee("Jane", "Doe", 15, 40);
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

Employee& Employee::setHourlyRate(const double hourlyRate) {
	if (hourlyRate > 0) {
		this->hourlyRate = hourlyRate;
	}
	else {
		cout << "crash: Employee& Employee::setHourlyRate(const double hourlyRate)" << endl;
		abort();
	}
	return *this;
}

Employee& Employee::setWeeklyHours(const double weeklyHours) {
	if (hourlyRate > 0) {
		this->hourlyRate = hourlyRate;
	}
	else {
		cout << "crash: Employee& Employee::setWeeklyHours(const double weeklyHours)" << endl;
		abort();
	}
	return *this;
}

double Employee::getTotalPay(void) {
	this->totalPay = hourlyRate * weeklyHours * 2;
	return totalPay;
}

const std::string Employee::getName(void) {
	std::ostringstream output; //whats ostringstream
	output << getFirstName() << " " << getLastName();
	return output.str();
} //returns full name

////////////////////////////

myEmployees::CommissionEmployee::CommissionEmployee(const std::string& firstName,
	const std::string& lastName,
	const double hourlyRate,
	const double weeklyHours,
	const double sales,
	const double commissionPercentage) : Employee(firstName,
		lastName,
		hourlyRate,
		weeklyHours){
	setCommission(commissionPercentage).setSales(sales);
}

myEmployees::CommissionEmployee::CommissionEmployee(void) : Employee()
{
	setCommission(0.35).setSales(2500);
}

CommissionEmployee& myEmployees::CommissionEmployee::setSales(double sales){
	if (sales > 0) {
		this->sales = sales;
	}
	else {
		cout << "crash: CommissionEmployee& myEmployees::CommissionEmployee::setSales(double)" << endl;
		abort();
	}
	return *this;
}

CommissionEmployee& myEmployees::CommissionEmployee::setCommission(double commissionPercentage) {
	if (commissionPercentage < 1 && commissionPercentage > 0) {
		this->commissionPercentage = commissionPercentage;
	}
	else {
		cout << "crash: CommissionEmployee& myEmployees::CommissionEmployee::setCommission" << endl;
		abort();
	}
	return *this;
}

double myEmployees::CommissionEmployee::getTotalPay(void) {
	return (Employee::getTotalPay() + (commissionPercentage*sales));
}
