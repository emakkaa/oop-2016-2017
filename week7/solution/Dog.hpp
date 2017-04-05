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
#include <fstream>

using namespace std;

class Dog{
    char* dogName;
 
    void free();
    void copyFrom(const Dog& other);
    
    public:
    Dog();
    Dog(char* newName);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
	bool operator==(const Dog& other) const;
	bool operator!=(const Dog& other) const;
    ~Dog();

	friend ostream &operator<<(ostream &os, Dog& d) {
		os << d.getName() << "\n";
		return os;
	}

	friend istream &operator>>(istream &is, Dog& d) {
		is >> d.dogName;
		return is;
	}
    
    
    void setName(char* name);
    char* getName() const;
};

#endif /* Dog_hpp */
