#pragma once
#include "Locomotive.h"
//formula used for drag: https://www.grc.nasa.gov/www/k-12/airplane/drageq.html
//
class LocomotiveWithDrag :
	public MyLocomotives::Locomotive
{
public:
	LocomotiveWithDrag(
		double length,
		double width,
		double height,
		double acceleration,
		double maxSpeed,
		double dragCoefficient,
		double mediumDensity,
		double currentSpeed,
		double distanceTraveled
	);
	LocomotiveWithDrag(
		double length,
		double width,
		double height,
		double acceleration,
		double maxSpeed,
		double dragCoefficient,
		double mediumDensity
	);
	LocomotiveWithDrag(double acceleration, double maxSpeed, double dragCoefficient, double mediumDensity);
	LocomotiveWithDrag(void);
	virtual ~LocomotiveWithDrag();


	virtual LocomotiveWithDrag& move(void);


	LocomotiveWithDrag& setDragCoefficient(double);
	LocomotiveWithDrag& setMediumDensity(double);

	double getDragCoefficient(void) { return dragCoefficient; }
	double getMediumDensity(void) { return mediumDensity; }
	double getCrossSectionArea(void) { return crossSectionArea; }
	double getDragDeccel(void);
private:
	double dragCoefficient{ 0 };
	double mediumDensity{ 0 };
	double crossSectionArea{ getWidth()*getHeight() };
};

