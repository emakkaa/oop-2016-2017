#pragma once
#include <iostream>
#include <string.h>
#include "ColorEnum.h"
using std::ostream;

class Egg
{
private:

	char* identificator;
	double size;
	Color color;

	void copy(const Egg& other) {
		this->setIdentificator(other.getIdentificator());
		this->setSize(other.getSize());
		this->setColor(other.getColor());
	}

public:
	Egg();
	~Egg();
	Egg(const Egg& other);
	Egg& operator=(const Egg& other);
	

	char* getIdentificator() const;
	double getSize() const;
	Color getColor() const;

	void setIdentificator(char*);
	void setSize(double);
	void setColor(Color);

	friend ostream& operator<<(ostream& os, const Egg& egg)
	{
		os << "This is an egg. It's identificator is - " << egg.getIdentificator() << ". His color is " << (Color)egg.getColor() << " with size of " << egg.getSize();
		return os;
	}
};