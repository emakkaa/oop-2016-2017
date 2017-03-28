//
//  main.cpp
//  Week6
//
//  Created by Emil Iliev on 3/27/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include <iostream>
#include "DogShelter.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    DogShelter a;
    DogShelter b("Gorni Bogrov", 1);
    
    cout<<a.getName()<<endl;
    a = b;
    
    cout<<a.getName()<<endl;
    
    return 0;
}
