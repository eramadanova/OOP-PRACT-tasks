#include "FuelTank.h"
#include "insufficient_fuel_error.h"
#include <stdexcept>


FuelTank::FuelTank(double capacity)
{
	setCapacity(capacity);
	setFuel(capacity);
}

double FuelTank::getCapacity() const
{
    return capacity;
}

double FuelTank::getFuel() const
{
    return fuel;
}

void FuelTank::use(double amount)
{
	if (amount < 0)
	{
		throw std::invalid_argument("Invalid amount of fuel.");
	}

	if (amount > fuel)
	{
		throw insufficient_fuel_error("Insufficient amount of fuel.");
	}

	fuel -= amount;
}

void FuelTank::fill(double amount)
{
	if (amount < 0)
	{
		throw std::invalid_argument("Invalid amount of fuel.");
	}

	if (fuel + amount > capacity)
	{
		fuel = capacity;
	}
	else
	{
		fuel += amount;
	}
}

void FuelTank::setCapacity(double capacity)
{
	if (capacity < 0)
	{
		throw std::invalid_argument("Invalid capacity of fuel tank.");
	}

	this->capacity = capacity;
}

void FuelTank::setFuel(double fuel)
{
	this->fuel = fuel;
}
