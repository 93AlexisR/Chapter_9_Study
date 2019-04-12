#include "pch.h"
#include "Locomotive.h"
unsigned int MyLocomotives::Locomotive::timeTick = 0;

MyLocomotives::Locomotive::Locomotive(
	double length,
	double width,
	double height,
	double acceleration,
	double maxSpeed,
	double currentSpeed,
	double distanceTraveled){
	setLength(length).
		setWidth(width).
		setHeight(height).
		setAcceleration(acceleration).
		setMaxSpeed(maxSpeed).
		setCurrentSpeed(currentSpeed).
	setDistance(distanceTraveled);
}

MyLocomotives::Locomotive::Locomotive(
	double length,
	double width,
	double height,
	double acceleration,
	double maxSpeed)	
	: Locomotive(length,width,height,acceleration,maxSpeed,0.0,0.0)
	{
	//
}

MyLocomotives::Locomotive::Locomotive(double acceleration,double maxSpeed) 
	: Locomotive(1.0, 1.0, 1.0, acceleration, maxSpeed)
	{
	//
}

MyLocomotives::Locomotive::Locomotive(void) : 
	Locomotive(1.0,1.0,1.0,1.0,1.0,1.0,1.0){
	//
}



MyLocomotives::Locomotive::~Locomotive()
{
}

MyLocomotives::Locomotive& MyLocomotives::Locomotive::setLength(double length)
{
	if (length > 0) {
		this->length = length;
	}
	else {
		cout << "crash: Locomotive::setLength(double)" << endl;
		abort();
	}
	return *this;
}

MyLocomotives::Locomotive& MyLocomotives::Locomotive::setWidth(double width)
{
	if (width > 0) {
		this->width = width;
	}
	else {
		cout << "crash: Locomotive::setWidth(double)" << endl;
		abort();
	}
	return *this;
}

MyLocomotives::Locomotive& MyLocomotives::Locomotive::setHeight(double height)
{
	if (height > 0) {
		this->height = height;
	}
	else {
		cout << "crash: Locomotive::setHeight" << endl;
		abort();
	}
	return *this;
}

MyLocomotives::Locomotive& MyLocomotives::Locomotive::setAcceleration(double acceleration)
{
	if (acceleration >= 0) {
		this->acceleration = acceleration;
	}
	else {
		cout << "crash: Locomotive::setAcceleration" << endl;
	}
	return *this;
}

MyLocomotives::Locomotive& MyLocomotives::Locomotive::setMaxSpeed(double maxSpeed)
{
	if (maxSpeed >= 0) {
		this->maxSpeed = maxSpeed;
	}
	else {
		cout << "crash: Locomotive::setMaxSpeed" << endl;
	}
	return *this;
}

MyLocomotives::Locomotive& MyLocomotives::Locomotive::setCurrentSpeed(double currentSpeed)
{
	if (currentSpeed >= 0) {
		this->currentSpeed = currentSpeed;
	}
	else {
		cout << "crash: Locomotive::setCurrentSpeed" << endl;
	}
	return *this;
}

MyLocomotives::Locomotive& MyLocomotives::Locomotive::setDistance(double distanceTraveled)
{
	if (distanceTraveled >= 0) {
		this->distanceTraveled = distanceTraveled;
	}
	else {
		cout << "crash: Locomotive::setDistance" << endl;
		abort();
	}
	return *this;
}

MyLocomotives::Locomotive& MyLocomotives::Locomotive::move(void)
{
	tick();
	if (getCurrentSpeed() + getAcceleration() >= getMaxSpeed()) {
		setCurrentSpeed(getMaxSpeed());
	}
	else {
		setCurrentSpeed(getCurrentSpeed() + getTick()*getAcceleration());
	}
	setDistance(getDistance() + getCurrentSpeed());
	return *this;
}

MyLocomotives::Locomotive& MyLocomotives::Locomotive::reset(void)
{
	timeTick = 0; 
	setAcceleration(0).setCurrentSpeed(0).setDistance(0); 
	return *this;
}

