#pragma once
class CarPart
{
public:
	CarPart();
	CarPart(const char* id, const char* manufacturer, const char* description);
	CarPart(const CarPart& other);
	CarPart& operator=(const CarPart& other);
	~CarPart();

	void setId(const char* id);
	void setManufacturer(const char* manufacturer);
	void setDescription(const char* description);

	const char* getId() const;
	const char* getManufacturer() const;
	const char* getDescription() const;

private:
	char* id;
	char* manufacturer;
	char* description;

	void copyFrom(const CarPart& other);
	void free();
};

