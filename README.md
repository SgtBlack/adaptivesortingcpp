# adaptivesortingcpp
Adaptive Sorting Algorithm in C++

# Insertion Sort

- Best case performance: 
 - already sorted input
 - linear running time (i.e., O(n))
 
- Worst case performance:
 - input is an array sorted in reverse order
 - quadratic running time (i.e., O(n^2))

- insertion sort is one of the fastest algorithms for sorting very small arrays
- even faster than quicksort

![Insertion Sort example](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

# Merge sort

- Best case performance: 
 - O(n log n) typical
 - O(n) natural variant
 
- Worst case performance: 
 - O(n log n)

- Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).
- Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.


![Merge sort example](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)


# references
- [Insertion Sort](http://cforbeginners.com/insertionsort.html)
- [Insertion Sort (Wikipedia)](https://en.wikipedia.org/wiki/Insertion_sort)
- [Merge Sort (Wikipedia)](https://en.wikipedia.org/wiki/Merge_sort)
- [C++ Language](http://www.cplusplus.com/doc/tutorial/)
- [Adaptive sort](https://en.wikipedia.org/wiki/Adaptive_sort)
