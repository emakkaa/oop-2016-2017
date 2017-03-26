//
//  Matrix.hpp
//  Week5Solution
//
//  Created by Emil Iliev on 3/26/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include "Point.hpp"


class Matrix{
    
    Point** points;
    int rows;
    int cols;
    
    void copyFrom(const Matrix &other);
    void dealloc();
    int getRand();
    int sumOfRowsAndCols();
public:
    
    
    Matrix();
    Matrix(int _rows, int _cols);
    Matrix(const Matrix &other);
    ~Matrix();
    Matrix& operator=(const Matrix &other);
    
    void setRows(int newRows);
    void setCols(int newCols);
    
    int getRows();
    int getCols();
    
    Point findMin();
    Point findMax();
    double calcMaxDistance();
    void showPoints();
    
};
#endif /* Matrix_hpp */
