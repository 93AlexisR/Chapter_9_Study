#include "pch.h"
#include "Shape.hpp"
using namespace MyShapes;

MyShapes::Shape::Shape()
{
	canvasSize = new unsigned int(50);
	canvasPtr = new vector<vector<bool>>(*canvasSize, vector<bool>(*canvasSize));
	for (auto v : *canvasPtr) {
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
	canvasPtr->at(i).at(j).flip();
	return *this;
}

Shape& Shape::print(void) {
	for (auto v : *canvasPtr) {
		for (auto w : canvasPtr->at(0)) {
			if (w) {
				cout << "*";
			}
			else {
				cout << "_";
			}
		}
		cout << endl;
	}
	return *this;
}

