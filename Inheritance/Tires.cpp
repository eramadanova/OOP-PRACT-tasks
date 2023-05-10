#include "Tires.h"

Tires::Tires() : CarPart()
{
    setWidth(165);
    setProfile(30);
    setDiameter(13);
}

Tires::Tires(const char* id, const char* manufacturer, const char* description, unsigned width, unsigned profile, unsigned diameter) :
    CarPart(id, manufacturer, description)
{
    setWidth(width);
    setProfile(profile);
    setDiameter(diameter);
}

void Tires::setWidth(unsigned width)
{
    if (width < 155 || width > 365)
    {
        throw std::invalid_argument("Invalid width of tires.");
    }

    this->width = width;
}

void Tires::setProfile(unsigned profile)
{
    if (profile < 30 || profile > 80)
    {
        throw std::invalid_argument("Invalid profile of tires.");
    }

    this->profile = profile;
}

void Tires::setDiameter(unsigned diameter)
{
    if (diameter < 13 || diameter > 21)
    {
        throw std::invalid_argument("Invalid diameter of tires.");
    }
    this->diameter = diameter;
}

unsigned Tires::getWidth() const
{
    return width;
}

unsigned Tires::getProfile() const
{
    return profile;
}

unsigned Tires::getDiamater() const
{
    return diameter;
}

std::ostream& operator<<(std::ostream& os, const Tires& other)
{
    return os << "(" << other.getId() << ") by " << other.getManufacturer() << " - " << other.getDescription() << " - " << other.getWidth() << "/" << other.getProfile() << "R" << other.getDiamater();
}
