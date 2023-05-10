#pragma once

class FuelTank
{
public:
	FuelTank(double capacity);

	double getCapacity() const;
	double getFuel() const;

	void use(double amount);
	void fill(double amount);
private:
	double capacity;
	double fuel;

	void setCapacity(double capacity);
	void setFuel(double fuel);
};

