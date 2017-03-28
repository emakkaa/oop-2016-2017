//
//  Dog.cpp
//  Week6
//
//  Created by Emil Iliev on 3/27/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include "Dog.hpp"
#include <cstring>

Dog::Dog():dogName(nullptr){}
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
