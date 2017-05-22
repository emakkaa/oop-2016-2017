#include <iostream>
#include "Egg.h"
#include "Basket.h"
using std::cout;

void printEgg(Egg& egg) {
	cout << egg;
	cout << egg.getColor() << "\n";
}

void printBasket(Basket& basket) {
	cout << basket;
}

int main() {

	//Egg tests
	Egg egg;

	egg.setColor(Color(1));
	egg.setIdentificator("NaStavri");
	egg.setSize(10);

	printEgg(egg);

	Egg egg2 = egg;

	printEgg(egg2);

	Egg egg3;

	egg3 = egg2;
	printEgg(egg3);

	Egg egg4;
	egg4.setIdentificator("Test");
	egg.setColor(Color::Black);
	egg.setSize(20);

	//BasketTests
	Basket basket;
	basket.addEgg(egg);
	basket.addEgg(egg2);
	basket.addEgg(egg3);
	basket.addEgg(egg4);
	basket.setBunnyName("Stavri");

	printBasket(basket);

	basket.removeEgg("Test");

	printBasket(basket);

	



	system("pause");
	return 0;
}