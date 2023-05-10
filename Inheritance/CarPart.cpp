#include "CarPart.h"
#include <stdexcept>
#include <cstring>

#pragma warning (disable: 4996)

CarPart::CarPart() : CarPart("Unknown", "Unknown", "Unknown")
{
}

CarPart::CarPart(const char* id, const char* manufacturer, const char* description) : 
    id(nullptr), manufacturer(nullptr), description(nullptr)
{
    setId(id);
    try
    {
        setManufacturer(manufacturer);
        setDescription(description);
    }
    catch (const std::exception&)
    {
        free();
        throw;
    }
    
}

CarPart::CarPart(const CarPart& other)
{
    copyFrom(other);
}

CarPart& CarPart::operator=(const CarPart& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

CarPart::~CarPart()
{
}

void CarPart::setId(const char* id)
{
    if (!id)
    {
        throw std::invalid_argument("Invalid id.");
    }

    this->id = new char[(strlen(id) + 1)];
    strcpy(this->id, id);
}

void CarPart::setManufacturer(const char* manufacturer)
{
    if (!manufacturer)
    {
        throw std::invalid_argument("Invalid manufacturer.");
    }

    this->manufacturer = new char[strlen(manufacturer) + 1];
    strcpy(this->manufacturer, manufacturer);
}

void CarPart::setDescription(const char* description)
{
    if (!description)
    {
        throw std::invalid_argument("Invalid description.");
    }

    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

const char* CarPart::getId() const
{
    return id;
}

const char* CarPart::getManufacturer() const
{
    return manufacturer;
}

const char* CarPart::getDescription() const
{
    return description;
}

void CarPart::copyFrom(const CarPart& other)
{
    setId(other.id);
    setManufacturer(other.manufacturer);
    setDescription(other.description);
}

void CarPart::free()
{
    delete[] id;
    delete[] manufacturer;
    delete[] description;
}
