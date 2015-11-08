/* 
 * File:   Import.h
 * Author: Fabian
 *
 * Created on 8. November 2015, 13:49
 */

#ifndef IMPORT_H
#define	IMPORT_H

#include "Point_2.h"

class Import {
public:
    Import();
    Import(int dimensions);
    Import(int dimensions, std::string filepath);
    virtual ~Import();
    
    std::vector<Point_2> getData();
    int getAnzExamples();
    
private:
    int dimensions;
    int anzExamples;
    std::vector<Point_2> data;
    
    void importData(std::string filepath);
};

#endif	/* IMPORT_H */

