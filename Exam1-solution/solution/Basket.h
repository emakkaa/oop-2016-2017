#pragma once
#include <iostream>
#include <string.h>
#include "Egg.h"

class Basket
{
private:

	char* bunnyName;
	Egg* eggs;
	int capacity;
	int current;

	void resize();
	void copy(const Basket& other);

public:
	Basket();
	Basket(const Basket& other);
	Basket(const char* newBunnyName, Egg* newEggs, int eggsSize);
	Basket& operator=(const Basket& other);
	~Basket();

	void setBunnyName(const char* );
	void setEggs(Egg* eggs, int size);

	char* getBunnyName() const;
	int getCapacity() const;
	int getCurrent() const;
	Egg* getEggs() const;

	void addEgg(Egg& newEgg);
	void removeEgg(char*);

	friend ostream& operator<<(ostream& os, const Basket& basket)
	{
		os << "This basket belongs to " << basket.getBunnyName() << ".\nAt the momment it has " << basket.getCurrent() << " eggs in it with maximum of " << basket.getCapacity() << "\n";
		os << "The eggs in it are: \n";
		for (int i = 0; i < basket.getCurrent(); i++) {
			os << basket.getEggs()[i].getIdentificator() << "\n";
		}
		return os;
	}
};