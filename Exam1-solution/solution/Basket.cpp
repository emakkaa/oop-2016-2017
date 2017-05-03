#include <iostream>
#include <string.h>
#include "Basket.h"

#define CAPACITY_MULTIPLIER 2
#define DEFAULT_CAPACITY 10
#define MINIMUM_EGGS 0

void Basket::resize() {
	this->capacity *= CAPACITY_MULTIPLIER;

	Egg* newEggs = new Egg[this->capacity];
	
	for (int i = 0; i < this->current; i++) {
		newEggs[i] = this->eggs[i];
	}

	delete[] this->eggs;

	this->eggs = newEggs;
}

void Basket::copy(const Basket& other) {
	this->setBunnyName(other.getBunnyName());
	this->capacity = other.getCapacity();
	this->current = other.getCurrent();
}


Basket::Basket() : bunnyName(nullptr), eggs(nullptr), current(MINIMUM_EGGS), capacity(DEFAULT_CAPACITY) {}


Basket::Basket(const Basket& other) {
	copy(other);
}

Basket& Basket::operator=(const Basket& other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}

Basket::~Basket() {
	delete[] this->bunnyName;
	delete[] this->eggs;
}

void Basket::setBunnyName(const char* newBunnyName) {
	if (this->getBunnyName() != nullptr) {
		delete[] this->bunnyName;
	}

	size_t length = strlen(newBunnyName) + 1;
	this->bunnyName = new char[length];
	strcpy(this->bunnyName, newBunnyName);
}

char* Basket::getBunnyName() const {
	return this->bunnyName;
}
int Basket::getCapacity() const {
	return this->capacity;
}
int Basket::getCurrent() const {
	return this->current;
}
Egg* Basket::getEggs() const {
	return this->eggs;
}

void Basket::addEgg(Egg& newEgg) {
	if (this->eggs == nullptr) {
		this->eggs = new Egg[DEFAULT_CAPACITY];
	}

	if (this->getCurrent() == this->getCapacity()) {
		resize();
	}

	this->eggs[current] = newEgg;
	current++;
}
void Basket::removeEgg(char* eggToBeRemoved) {
	for (int i = 0; i < this->getCurrent(); i++) {
		if (strcmp(this->eggs[i].getIdentificator(), eggToBeRemoved) == 0) {
			for (int j = i; j < this->getCurrent() - 1; j++) {
				this->eggs[j] = this->eggs[j + 1];
			}
			current--;
			return;
		}
	}
}
