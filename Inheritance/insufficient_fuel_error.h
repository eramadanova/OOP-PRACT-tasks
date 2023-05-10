#pragma once
#include <stdexcept>

class insufficient_fuel_error : public std::logic_error
{
public:
	insufficient_fuel_error(const char* errorMsg);

	const char* what();

private:
	char* errorMsg;
};

