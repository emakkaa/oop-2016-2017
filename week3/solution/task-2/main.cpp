//
//  main.cpp
//  task-2
//
//  Created by Emil Iliev on 3/13/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;


class Animal{
    int weight;
    int daysGrowing;
    int foodNeeded;
    int waterNeeded;
    char* name;
    
    public:
        Animal(): name(nullptr){
            weight = 0;
            daysGrowing = 0;
            foodNeeded = 0;
            waterNeeded = 0;
        }
        
        Animal(int _weight, int _daysGrowing, int _foodNeeded, int _waterNeeded, char* _name): name(nullptr){
            setWeight(_weight);
            setDaysGrowing(_daysGrowing);
            setFoodNeeded(_foodNeeded);
            setWaterNeeded(_waterNeeded);
            setName(_name);
        }
    
        int getWeight(){
            return weight;
        }
        
        int getDaysGrowing(){
            return daysGrowing;
        }
        
        int getFoodNeeded(){
            return foodNeeded;
        }
        
        int getWaterNeeded(){
            return waterNeeded;
        }

        char* getName(){
            return name;
        }
        
        void setWeight(int newWeight){
            if (newWeight > 0){
                weight = newWeight;
            }
        }
        
        void setDaysGrowing(int newNumDays){
            if (newNumDays > 0){
                daysGrowing = newNumDays;
            }
        }
        
        void setFoodNeeded(int requiredFood){
            if (requiredFood > 0){
                foodNeeded = requiredFood;
            }
        }
        
        void setWaterNeeded(int requiredWater){
            if(requiredWater > 0){
                waterNeeded = requiredWater;
            }
        }
        
        void setName(char* newName){
            delete name;
            size_t length = strlen(newName) + 1;
            name = new char[length];
            strcpy(name, newName);
        }
        
        void description(){
            cout<<weight<<"\n"
                <<daysGrowing<<"\n"
                <<foodNeeded<<"\n"
                <<waterNeeded<<"\n"
                <<name<<"\n";
        }
        
        void feed(int water, int food){
            int newFoodCap = foodNeeded - food;
            setFoodNeeded(newFoodCap);
            int newWaterCap = waterNeeded - water;
            setWaterNeeded(newWaterCap);
        }
        
        
        void needs(){
            if (foodNeeded > 0 && waterNeeded > 0){
                cout<<"The animal needs : "<<foodNeeded<<" kg food and "<<waterNeeded<<" l water.";
            }
        }
        
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Animal animal(15,150,3,3,"Tom");
    animal.setName("Milka");
    animal.description();
    animal.needs();

    
    
    return 0;
}
