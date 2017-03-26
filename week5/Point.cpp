//
//  Point.cpp
//  Week5Solution
//
//  Created by Emil Iliev on 3/26/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include "Point.hpp"
#include <cmath>
#include <iostream>

#define POWER 2

Point::Point(){
    x = 0;
    y = 0;
    z = 0;
}

Point::Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
{
}

/*
 Този запис е същия като:
 Point(double _x, double _y, double _z) {
 x = _x;
 y = _y;
 z = _z;
 }
 
 */

//функции(селектори) за достъпване на private: данните
double Point::getX() { return x; };
double Point::getY() { return y; };
double Point::getZ() { return z; };


//функции(манипулатори) за промяна на private: данните
void Point::setX(double _x){
    x = _x;
}

void Point::setY(double _y) {
    y = _y;
}

void Point::setZ(double _z) {
    z = _z;
}

void Point::translatePoint(double dx, double dy, double dz) {
    setX(getX() + dx);
    setY(getY() + dy);
    setZ(getZ() + dz);
}

double Point::distance(const Point &other) {
    //използваме this като пояснение, че става дума за нашата точка от класа.
    
    return sqrt(
                pow(this->x - other.x, POWER) +
                pow(this->y - other.y, POWER) +
                pow(this->z - other.z, POWER)
                );
}

void Point::showPoint(){
    std::cout<<"("<<x<<" "<<y<<" "<<z<<") ";
}


bool Point::comparePoints(const Point &other){
    
    return (x > other.x && y > other.y && z > other.z);
}





