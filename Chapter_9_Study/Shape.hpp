#pragma once
class Shape
{
public:
	Shape(void);
	~Shape(void);
	virtual Shape& draw(void) = 0;
	virtual Shape& print(void);
	Shape& flipX(unsigned int);
	Shape& flipY(unsigned int);
private:
	vector<bool>* canvasPtrX;
	vector<bool>* canvasPtrY;
	unsigned int canvasSize = 50;
};

