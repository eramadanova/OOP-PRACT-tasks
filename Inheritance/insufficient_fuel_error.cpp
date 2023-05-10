#include "insufficient_fuel_error.h"

#pragma warning (disable: 4996)

insufficient_fuel_error::insufficient_fuel_error(const char* errorMsg) : logic_error(errorMsg)
{
	strcpy(this->errorMsg, errorMsg);
}

const char* insufficient_fuel_error::what()
{
	return errorMsg;
}


