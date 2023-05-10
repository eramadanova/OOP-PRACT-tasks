#pragma once
#include "CarPart.h"
#include <iostream>

class Tires : public CarPart
{
public:
	Tires();
	Tires(const char* id, const char* manufacturer, const char* description, unsigned width, unsigned profile, unsigned diameter);

	void setWidth(unsigned width);
	void setProfile(unsigned profile);
	void setDiameter(unsigned diameter);

	unsigned getWidth() const;
	unsigned getProfile() const;
	unsigned getDiamater() const;


	friend std::ostream& operator<<(std::ostream& os, const Tires& other);

private:
	unsigned width;
	unsigned profile;
	unsigned diameter;
};

