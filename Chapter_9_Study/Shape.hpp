#pragma once
class Shape
{
public:
	Shape(void);
	~Shape(void);
	virtual Shape& draw(void) = 0;
private:
	bool canvas[50][50];
};

