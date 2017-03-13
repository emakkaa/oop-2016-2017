//
//  Employee.hpp
//  task-1
//
//  Created by Emil Iliev on 3/13/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#ifndef Employee_hpp
#define Employee_hpp



class Employee{
    
    int id;
    char* firstName;
    char* lastName;
    double salary;
    const int weight;
    
    const int MONTHS = 12;
    
    public:
    
        Employee();
        Employee(int, char*, char*, double, int);
        Employee(const Employee &);
        
        int getID();
        char* getFirstName();
        char* getLastName();
        double getSalary();
        int getWeight();
        
        void setID(int);
        void setFirstName(char*);
        void setLastName(char*);
        void setSalary(double);
        
        void description();
        int getAnnualSalary();
        void raiseSalary(int);
};

#endif /* Employee_hpp */
