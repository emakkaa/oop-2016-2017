//
//  main.cpp
//  Week5Solution
//
//  Created by Emil Iliev on 3/26/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include <iostream>
#include "Matrix.hpp"
int main(int argc, const char * argv[]) {
    
    
    
    Matrix m2(2,2);
    m2.showPoints();
    
    
    Matrix m3(3,3);
    m3.showPoints();
    m2 = m3;
    m2.showPoints();
    
    return 0;
}
