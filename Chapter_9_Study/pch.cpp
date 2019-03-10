// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "pch.h"






Time& Time::setTime(unsigned int hour, unsigned int minute, unsigned int second) {
	if ((hour >= 0 && hour < 24) && (minute >= 0 && minute < 60) && (second >= 0 && second < 60)) {
		this->setHour(hour).setMinute(minute).setSecond(second); // cascaded function calls
	}
	else {
		throw std::invalid_argument(
			"Hour, minute and/or second is out of range");
	}
	return *this;
}

Time& Time::setHour(unsigned int hour) {
	if (hour >= 0 && hour < 24) {
		this->hour = hour;
	}
	else {
		throw std::invalid_argument(
			"Hour must be 0-24");
	}
	return *this;
}

Time& Time::setMinute(unsigned int minute) {
	if (minute >= 0 && minute < 60) {
		this->minute = minute;
	}
	else {
		throw std::invalid_argument(
			"Minute must be 0-60");
	}
	return *this;
}

Time& Time::setSecond(unsigned int second) {
	if (second >= 0 && second < 60) {
		this->second = second;
	}
	else {
		throw std::invalid_argument(
			"Second must be 0-60");
	}
	return *this;
}

std::string Time::toUniversalString(void) const {
	std::ostringstream output; //whats ostringstream
	output << std::setfill('0') << std::setw(2) << getHour() << ":"
		<< std::setw(2) << getMinute() << ":" << std::setw(2) << getSecond();
	return output.str();
}

std::string Time::toStandardString(void) const {
	std::ostringstream output;
	output << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
		<< ":" << std::setfill('0') << std::setw(2) << getMinute() << ":" << std::setw(2)
		<< getSecond() << (getHour() < 12 ? " AM" : " PM");
	return output.str();
}






// In general, ignore this file, but keep it around if you are using pre-compiled headers.
