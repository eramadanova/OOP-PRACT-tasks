#pragma once
#include "CarPart.h"
#include <iostream>

class Accumulator : public CarPart
{
public:
	Accumulator();
	Accumulator(const char* id, const char* manufacturer, const char* description, unsigned ampHours, const char* batteryId);

	void setAmpHours(unsigned ampHours);
	void setBatteryId(const char* batteryId);

	unsigned getAmpHours() const;
	const char* getbatteryId() const;

	friend std::ostream& operator<<(std::ostream& os, const Accumulator& other);

private:
	unsigned ampHours;
	char batteryId[16];
};

