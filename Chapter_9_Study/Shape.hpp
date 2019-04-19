#pragma once
class Shape
{
public:
	Shape(void);
	~Shape(void);
	virtual Shape& draw(void) = 0;
	Shape& print(void);
private:
	vector<vector<bool>>* myVecPtr;;
	unsigned int canvasSize = 50;
};

