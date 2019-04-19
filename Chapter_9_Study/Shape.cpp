#include "pch.h"
#include "Shape.hpp"
using namespace MyShapes;

MyShapes::Shape::Shape()
{
	myVecPtr = new vector<vector<bool>>(50, vector<bool>(50));
}


MyShapes::Shape::~Shape()
{
	delete myVecPtr;
}

Shape & Shape::print(void){
	for (int i = myVecPtr->size()-1; i > 0; i--) {

	}
	return *this;
}

