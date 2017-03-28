//
//  DogShelter.hpp
//  Week6
//
//  Created by Emil Iliev on 3/27/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#ifndef DogShelter_hpp
#define DogShelter_hpp

#include <stdio.h>
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
    ~DogShelter();
    
    void setName(char* name);
    char* getName() const;
    void setNumDogs(int num);
    int getNumDogs() const;
};
#endif /* DogShelter_hpp */
