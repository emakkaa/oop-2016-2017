//
//  main.cpp
//  Week6
//
//  Created by Emil Iliev on 3/27/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include <iostream>
#include "DogShelter.hpp"

using std::endl;
using std::cout;

int main(int argc, const char * argv[]) {
	Dog pesho("Pesho");
	Dog gosho("Gosho");

	cout << gosho << pesho;

	bool areEqual = pesho == gosho;
	bool areNotEqual = pesho != gosho;

	cout << areEqual << endl;
	cout << areNotEqual << endl;

    DogShelter a("Gorni Bogrov", 1);
    DogShelter b("Gorni Bogrov", 1);
    
	areEqual = a == b;
	areNotEqual = a != b;

	cout << areEqual << endl;
	cout << areNotEqual << endl;

	DogShelter c("",2);

	cin >> c;
	cout << c << endl;

    return 0;
}
