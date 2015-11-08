/* 
 * File:   Sort.cpp
 * Author: Fabian
 * 
 * Created on 8. November 2015, 13:42
 */

#include "Sort.h"

Sort::Sort() {}

Sort::~Sort() {}

template <class T>
void Sort::swap( T& a, T& b ){
    
    T temp(a); a = b; b = temp;
}

template <class ForwardIterator1, class ForwardIterator2>
void Sort::iter_swap( ForwardIterator1 a, ForwardIterator2 b ){
    
    swap(*a, *b);
}

template<class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result){
    
    while( first != last) {
        *result = *first;
        ++result; 
        ++first;
    }
    return result;
}