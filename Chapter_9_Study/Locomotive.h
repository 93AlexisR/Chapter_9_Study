#pragma once
class Locomotive { //1-D locomotive base class
public:
	Locomotive(
		double length,
		double width,
		double height,
		double acceleration,
		double maxSpeed,
		double currentSpeed,
		double distanceTraveled
	);
	Locomotive(
		double length,
		double width,
		double height,
		double acceleration,
		double maxSpeed
	);
	Locomotive(double acceleration, double maxSpeed);
	Locomotive(void);
	virtual ~Locomotive();


	
	double getLength(void) { return length; }
	double getWidth(void) { return width; }
	double getHeight(void) { return height; }
	double getAcceleration(void) { return acceleration; }
	double getMaxSpeed(void) { return maxSpeed; }
	double getCurrentSpeed(void) { return currentSpeed; }
	double getDistance(void) { return distanceTraveled; }
	unsigned int getTick(void) { return timeTick; }

	
	virtual Locomotive& move(void);
	virtual Locomotive& reset(void);

protected:
	Locomotive& setLength(double);
	Locomotive& setWidth(double);
	Locomotive& setHeight(double);
	Locomotive& setAcceleration(double);
	Locomotive& setMaxSpeed(double);
	Locomotive& setCurrentSpeed(double);
	Locomotive& setDistance(double);
	Locomotive& tick(void) { timeTick++; return *this;}

private:
	static unsigned int timeTick; //timer replacement
	double length{ 0.0 };
	double width{ 0.0 };
	double height{ 0.0 };
	double acceleration{ 0.0 };
	double maxSpeed{ 0.0 };
	double currentSpeed{ 0.0 };
	double distanceTraveled{ 0.0 };
};
