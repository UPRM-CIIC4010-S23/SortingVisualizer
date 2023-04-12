# Sorting Viewer

## Dependencies
- [ofxDatGui](https://github.com/braitsch/ofxDatGui)

## Which sorting algorithm should I use?
We have considered numerous sorting algorithms in this lectures, so this question is natural. Knowing which algorithm is best possible depends on various factors such as the size of the input, the range of values to be sorted, the desired time complexity, and the available resources. Here are a few common sorting algorithms and their characteristics:

- Quicksort: It is a divide and conquer algorithm with an average case time complexity of $O(n \log n)$. It is efficient for large inputs and can be implemented with limited extra memory.

- Mergesort: It is also a divide and conquer algorithm with a worst-case time complexity of $O(n \log n)$. It is stable and is useful when sorting linked lists.

- Heapsort: It is an in-place sorting algorithm with a worst-case time complexity of $O(n \log n)$. It is not as fast as Quicksort or Mergesort in most cases, but it has the advantage of not needing extra memory.

- Insertion sort: It is a simple algorithm with a worst-case time complexity of $O(n^2)$. It is efficient for small inputs and is useful when the array is already partially sorted.

The best sorting algorithm for your specific use case will depend on your requirements and constraints.

### Performance characteristics of sorting algorithms

| Algorith        | Stable? | In place? | Order of growth running time | Items extra space |    Notes                                                  |
|-----------------|---------|-----------|------------------------------|-------------------|-----------------------------------------------------------|
|  selection sort | no      | yes       | $N^2$                        | 1                 | depends on order of items                                 |
|  insertion sort | yes     | yes       | between $N$ and $N^2$        | 1                 |                                                           |
|    shellsort    | no      | yes       | $N \log N$ - $N^{6/5}$       | 1                 |                                                           |
|    quicksort    | no      | yes       | $N \log N$                   | $\log N$          | probabilistic guarantee                                   |
| 3-way quicksort | no      | yes       | between $N$ and $N \log N$   | $log N$           | probabilistic, also depends on distribution of input keys |
|    mergesort    | yes     | no        | $N \log N$                   | $N$               |                                                           |
|     heapsort    | no      | yes       | $N \log N$                   | 1                 |                                                           |