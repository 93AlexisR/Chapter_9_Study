#pragma once
class SquareShape :
	public MyShapes::Shape
{
public:
	SquareShape(unsigned int sideSize, unsigned int lowerLeftPositionX, unsigned int lowerLeftPositionY);
	SquareShape(void);
	//virtual ~SquareShape(void);
	virtual SquareShape& draw(void);
private:
	unsigned int sideSize{ 0 };
	unsigned int lowerLeftPositionX{ 0 };
	unsigned int lowerLeftPositionY{ 0 };
};

