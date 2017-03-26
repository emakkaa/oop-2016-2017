//
//  Point.hpp
//  Week5Solution
//
//  Created by Emil Iliev on 3/26/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#endif /* Point_hpp */


class Point{
    
    double x;
    double y;
    double z;
    
    public:
        Point();
        Point(double _x, double _y, double _z);
        
        void setX(double _x);
        void setY(double _y);
        void setZ(double _z);
        
        double getX();
        double getY();
        double getZ();
        
        void translatePoint(double dx, double dy, double dz);
        double distance(const Point &other);
        void showPoint();
    
        bool comparePoints(const Point& other);
};
