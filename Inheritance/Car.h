#pragma once
#include "FuelTank.h"
#include "Engine.h"
#include "Tires.h"
#include "Accumulator.h"

class Car
{
public:
	Car(double capacity, const Engine& engine, const Tires& tires, const Accumulator& accumulator, double km, double weight);

	const FuelTank& getFuelTank() const;
	const Engine& getEngine() const;
	const Tires& getTires() const;
	const Accumulator& setAccumulator() const;
	double getKm() const;
	double getWeight() const;

	void drive(double km);
	void print();
private:
	FuelTank fuelTank;
	Engine engine;
	Tires tires;
	Accumulator accumulator;
	double km;
	double weight;

	void setFuelTank(const FuelTank& fuelTank);
	void setEngine(const Engine& engine);
	void setTires(const Tires& tires);
	void setAccumulator(const Accumulator& accumulator);
	void setKm(double km);
	void setWeight(double weight);
};

Car* dragRace(Car* car1, Car* car2);

