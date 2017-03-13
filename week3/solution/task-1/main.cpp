//
//  main.cpp
//  task-1
//
//  Created by Emil Iliev on 3/13/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

class Employee{
    
    int id;
    char* firstName;
    char* lastName;
    double salary;
    const int weight;
    
    const int MONTHS = 12;
    
    public:
        
        Employee(): firstName(nullptr), lastName(nullptr), weight(1){
            setID(0);
            setSalary(0.0);
        };
        
        Employee(int _id, char* _firstName, char* _lastName , double _salary, int _weight): weight(_weight),
                firstName(nullptr), lastName(nullptr){
            setID(_id);
            setFirstName(_firstName);
            setLastName(_lastName);
            setSalary(_salary);
        }
        
        int getId(){
            return id;
        }
        
        double getSalary(){
            return salary;
        }
        
        const char* getFirstName(){
            return  firstName;
        }
        
        const char* getLastName(){
            return  lastName;
        }
        
        int getWeight(){
            return weight;
        }

        void setID(int newID){
            if (newID > 0){
                id = newID;
            }
        }
        
        void setSalary(double newSalary){
            if (newSalary > 0){
                salary = newSalary;
            }
        }
        
        void setFirstName(char* newFirstName){
            delete firstName;
            size_t length = strlen(newFirstName) + 1;
            firstName = new char[length];
            strcpy(firstName, newFirstName);
        }
        
        void setLastName(char* newLastName){
            delete lastName;
            size_t length = strlen(newLastName) + 1;
            lastName = new char[length];
            strcpy(lastName, newLastName);
        }
        
        
    int getAnnualSalary(){
        return MONTHS * getSalary();
    }
    
    void raiseSalary(int percent = 50){
        double prop = (double) percent / 100;
        cout<<prop<<endl;
        int newSalary = salary * prop + salary;
        setSalary(newSalary);
    }

    void description(){
        cout<<"Employee with ID: "
            <<id<<"\nName: "
            <<firstName<<" "
            <<lastName<<" "
            <<"\nSalary: "
            <<salary
            <<endl;
    }

};



int main(int argc, const char * argv[]) {
    
    Employee emp;
    emp.setSalary(100);
    cout<<emp.getSalary()<<endl;
    emp.raiseSalary(20);
    
    
    Employee emp1(1,"Emo", "Iliev", 1000, 15);
    emp1.setFirstName("Pesho");
    emp1.setFirstName("Gosho");
    emp1.description();
    
    return 0;
}
