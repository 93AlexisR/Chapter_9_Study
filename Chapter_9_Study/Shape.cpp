#include "pch.h"
#include "Shape.hpp"
using namespace MyShapes;

MyShapes::Shape::Shape()
{
	canvasSize = new unsigned int(50);
	canvasPtr = new vector<vector<bool>>(*canvasSize, vector<bool>(*canvasSize));
	for (auto v : *canvasPtr) { //iterating through vector of vector<bool>s
		for (auto w : canvasPtr->at(0)) {
			w = false;
		}
	}
}


MyShapes::Shape::~Shape()
{
	delete (
		canvasSize,
		canvasPtr
		);
}

Shape& MyShapes::Shape::flip(unsigned int i, unsigned int j) {
	canvasPtr->at(j).at(i).flip();
	return *this;
}

Shape& Shape::print(void) {
	unsigned int i = 0;
	for (auto v : *canvasPtr) {
		for (unsigned int i = 0; i < v.size(); i++) {
			if (v.at(i)) {
				cout << "*";
			}
			else {
				cout << "_";
			}
		}
		cout << endl;
	}
	cout << endl;

	return *this;
}

