#include "pch.h"
#include "SquareShape.hpp"
using namespace MyShapes;


MyShapes::SquareShape::SquareShape(unsigned int sideSize, unsigned int lowerLeftPositionX, unsigned int lowerLeftPositionY)
{
	this->lowerLeftPositionX = lowerLeftPositionX;
	this->lowerLeftPositionY = lowerLeftPositionY;
	draw();
}

MyShapes::SquareShape::SquareShape()
	: SquareShape(5, 0, 0)
{
	draw();
}


//MyShapes::SquareShape::~SquareShape() {
	//MyShapes::Shape::~Shape();
//}

SquareShape& MyShapes::SquareShape::draw(void) {
	for (unsigned int i = 0; i < sideSize; i++) {

	}
	return *this;
}