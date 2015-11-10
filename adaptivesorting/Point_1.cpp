/* 
 * File:   Point_1.cpp
 * Author: Fabian
 * 
 * Created on 8. November 2015, 13:01
 */
#include <iostream>
#include "Point_1.h"

Point_1::Point_1(double x) {
    xcoord = x;
}

Point_1::~Point_1() {}

double Point_1::x() const {
    return xcoord;
}

double Point_1::y() const { return 0; };

int Point_1::dimension() const {
    return 1;
}

std::ostream& operator<<(std::ostream& s, const Point_1& p)
{
    return s << p.x() << std::endl;
}