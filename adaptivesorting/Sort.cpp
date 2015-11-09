///* 
// * File:   Sort.cpp
// * Author: Fabian
// * 
// * Created on 8. November 2015, 13:42
// */
//
//#include <vector>
//#include "Sort.h"
//
//using namespace std;
//
//Sort::Sort() {}
//
//Sort::~Sort() {}
//
//template <class T>
//void Sort::swap( T& a, T& b ){
//    
//    T temp(a); a = b; b = temp;
//}
//
//template <class ForwardIterator1, class ForwardIterator2>
//void Sort::iter_swap( ForwardIterator1 a, ForwardIterator2 b ){
//    
//    swap(*a, *b);
//}
//
//template<class InputIterator, class OutputIterator>
//OutputIterator Sort::copy(InputIterator first, InputIterator last, OutputIterator result){
//    
//    while( first != last) {
//        *result = *first;
//        ++result; 
//        ++first;
//    }
//    return result;
//}
//
//template <class InputIterator, class OutputIterator, class Less>
//OutputIterator Sort::greedySort(InputIterator first, InputIterator beyond, OutputIterator result, Less less ){
//    //greedySort(first, beyond, less);
//    
//    //result = copy(first, beyond-1, result);
//    
//    return result;
//}
//
//template <class RandomAccessIterator, class Less>
//void Sort::greedySort(RandomAccessIterator first, RandomAccessIterator beyond, Less less ){
//    
//    vector<Point_2> x = copy(first, beyond-1, x);
//    vector<Point_2> xu;
//    vector<Point_2> x1;
//    vector<Point_2> x2;
//    
////    xu.push_back( *(x.begin()) );
////    
////    vector<Point_2>::iterator iter;
////    for(iter = first; iter != beyond; iter++){
////    
////        if( less( *(xu.end()), *iter ) ){
////            xu.push_back( *iter );
////            
////        } else if( x1.size() == x2.size() ){
////            x1.push_back( *iter );
////        } else {
////            x2.push_back( *iter );
////        }
////    }
////    
////    if( xu.size() == x.size() ){
////        return x;
////    } else {
////        x1 = greedySort( x1.begin(), x1.end(), x1, less );
////        x2 = greedySort( x2.begin(), x2.end(), x2, less );
////        
////        xu.assign( x1.begin(), x1.end() );
////        xu.assign( x2.begin(), x2.end() );
////        
////        return xu;
////    }
//    
//}