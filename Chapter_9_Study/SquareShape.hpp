#pragma once
class SquareShape :
	public MyShapes::Shape
{
public:
	SquareShape(double sideSize, double lowerLeftPosition);
	SquareShape(void);
	virtual ~SquareShape(void);
	virtual SquareShape& draw(void);
private:
	unsigned int sideSize{ 0 };
	unsigned int lowerLeftPosition{ 0 };
};

