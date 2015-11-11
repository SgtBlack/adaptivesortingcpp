/* 
 * File:   Sort.h
 * Author: Fabian Witt
 *
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
    
    template <class InputIterator, class OutputIterator, class Less>
    OutputIterator insertionSort(InputIterator first, InputIterator beyond, OutputIterator result, Less less ){
        
        std::vector<Point_2>::iterator iter;
        for(iter = first; iter != beyond; ++iter) {
            rotate(upperBound(first, iter, *iter, less), iter, iter + 1);
        }
        
        return copy(first, beyond, result);
    }
    

    template <class InputIterator, class OutputIterator, class Less>
    OutputIterator quickSort(InputIterator first, InputIterator beyond, OutputIterator result, Less less ){
        
        quickSort(first, beyond, less);
        
        return copy(first, beyond, result);
    }
    
    template <class RandomAccessIterator, class Less>
    void quickSort(RandomAccessIterator first, RandomAccessIterator beyond, Less less ){
        
        int leftBorder = 1, rightBorder = size(first, beyond);
        
        int leftBorderTmp = 1, rightBorderTmp = size(first, beyond);
        
        std::vector<Point_2>::iterator leftBorderIter = first;
        std::vector<Point_2>::iterator rightBorderIter = beyond - 1;
        
        //select element in the middle
        int i = 1; Point_2 pivot;
        std::vector<Point_2>::iterator iter = first;
        while(i <= (size(first, beyond) / 2)){
            if(i == (size(first, beyond) / 2))
                pivot = *iter;
            iter++; i++;
        }
        
        while( leftBorderTmp <= rightBorderTmp ){
            
            while( less( *leftBorderIter, pivot ) ){
                leftBorderTmp++;
                leftBorderIter++;
            }
            
            while( less( pivot, *rightBorderIter ) ){
                rightBorderTmp--;
                rightBorderIter--;
            }
            
            if( leftBorderTmp <= rightBorderTmp ){
                iter_swap(leftBorderIter, rightBorderIter);
                leftBorderTmp++; leftBorderIter++;
                
                rightBorderTmp--; rightBorderIter--;
            }
            
        }
        
        if( leftBorder < rightBorderTmp )
            quickSort(first, rightBorderIter+1, less );
        
        if( leftBorderTmp < rightBorder )
            quickSort(leftBorderIter, beyond, less );
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