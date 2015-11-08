/* 
 * File:   Sort.h
 * Author: Fabian
 *
 * Created on 8. November 2015, 13:42
 */

#ifndef SORT_H
#define	SORT_H

#include <iterator>


class Sort {
public:
    Sort();
    virtual ~Sort();
    
    template <class T>
    void swap( T& a, T& b );
    
    template <class ForwardIterator1, class ForwardIterator2>
    void iter_swap ( ForwardIterator1 a, ForwardIterator2 b );
    
    template<class InputIterator, class OutputIterator>
    OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result);

    template <class InputIterator, class OutputIterator, class Less>
    OutputIterator sort(InputIterator first, InputIterator beyond, OutputIterator result, Less less );
    
private:

};

#endif	/* SORT_H */

