#include "Car.h"
#include <cmath>


Car::Car(double capacity, const Engine& engine, const Tires& tires, const Accumulator& accumulator, double km, double weight)
	: fuelTank(capacity), engine(engine), tires(tires), accumulator(accumulator)
{
	setKm(km);
	setWeight(weight);
}

const FuelTank& Car::getFuelTank() const
{
	return fuelTank;
}
const Engine& Car::getEngine() const
{
	return engine;
}
const Tires& Car::getTires() const
{
	return tires;
}
const Accumulator& Car::setAccumulator() const
{
	return accumulator;
}
double Car::getKm() const
{
	return km;
}
double Car::getWeight() const
{
	return weight;
}

void Car::drive(double km)
{
	if (km < 0)
	{
		throw std::invalid_argument("Invalid km.");
	}

	double neededFuel = (log(engine.getHorsePower()) / log(3.6) + log(weight) / log(8)) / 100 * km;

	if (neededFuel <= fuelTank.getFuel())
	{
		this->km += km;
		fuelTank.use(neededFuel);
	}
}

void Car::setFuelTank(const FuelTank& fuelTank)
{
	this->fuelTank = fuelTank;
}
void Car::setEngine(const Engine& engine)
{
	this->engine = engine;
}
void Car::setTires(const Tires& tires)
{
	this->tires = tires;
}
void Car::setAccumulator(const Accumulator& accumulator)
{
	this->accumulator = accumulator;
}
void Car::setKm(double km)
{
	if (km < 0)
	{
		throw std::invalid_argument("Invalid km of a car.");
	}

	this->km = km;
}
void Car::setWeight(double weight)
{
	if (weight < 0)
	{
		throw std::invalid_argument("Invalid weight of a car.");
	}

	this->weight = weight;
}

void Car::print()
{
	std::cout << "capacity: " << fuelTank.getCapacity() << ", fuel: " << fuelTank.getFuel() << ", km: " << getKm() << std::endl;
}

Car* dragRace(Car* car1, Car* car2)
{
	const double dragRace = 0.4;
	double fuel1 = car1->getFuelTank().getFuel();
	double fuel2 = car2->getFuelTank().getFuel();

	car1->drive(dragRace);
	car2->drive(dragRace);
	if (car1->getFuelTank().getFuel() != fuel1 && car2->getFuelTank().getFuel() == fuel2)
	{
		return car1;
	}
	else if (car1->getFuelTank().getFuel() == fuel1 && car2->getFuelTank().getFuel() != fuel2)
	{
		return car2;
	}
	else if (car1->getFuelTank().getFuel() != fuel1 && car2->getFuelTank().getFuel() != fuel2)
	{
		double rat1 = car1->getEngine().getHorsePower() / car1->getWeight();
		double rat2 = car2->getEngine().getHorsePower() / car2->getWeight();

		if (rat1 > rat2)
		{
			return car1;
		}
		else if (rat1 < rat2)
		{
			return car2;
		}
	}
	return nullptr;
}


