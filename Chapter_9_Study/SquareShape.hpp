#pragma once
class SquareShape :
	public MyShapes::Shape
{
public:
	SquareShape(unsigned int sideSize, unsigned int lowerLeftPositionX, unsigned int lowerLeftPositionY);
	SquareShape(void);
	virtual ~SquareShape(void);
	virtual SquareShape& draw(void);
private:
	unsigned int* squareOriginX{ nullptr };
	unsigned int* squareOriginY{ nullptr };
	unsigned int* sideSize{ nullptr };


};

