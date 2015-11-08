/* 
 * File:   sort.h
 * Author: Fabian
 *
 */

#ifndef SORT_H
#define	SORT_H

class Sort {
public:
    Sort();
    Sort(const Sort& orig);
    virtual ~Sort();
    
    //import(std::string link, std::string delimiter);
    
private:
    static const int anzExamples;
    float data[][];

};

#endif	/* SORT_H */

