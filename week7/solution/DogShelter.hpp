//
//  DogShelter.hpp
//  Week6
//
//  Created by Emil Iliev on 3/27/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#ifndef DogShelter_hpp
#define DogShelter_hpp

#define MAX_CHAR 100


#include <stdio.h>
#include <fstream>
#include <iostream>
#include "Dog.hpp"

class DogShelter{

    Dog* dogs;
    char* shelterName;
    int numDogs;
    void free();
    void copyFrom(const DogShelter& other);
 
    void generateDogs();
    
public:
    DogShelter();
    DogShelter(char* name, int num);
    DogShelter(const DogShelter& other);
    DogShelter& operator=(const DogShelter& other);
	Dog operator[](int index);
	Dog getDog(int index);
	bool operator==(DogShelter& other);
	bool operator!=(DogShelter& other);
	bool operator<(DogShelter& other);
	bool operator>(DogShelter& other);
	bool operator<=(DogShelter& other);
	bool operator>=(DogShelter& other);

	//alows to stream the object
	friend ostream &operator<<(ostream &os, DogShelter& ds) {
		os << "This dogshelter name is " << ds.getName() << "\n";
		os << "The dogs in the shelter are: " << "\n";
		for (int index = 0; index < ds.getNumDogs(); index++) {
			os << ds.getDog(index).getName() << "\n";
		}
		return os;
	}

	//alows us to set object values
	friend istream &operator>>(istream &is, DogShelter& ds) {
		char temp[MAX_CHAR];
		is >> temp;
		ds.setName(temp);

		return is;
	}

    ~DogShelter();
    
    void setName(char* name);
    char* getName() const;
    void setNumDogs(int num);
    int getNumDogs() const;
};
#endif /* DogShelter_hpp */
