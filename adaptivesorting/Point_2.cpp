/* 
 * File:   Point_2.cpp
 * Author: Fabian Witt
 * 
 */

#include <iostream>
#include "Point_2.h"

Point_2::Point_2(double x, double y) : Point_1::Point_1(x), ycoord(y) {}

Point_2::~Point_2(){}

double Point_2::y() const {
    return ycoord;
}

int Point_2::dimension() const {
    return 2;
}

std::ostream& operator<<(std::ostream& s, const Point_2& p)
{
    return s << p.x() << "/" << p.y() << std::endl;
}

