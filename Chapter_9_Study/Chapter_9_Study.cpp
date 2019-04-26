// chapter_9_study.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"



int main() {
	/*	myEmployees::CommissionEmployee myEmployee(
		"John",
		"Smith",
		5.0,
		40.0,
		2500.0,
		0.125
	);
	myEmployees::Employee* baseClassPtr{ &myEmployee };
	cout << baseClassPtr->getTotalPay() << endl; //base method
	cout << myEmployee.getTotalPay() << endl; //new method
	//the above is the bread & butter of polymorphism 


	MyLocomotives::Locomotive myLoco(
		1.0,
		1.0,
		1.0,
		5.0,
		360.0
	);
	MyLocomotives::LocomotiveWithDrag myLocoWithDrag(5.0, 360.0, 1.0, 1.1455);

	vector<vector<bool>>* newBoolPtr;
	newBoolPtr = new vector<vector<bool>>(50, vector<bool>(50));
	for (unsigned int i = 0; i < 50; i++) {
		for (unsigned int j = 0; j < 50; j++) {
			newBoolPtr->at(i).at(j).flip();
			if (newBoolPtr->at(i).at(j)) {
				cout << "[" << i << "],[" << j << "]" << endl;
			}
		}
	}
	unsigned int i = 0;
	for (auto v : *newBoolPtr) {
		for (auto w : newBoolPtr->at(0)) {
			if (w) {
				cout << ++i << endl;
			}
		}
	}
	*/


	MyShapes::SquareShape mySquare;
	mySquare.draw();
	mySquare.print();


	//https://stackoverflow.com/questions/14959393/pointer-to-a-multidimensional-vector
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
