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
	: SquareShape(5, 0, 0)
{
	MyShapes::SquareShape::draw();
}


MyShapes::SquareShape::~SquareShape() {
	delete (
		squareOriginX,
		squareOriginY,
		sideSize
		);
}

SquareShape& MyShapes::SquareShape::draw(void) {
	bool topComplete{ false };

	for (unsigned int i = 0; i < *canvasSize; i++) {

		if (i == *squareOriginY) {
			for (unsigned int j = *squareOriginX; j < *sideSize; j++) {
				flip(i, j);
			}
			topComplete = true;
		}
		else if (topComplete) {
			flip(i, 0);
			flip(i, *sideSize);
		}
		else if (i == (*squareOriginY + *sideSize)) {
			for (unsigned int j = *squareOriginX; j < (*sideSize + *squareOriginX); j++) {
				flip(i, j);
			}
			break;
		}
	}
	return *this;
}