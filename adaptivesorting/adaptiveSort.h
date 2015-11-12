//
//  adaptiveSort.h
//  adaptivesorting
//
//  Created by Fabian Witt on 12.11.15 | KW 46.
//  Copyright (c) 2015 Fabian Witt. All rights reserved.
//

#ifndef adaptivesorting_adaptiveSort_h
#define adaptivesorting_adaptiveSort_h

#include <iterator>
#include <vector>
#include "Point_2.h"

class AdaptiveSort {
public:
    AdaptiveSort(){}
    virtual ~AdaptiveSort(){}
    
    template <class RandomAccessIterator, class Less>
    void insertionSort(RandomAccessIterator first, RandomAccessIterator beyond, Less less ){
        
        for(auto iter = first; iter != beyond; ++iter){
            rotate(upperBound(first, iter, *iter, less), iter, iter + 1);
        }
    }
    
    template <class InputIterator, class OutputIterator, class Less>
    OutputIterator insertionSort(InputIterator first, InputIterator beyond, OutputIterator result, Less less ){
        
        insertionSort(first, beyond, less);
        
        return copy(first, beyond, result);
    }
    
    template <class RandomAccessIterator, class Less>
    void straightInsertionSort(RandomAccessIterator first, RandomAccessIterator beyond, Less less ){
        
        for(auto iter = first; iter != beyond; ++iter){
            
            for(auto iter2 = iter; iter2 != first && less(*iter2, *(iter2-1)); iter2--){
                iter_swap(iter2, iter2-1);
            }
        }
    }
    
    template <class InputIterator, class OutputIterator, class Less>
    OutputIterator straightInsertionSort(InputIterator first, InputIterator beyond, OutputIterator result, Less less ){
        
        straightInsertionSort(first, beyond, less);
        
        return copy(first, beyond, result);
    }

private:
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
    
    //Rotates the order of the elements in the range [first,beyond),
    //in such a way that the element pointed by middle becomes the new first element.
    template <class ForwardIterator>
    void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator beyond)
    {
        ForwardIterator next = middle;
        while (first != next)
        {
            swap(*first++, *next++);
            if(next == beyond){
                next = middle;
            } else if (first == middle){
                middle = next;
            }
        }
    }
    
    // Returns an iterator pointing to the first element in the range [first,beyond) which compares greater than val.
    template <class ForwardIterator, class T, class Less>
    ForwardIterator upperBound(ForwardIterator first, ForwardIterator beyond, const T& val, Less less)
    {
        ForwardIterator it;
        typename std::iterator_traits<ForwardIterator>::difference_type count, step;
        count = std::distance(first, beyond);
        while (count > 0)
        {
            it = first;
            step = count / 2;
            std::advance(it, step);
            
            if( !less(val, *it) ){
                first = ++it;
                count -= step + 1;
            }
            else count = step;
        }
        return first;
    }
};

#endif
