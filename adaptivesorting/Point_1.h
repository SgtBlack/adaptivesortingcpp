/* 
 * File:   Point_1.h
 * Author: Fabian
 *
 * Created on 8. November 2015, 13:01
 */

#ifndef POINT_1_H
#define	POINT_1_H

class Point_1 {
public:
    Point_1(double x = 0.0);
    virtual ~Point_1();
    
    virtual double x() const;
    virtual double y() const;
    virtual int    dimension() const;
    
protected:
    double xcoord;
};

#endif	/* POINT_1_H */

