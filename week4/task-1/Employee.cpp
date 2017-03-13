//
//  Employee.cpp
//  task-1
//
//  Created by Emil Iliev on 3/13/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include "Employee.hpp"
#include <string.h>
#include <iostream>

using namespace std;

Employee::Employee(): firstName(nullptr), lastName(nullptr), weight(1){
    setID(0);
    setSalary(0.0);
};

Employee::Employee(int _id, char* _firstName, char* _lastName , double _salary, int _weight): weight(_weight),
firstName(nullptr), lastName(nullptr){
    this->setID(_id);
    this->setFirstName(_firstName);
    this->setLastName(_lastName);
    this->setSalary(_salary);
}

Employee::Employee(const Employee &other):weight(other.weight), firstName(nullptr), lastName(nullptr){
        this->setID(other.id);
        this->setFirstName(other.firstName);
        this->setLastName(other.lastName);
        this->setSalary(other.salary);
}

int Employee::getID(){
    return this->id;
}

double Employee::getSalary(){
    return this->salary;
}

char* Employee::getFirstName(){
    return  this->firstName;
}

char* Employee::getLastName(){
    return  this->lastName;
}

int Employee::getWeight(){
    return this->weight;
}

void Employee::setID(int newID){
    if (newID > 0){
        id = newID;
    }
}

void Employee::setSalary(double newSalary){
    if (newSalary > 0){
        salary = newSalary;
    }
}

void Employee::setFirstName(char* newFirstName){
    delete firstName;
    size_t length = strlen(newFirstName) + 1;
    firstName = new char[length];
    strcpy(firstName, newFirstName);
}

void Employee::setLastName(char* newLastName){
    delete lastName;
    size_t length = strlen(newLastName) + 1;
    lastName = new char[length];
    strcpy(lastName, newLastName);
}


int Employee::getAnnualSalary(){
    return MONTHS * getSalary();
}

void Employee::raiseSalary(int percent = 50){
    double prop = (double) percent / 100;
    int newSalary = salary * prop + salary;
    setSalary(newSalary);
}

void Employee::description(){
    cout<<"Employee with ID: "
    <<id<<"\nName: "
    <<firstName<<" "
    <<lastName<<" "
    <<"\nSalary: "
    <<salary
    <<endl;
}

