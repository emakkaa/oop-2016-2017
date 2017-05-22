//
//  DogShelter.cpp
//  Week6
//
//  Created by Emil Iliev on 3/27/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include "DogShelter.hpp"
#include <cstring>

#define DEFAULT_NUM 1
#define DEFAULT_NAME "Seslavtsi"

DogShelter::DogShelter():dogs(nullptr), shelterName(nullptr){
    setNumDogs(DEFAULT_NUM);
    setName(DEFAULT_NAME);
    generateDogs();
}

DogShelter::DogShelter(char* name, int num): dogs(nullptr), shelterName(nullptr){
    setName(name);
    setNumDogs(num);
    generateDogs();
}

DogShelter::DogShelter(const DogShelter& other): dogs(nullptr), shelterName(nullptr){
    copyFrom(other);
}

DogShelter& DogShelter::operator=(const DogShelter &other){
    if (this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

DogShelter::~DogShelter(){
    free();
}

void DogShelter::copyFrom(const DogShelter &other){
    setNumDogs(other.numDogs);
    setName(other.shelterName);
    dogs = new Dog[numDogs];
    for(int curDog = 0; curDog < numDogs; ++curDog){
        dogs[curDog] = other.dogs[curDog];
    }
}

void DogShelter::generateDogs(){
    delete dogs;
    dogs = new Dog[numDogs];
    for (int num = 0;  num < numDogs; ++num){
        dogs[num] = Dog();
    }
}

void DogShelter::free(){
    delete [] dogs;
    dogs = nullptr;
    delete shelterName;
    shelterName = nullptr;
    
}

void DogShelter::setName(char *name){
    delete [] shelterName;
    size_t length = strlen(name) + 1;
    shelterName = new char[length];
    strcpy(shelterName, name);
}

char* DogShelter::getName() const{
    return shelterName;
}

void DogShelter::setNumDogs(int num){
    if (num >= 0){
        numDogs = num;
    }
}

int DogShelter::getNumDogs() const {
    return numDogs;
}

//returns the dog on the index we want - allows Dogshelter a; a[0];
Dog DogShelter::operator[](int index) {
	if (index >= this->getNumDogs() ||
		index < 0) {
		return Dog();
	}

	return dogs[index];
}
//replaces operator[]
Dog DogShelter::getDog(int index) {
	if (index >= this->getNumDogs() ||
		index < 0) {
		return Dog();
	}
	
	return dogs[index];
}

//compares DogShelters by comparing the names and the number of dogs. If they are equal compare each dog
bool DogShelter::operator==(DogShelter& other) {
	if (!!strcmp(this->getName(), other.getName())) {
		return false;
	}

	if (this->getNumDogs() != other.getNumDogs()) {
		return false;
	}
	else {
		for (int index = 0; index < this->getNumDogs(); index++) {
			if (this->getDog(index) != other.getDog(index)) {
				return false;
			}
		}
	}

	return true;
}

//compares DogShelters by comparing the names and the number of dogs. If they are equal compare each dog
bool DogShelter::operator!=(DogShelter& other) {
	if (!!strcmp(this->getName(), other.getName())) {
		return true;
	}

	if (this->getNumDogs() != other.getNumDogs()) {
		return true;
	}
	else {
		for (int index = 0; index < this->getNumDogs(); index++) {
			if (this->getDog(index) != other.getDog(index)) {
				return true;
			}
		}
	}

	return false;
}

//compares DogShelters by their size
bool DogShelter::operator<(DogShelter& other) {
	return this->getNumDogs() < other.getNumDogs();
}

//compares DogShelters by their size
bool DogShelter::operator>(DogShelter& other) {
	return this->getNumDogs() > other.getNumDogs();
}

//compares DogShelters by their size
bool DogShelter::operator<=(DogShelter& other) {
	return this->getNumDogs() <= other.getNumDogs();
}

//compares DogShelters by their size
bool DogShelter::operator>=(DogShelter& other) {
	return this->getNumDogs() >= other.getNumDogs();
}
