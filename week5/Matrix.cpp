//
//  Matrix.cpp
//  Week5Solution
//
//  Created by Emil Iliev on 3/26/17.
//  Copyright © 2017 Emil Iliev. All rights reserved.
//

#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix():points(nullptr){
    rows = 0;
    cols = 0;
}

Matrix::Matrix(int _rows, int _cols): points(nullptr){
    rows = _rows;
    cols = _cols;
    points = new Point*[_rows]; //1
    for (int r = 0; r < _rows; ++r){
        points[r] = new Point[_cols]; //2
        for (int j = 0; j < _cols; ++j){
            int x = getRand();
            int y = getRand();
            int z = getRand();
            points[r][j] = Point(x,y,z); //3
        }
    }
}

Matrix::~Matrix(){
    dealloc();
}

Matrix::Matrix(const Matrix &other): points(nullptr){
    copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other){
    if (this != &other){
        dealloc();
        copyFrom(other);
    }
    return *this;
}



void Matrix::showPoints(){
    for (int r = 0; r < rows; r++){
        for(int c = 0; c< cols; c++){
            points[r][c].showPoint();
        }
        std::cout<<"\n";
    }
}

double Matrix::calcMaxDistance(){
    return 0.0;
}

Point Matrix::findMin(){
    Point minPoint = points[0][0];
    for(int row = 0; row < getRows(); ++row){
        for(int col = 0; col < getCols(); ++col){
            if (minPoint.comparePoints(points[row][col])){
                minPoint = points[row][col];
            }
        }
    }
    return minPoint;
}

Point Matrix::findMax(){
    Point maxPoint = points[0][0];
    for(int row = 0; row < getRows(); ++row){
        for(int col = 0; col < getCols(); ++col){
            if (!maxPoint.comparePoints(points[row][col])){
                maxPoint = points[row][col];
            }
        }
    }
    return maxPoint;
}


void Matrix::dealloc(){
    for (int r = 0; r < rows; ++r){
        delete points[r];
    }
    delete points;
}

void Matrix::copyFrom(const Matrix &other){
    rows = other.rows;
    cols = other.cols;
    points = new Point*[other.rows];
    for(int r = 0; r < other.rows; r++){
        points[r] = new Point[other.cols];
        for(int c = 0; c < other.cols; c++){
            points[r][c] = other.points[r][c];
        }
    }
}

int Matrix::getRand(){
    return rand() % 10;
}


int Matrix::getRows(){
    return rows;
}

int Matrix::getCols(){
    return cols;
}

int Matrix::sumOfRowsAndCols(){
    int sum = 0;
    int allElements = rows + cols;
    for (int elem = 0; elem < allElements; ++elem){
        sum += elem;
    }
    return sum;
}

