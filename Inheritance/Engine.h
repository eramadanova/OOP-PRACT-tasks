#pragma once
#include "CarPart.h"
#include <iostream>

class Engine : public CarPart
{
public:
	Engine();
	Engine(const char* id, const char* manufacturer, const char* description, unsigned horsePower);

	void setHorsePower(unsigned horsePower);

	unsigned getHorsePower() const;

	friend std::ostream& operator<<(std::ostream& os, const Engine& other);

private:
	unsigned horsePower;
};

