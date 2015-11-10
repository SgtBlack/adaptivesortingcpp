/* 
 * File:   Import.cpp
 * Author: Fabian Witt
 *
 */
#include <fstream>
#include <vector>

#include "Import.h"


using namespace std;

Import::Import() {
    dimensions = 1;
}

Import::Import(int dimensions) {
    this->dimensions = dimensions;
}

Import::Import(int dimensions, string filepath) {
    this->dimensions = dimensions;
    
    importData(filepath);
}

Import::~Import() {
}

std::vector<Point_2> Import::getData(){
    return data;
}

int Import::getAnzExamples(){
    return anzExamples;
}

void Import::importData(string filepath){
    
    ifstream infile;
    infile.open(filepath);
    
    string line;
    
    //getline(infile, line);

    infile >> anzExamples;
    //anzExamples = stoi( line );
    
    for( int i = 0; i < anzExamples; i++ )
    {
        double coordinates[dimensions];

        if(dimensions == 1){
            infile >> coordinates[0];
            
        } else if(dimensions == 2){
            infile >> coordinates[0] >> coordinates[1];
        }
        
        data.push_back(Point_2(coordinates[0], coordinates[1]));
    }
    
    infile.close();
}