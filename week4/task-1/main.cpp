//
//  main.cpp
//  task-1
//
//  Created by Emil Iliev on 3/13/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include <iostream>
#include "Employee.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Employee emp;
    emp.setSalary(100);
    cout<<emp.getSalary()<<endl;
    emp.raiseSalary(20);
    
    
    Employee emp1(1,"Toshko", "Afrikanski", 341, 15);
    emp1.setFirstName("Pesho");
    emp1.setFirstName("Gosho");
    emp1.description();
    
    Employee pesho(emp1);
    pesho.description();
    return 0;
}
