//
//  Dog.hpp
//  Week6
//
//  Created by Emil Iliev on 3/27/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#ifndef Dog_hpp
#define Dog_hpp

#include <stdio.h>
class Dog{
    char* dogName;
 
    void free();
    void copyFrom(const Dog& other);
    
    public:
    Dog();
    Dog(char* newName);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();
    
    
    void setName(char* name);
    char* getName() const;
};

#endif /* Dog_hpp */
