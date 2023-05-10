#include "Accumulator.h"
#include <cstring>

#pragma warning (disable: 4996)

Accumulator::Accumulator() : CarPart()
{
    setAmpHours(70);
    setBatteryId("Unknown");
}

Accumulator::Accumulator(const char* id, const char* manufacturer, const char* description, unsigned ampHours, const char* batteryId)
    : CarPart(id, manufacturer, description)
{
    setAmpHours(ampHours);
    setBatteryId(batteryId);
}

void Accumulator::setAmpHours(unsigned ampHours)
{
    this->ampHours = ampHours;
}

void Accumulator::setBatteryId(const char* batteryId)
{
    if (!batteryId)
    {
        throw std::invalid_argument("Invalid id of accumulator.");
    }

    strcpy(this->batteryId, batteryId);
}

unsigned Accumulator::getAmpHours() const
{
    return ampHours;
}

const char* Accumulator::getbatteryId() const
{
    return batteryId;
}


std::ostream& operator<<(std::ostream& os, const Accumulator& other)
{
    return os << "(" << other.getId() << ") by " << other.getManufacturer() << " - " << other.getDescription() << " - " << other.getAmpHours() << " Ah";
}
