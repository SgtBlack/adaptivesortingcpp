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
    
    template <class RandomAccessIterator>
    int size(RandomAccessIterator first, RandomAccessIterator beyond){
        
        int size = 0;
        
        while( first != beyond ){
            first++;
            size++;
        }
        return size;
    }

    template <class InputIterator, class OutputIterator, class Less>
    OutputIterator greedySort(InputIterator first, InputIterator beyond, OutputIterator result, Less less ){
        
        greedySort(first, beyond, less);
        
        return copy(first, beyond, result);
    }
    
    
    
    template <class RandomAccessIterator, class Less>
    void greedySort(RandomAccessIterator first, RandomAccessIterator beyond, Less less ){

    }
    
    template <class InputIterator, class OutputIterator, class Less>
    OutputIterator bubbleSort(InputIterator first, InputIterator beyond, OutputIterator result, Less less ){

        bubbleSort(first, beyond, less );
        
        return copy(first, beyond, result);
    }
    
    
    
    template <class RandomAccessIterator, class Less>
    void bubbleSort(RandomAccessIterator first, RandomAccessIterator beyond, Less less ){
        
        int j = 0;
        bool notSorted = true;
        std::vector<Point_2>::iterator iter;
        
        while ( notSorted ) {
            
            notSorted = false;
            j++;

            for(iter = first; iter != beyond - j; iter++){
            
                if( less( *(iter+1),*iter ) ){
                    iter_swap(iter,iter+1);
                    notSorted = true;
                }
            }
        }
    }
};



#endif	/* SORT_H */