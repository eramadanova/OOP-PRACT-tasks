#include <iostream>
#include "Car.h"

int main()
{
	Tires tires1("A123", "BMW", "racing" , 200, 50, 20);
	Tires tires2("B567", "Range Rover", "offroad" , 170, 60, 15);
	Engine engine1("wwsd", "Belgium", "racing", 300);
	Engine engine2("fggs", "America", "eco-friendly", 100);
	Accumulator accumulator1("4548", "Germany", "racing", 100, "5");
	Accumulator accumulator2("6796", "Australia", "family", 50, "3");
	Car car1(300, engine1, tires1, accumulator1, 900, 1800);
	Car car2(100, engine2, tires2, accumulator2, 1800, 2000);
	
	Car* winner = dragRace(&car1, &car1);
	winner->print();
}