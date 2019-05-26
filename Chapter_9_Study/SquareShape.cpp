#include "pch.h"
#include "SquareShape.hpp"
using namespace MyShapes;


MyShapes::SquareShape::SquareShape(unsigned int newSideSize, unsigned int newSquareOriginX, unsigned int newSquareOriginY)
{
	if (newSideSize > *canvasSize) {
		cout << "Error: MyShapes::SquareShape::SquareShape(unsigned int, unsigned int, unsigned int)";
		abort();
	}

	squareOriginX = new unsigned int(newSquareOriginX);
	squareOriginY = new unsigned int(newSquareOriginY);
	sideSize = new unsigned int(newSideSize);

	MyShapes::SquareShape::draw();
}

MyShapes::SquareShape::SquareShape()
	: SquareShape(5, 0, 0) //create square of side size 5 at 0,0
{
	//
}


MyShapes::SquareShape::~SquareShape() {
	delete (
		squareOriginX,
		squareOriginY,
		sideSize
		);
}

MyShapes::SquareShape& MyShapes::SquareShape::draw(void) {
	for (unsigned int i = *squareOriginX; i < *squareOriginX + *sideSize; i++) {
		flip(i, *squareOriginX).
			flip(i, *squareOriginX + *sideSize - 1).
			flip(*squareOriginY, i).
			flip(*squareOriginY + *sideSize - 1, i);

	}
	flip(*squareOriginX, *squareOriginY).
		flip(*squareOriginX + *sideSize - 1, *squareOriginY).
		flip(*squareOriginX, *squareOriginY + *sideSize - 1).
		flip(*squareOriginX + *sideSize - 1, *squareOriginY + *sideSize - 1);
	return *this;
}