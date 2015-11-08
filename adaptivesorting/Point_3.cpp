/* 
 * File:   Point_3.cpp
 * Author: Fabian
 * 
 * Created on 8. November 2015, 17:08
 */

#include "Point_3.h"

Point_3::Point_3(double x, double y, double z) : Point_2::Point_2(x, y), zcoord(z) {}

Point_3::~Point_3() {}

double Point_3::z() const {
    return zcoord;
}

int Point_3::dimension() const {
    return 3;
}

