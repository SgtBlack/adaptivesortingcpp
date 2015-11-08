/* 
 * File:   Point_1.cpp
 * Author: Fabian
 * 
 * Created on 8. November 2015, 13:01
 */

#include "Point_1.h"

Point_1::Point_1(double x) : xcoord(x) {}

Point_1::~Point_1() {}

double Point_1::x() const {
    return xcoord;
}

double Point_1::y() const { return 0; };

double Point_1::z() const { return 0; };

int Point_1::dimension() const {
    return 1;
}