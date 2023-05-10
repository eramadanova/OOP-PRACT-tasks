#include "Engine.h"

Engine::Engine() : CarPart()
{
    setHorsePower(150);
}

Engine::Engine(const char* id, const char* manufacturer, const char* description, unsigned horsePower) :
    CarPart(id, manufacturer, description)
{
    setHorsePower(horsePower);
}

void Engine::setHorsePower(unsigned horsePower)
{
    this->horsePower = horsePower;
}

unsigned Engine::getHorsePower() const
{
    return horsePower;
}

std::ostream& operator<<(std::ostream& os, const Engine& other)
{
    return os << "(" << other.getId() << ") by " << other.getManufacturer() << " - " << other.getDescription() << " - " << other.getHorsePower() << " hp";
}

