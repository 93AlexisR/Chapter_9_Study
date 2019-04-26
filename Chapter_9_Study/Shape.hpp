#pragma once
class Shape
{
public:
	Shape(void);
	~Shape(void);
	virtual Shape& draw(void) = 0;
	Shape& print(void);
	Shape& flip(unsigned int, unsigned int);
protected:
	vector<vector<bool>>* canvasPtr;
	unsigned int* canvasSize;
private:
	//
};

