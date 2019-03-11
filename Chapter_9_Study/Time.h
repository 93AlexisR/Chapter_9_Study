#ifndef TIME_H
#define TIME_H
#include "pch.h"

class Time {
public:
	explicit Time(void) {
		Time(0, 0, 0);
	}

	Time(unsigned int hours, unsigned int minutes, unsigned int seconds) {
		setTime(0, 0, 0);
	}

	//the Time& return type enables cascading
	Time& setTime(unsigned int hours, unsigned int minutes, unsigned int seconds);
	Time& setHour(unsigned int);
	Time& setMinute(unsigned int);
	Time& setSecond(unsigned int);

	unsigned int getHour(void) const { return hour; }
	unsigned int getMinute(void) const { return minute; }
	unsigned int getSecond(void) const { return second; }
	std::string toUniversalString() const;
	std::string toStandardString() const;

private:
	unsigned int hour{ 0 };
	unsigned int minute{ 0 };
	unsigned int second{ 0 };
};

#endif TIME_H