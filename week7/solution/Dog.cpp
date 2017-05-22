//
//  Dog.cpp
//  Week6
//
//  Created by Emil Iliev on 3/27/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include "Dog.hpp"
#include <cstring>

Dog::Dog():dogName(){
	this->setName("Nqmam si ime");
}
Dog::Dog(char* newName): dogName(nullptr){
    setName(newName);
}

Dog::Dog(const Dog &other): dogName(nullptr){
    copyFrom(other);
}

Dog& Dog::operator=(const Dog &other){
    if(this != &other){
        copyFrom(other);
    }
    return *this;
}

Dog::~Dog(){
    free();
}

void Dog::setName(char *name){
    if (name){
        free();
        size_t length = strlen(name) + 1;
        dogName = new char[length];
        strcpy(dogName, name);
    }
}

char* Dog::getName() const{
    return dogName;
}

void Dog::free(){
    delete dogName;
}

void Dog::copyFrom(const Dog &other){
    setName(other.dogName);
}

//compare Dogs by comparing only their names, strcmp returns 0 if they are equal, thats why there is "!" in front to convert to a true value
bool Dog::operator==(const Dog& other) const {
	return !strcmp(this->dogName, other.getName());
}

//compare Dogs by comparing only their names, strcmp returns -1 or 1 if they are not equal and thats why with "!!" we make this function returning always 1 if they are not equal
bool Dog::operator!=(const Dog& other) const {
	return !!strcmp(this->dogName, other.getName());
}
