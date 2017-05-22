#include <iostream>
#include "Egg.h"
using std::cout;

#define DEFAULT_EGG_SIZE 0


Egg::Egg() : identificator(nullptr), size(DEFAULT_EGG_SIZE), color(Color::None) {
}

Egg::Egg(const Egg& other) {
	copy(other);
}

Egg& Egg::operator=(const Egg& other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}

Egg::~Egg() {
	delete[] identificator;
}

double Egg::getSize() const {
	return this->size;
}

char* Egg::getIdentificator() const {
	return this->identificator;
}

Color Egg::getColor() const {
	return this->color;
}

void Egg::setIdentificator(char* newIdentificator) {
	if (this->identificator != nullptr) {
		delete[] this->identificator;
		this->identificator = nullptr;
	}
	size_t newIdentificatorLength = strlen(newIdentificator) + 1;
	this->identificator = new char[newIdentificatorLength];
	strcpy(this->identificator, newIdentificator);
}
void Egg::setSize(double newSize) {
	if (size < DEFAULT_EGG_SIZE) {
		cout << "Wrong size added (" << newSize << ") \n";
		return;
	}
	else {
		this->size = newSize;
	}
}
void Egg::setColor(Color newColor) {
	this->color = newColor;
}