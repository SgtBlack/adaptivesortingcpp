/* 
 * File:   main.cpp
 * Author: Fabian Witt
 * 
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Point_1.h"
#include "Point_2.h"
#include "Import.h"

using namespace std;

int main(int argc, char** argv) {
    
    Import import = Import(2, "data/artificialPolygons/H.txt");
    
    cout << import.getAnzExamples() << endl;
    
    vector<Point_2> data = import.getData();
    
//    for(int i = 0; i < import.getAnzExamples(); i++){
//        cout << data.at(i).x() << "/" << data.at(i).y() << endl;
//    }
    
    
    
    
    return EXIT_SUCCESS;
}

