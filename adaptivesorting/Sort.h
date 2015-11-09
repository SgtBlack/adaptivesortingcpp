/* 
 * File:   Sort.h
 * Author: Fabian
 *
 * Created on 8. November 2015, 13:42
 */

#ifndef SORT_H
#define	SORT_H

#include <iterator>
#include <vector>
#include "Point_2.h"


class Sort {
public:
    Sort(){}
    virtual ~Sort(){}
    
    template <class T>
    void swap( T& a, T& b ){

        T temp(a); a = b; b = temp;
    }
    
    template <class ForwardIterator1, class ForwardIterator2>
    void iter_swap( ForwardIterator1 a, ForwardIterator2 b ){

        swap(*a, *b);
    }
    
    template<class InputIterator, class OutputIterator>
    OutputIterator copy(InputIterator first, InputIterator beyond, OutputIterator result){

        while( first != beyond ) {
            *result = *first;
            ++result; 
            ++first;
        }
        return result;
    }

    template <class InputIterator, class OutputIterator, class Less>
    OutputIterator greedySort(InputIterator first, InputIterator beyond, OutputIterator result, Less less ){
        
        //greedySort(first, beyond, less );
        
        //copy(first, beyond-1, result);
        
        return result;
    }
    
    template <class RandomAccessIterator>
    int size(RandomAccessIterator first, RandomAccessIterator beyond){
        
        int size = 0;
        
        while( first != beyond ){ 
           first++;
           size++;
        }
        return size;
    }
    
    template <class RandomAccessIterator, class Less>
    void greedySort(RandomAccessIterator first, RandomAccessIterator beyond, Less less ){
        
        //std::vector<Point_2> x; copy(first, beyond-1, x.begin());
        std::vector<Point_2> xu;
        std::vector<Point_2> x1;
        std::vector<Point_2> x2;

        if(size(first, beyond) > 0){
            xu.push_back( *first );
        } else return;
        
        std::vector<Point_2>::iterator iter;
        for(iter = first+1; iter != beyond; iter++){
        
            if( less( *(xu.end()-1), *iter ) ){
                xu.push_back( *iter );
                
            } else if( x1.size() == x2.size() ){
                x1.push_back( *iter );
            } else {
                x2.push_back( *iter );
            }
        }
        
        if( xu.size() == size(first, beyond) ){
            //copy(first, beyond, first);
            return;
        } else {
            greedySort( x1.begin(), x1.end(), less );
            //xu.assign( x1.begin(), x1.end() );
            std::vector<Point_2>::iterator i_iter1;
            for(i_iter1 = x1.begin(); i_iter1 != x1.end(); i_iter1++)
                xu.push_back( *i_iter1 );
            
            greedySort( x2.begin(), x2.end(), less );
            //xu.assign( x2.begin(), x2.end() );
            std::vector<Point_2>::iterator i_iter2;
            for(i_iter2 = x2.begin(); i_iter2 != x2.end(); i_iter2++)
                xu.push_back( *i_iter2 );
            
            //return xu.begin();
        }
    }
};



#endif	/* SORT_H */