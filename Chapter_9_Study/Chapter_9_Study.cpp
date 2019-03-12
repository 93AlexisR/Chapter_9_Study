// chapter_9_study.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "Employee.h"
#include "Account.h"
#include "Time.h"
using namespace std;


class mySphere {
	static unsigned int sphereCount;
	double radius{ 1.0 };

public:
	mySphere(void) { sphereCount++; }
	~mySphere(void) { sphereCount--; }
	static unsigned int getCount(void) { return sphereCount; }
};
unsigned int mySphere::sphereCount{ 0 };
unsigned int Employee::count{ 0 };



int main()
{

	mySphere mySpheres[10];
	cout << mySphere::getCount() << endl;

	Employee myEmployees[10];
	cout << Employee::getCount() << endl;


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
