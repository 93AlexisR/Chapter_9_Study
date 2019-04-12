#include "pch.h"
#include "LocomotiveWithDrag.hpp"
using namespace MyLocomotives;

LocomotiveWithDrag::LocomotiveWithDrag(double length, double width, double height, double acceleration, double maxSpeed, double dragCoefficient, double mediumDensity, double currentSpeed, double distanceTraveled)
	: Locomotive(length, width, height, acceleration, maxSpeed, currentSpeed, distanceTraveled)
{
	setMediumDensity(mediumDensity).
		setDragCoefficient(dragCoefficient);
}

LocomotiveWithDrag::LocomotiveWithDrag(double length, double width, double height, double acceleration, double maxSpeed, double dragCoefficient, double mediumDensity)
	: LocomotiveWithDrag(length, width, height, acceleration, maxSpeed, dragCoefficient, mediumDensity, 0.0, 0.0)
{
	//
}

LocomotiveWithDrag::LocomotiveWithDrag(double acceleration, double maxSpeed, double dragCoefficient, double mediumDensity)
	: LocomotiveWithDrag(1.0, 1.0, 1.0, acceleration, maxSpeed, dragCoefficient, mediumDensity)
{
	//
}

MyLocomotives::LocomotiveWithDrag::LocomotiveWithDrag()
	: LocomotiveWithDrag(10.0, 500.0, 1.0, 1.1455)
{
	//
}


MyLocomotives::LocomotiveWithDrag::~LocomotiveWithDrag()
{
}


LocomotiveWithDrag& LocomotiveWithDrag::setDragCoefficient(double dragCoefficient) {
	if (dragCoefficient >= 0 && dragCoefficient <= 1) {
		this->dragCoefficient = dragCoefficient;
	}
	else {
		cout << "crash: LocomotiveWithDrag::setDragCoefficient" << endl;
		abort();
	}
	return *this;
}
LocomotiveWithDrag& LocomotiveWithDrag::setMediumDensity(double) {
	if (mediumDensity >= 0) {
		this->mediumDensity = mediumDensity;
	}
	else {
		cout << "crash: LocomotiveWithDrag::setDragCoefficient" << endl;
		abort();
	}
	return *this;
}

double LocomotiveWithDrag::getDragDeccel(void)
{
	return getDragCoefficient()*
		getMediumDensity()*
		getCurrentSpeed()*
		getCurrentSpeed()*
		getCrossSectionArea()*
		(-0.5);
}

LocomotiveWithDrag& LocomotiveWithDrag::move(void) {
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

