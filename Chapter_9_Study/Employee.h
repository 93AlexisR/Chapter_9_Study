#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "pch.h"
namespace myEmployees {
	class Employee {
	public:
		Employee(const std::string& firstName, 
			const std::string& lastName,
			const double hourlyRate,
			const double weeklyHours);
		Employee(void);
		~Employee();

		Employee& setFirstName(const std::string& firstName);
		Employee& setLastName(const std::string& lastName);
		Employee& setHourlyRate(const double);
		Employee& setWeeklyHours(const double);
		double getTotalPay(void);


		const std::string getFirstName(void) { return firstName; }
		const std::string getLastName(void) { return lastName; }
		const std::string getName(void); //returns full name
		const static unsigned int getCount(void) { return count; }

		static unsigned int count; //total employee count

		//static member function

	private:
		std::string firstName;
		std::string lastName;
		double hourlyRate{ 0 };
		double weeklyHours{ 0 };
		double totalPay{ 0 };
	};

	class CommissionEmployee : public Employee {
	public:
		CommissionEmployee(const std::string& firstName,
			const std::string& lastName,
			const double hourlyRate,
			const double weeklyHours,
			const double sales,
			const double commissionPercentage);
		CommissionEmployee(void);

		CommissionEmployee& setSales(double);
		CommissionEmployee& setCommission(double);

		double getTotalPay(void);
	private:
		double sales{ 0 };
		double commissionPercentage{ 0 };
	};

}
#endif EMPLOYEE_H
