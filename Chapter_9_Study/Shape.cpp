#include "pch.h"
#include "Shape.hpp"
using namespace MyShapes;

MyShapes::Shape::Shape()
{
	canvasPtrX = new vector<bool>(canvasSize);
	canvasPtrY = new vector<bool>(canvasSize);
}


MyShapes::Shape::~Shape()
{
	delete canvasPtrX;
	delete canvasPtrY;
}

Shape& MyShapes::Shape::flipX(unsigned int xPosition) {
	if (xPosition > canvasSize - 1) {
		cout << "flipX(unsigned int) crash" << endl;
		abort();
	}
	else {
		canvasPtrX->at(xPosition).flip();
	}
	return *this;
}
Shape& MyShapes::Shape::flipY(unsigned int yPosition) {
	if (yPosition > canvasSize - 1) {
		cout << "flipY(unsigned int) crash" << endl;
		abort();
	}
	else {
		canvasPtrY->at(yPosition).flip();
	}
	return *this;
}