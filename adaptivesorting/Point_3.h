/* 
 * File:   Point_3.h
 * Author: Fabian
 *
 * Created on 8. November 2015, 17:08
 */

#ifndef POINT_3_H
#define	POINT_3_H

#include "Point_2.h"

class Point_3 : public Point_2 {
public:
    Point_3(double x = 0.0, double y = 0.0, double z = 0.0);
    virtual ~Point_3();
    
    virtual double  z() const;
    virtual int     dimension() const;
    
    
//private:
    
protected:
    double  zcoord;
};

#endif	/* POINT_3_H */

