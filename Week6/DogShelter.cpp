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
