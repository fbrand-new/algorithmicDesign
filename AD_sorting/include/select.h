#ifndef __SELECT__
#define __SELECT__

#include <stdlib.h>

#include "total_order.h"

/**********************************************************************
 * An implementation for the Select algorithm.
 *
 * This function implements the Select algorithm to identify the 
 * position of the i-th value in an array if it was sorted.
 * The algorithm may destroy the original ordering of the array.
 * If the fuction `leq` costs Theta(1), then the execution of this 
 * function takes time Theta(n) where n is the number of elements 
 * in the array.
 *
 * @param A is the array of which the i-th value should be found. 
 *          The original ordering of the array may be destroyed.
 * @param n is the number of element of A.
 * @param i is the index in the sorted array of the value to be found.
 * @param elem_size is the type size in bytes of the elements in A.
 * @param leq is the total order to be satisfied by the sorting.
 **********************************************************************/
unsigned int select_median(void *A, const unsigned int n,
                          const size_t elem_size, 
                          total_order leq);

/**********************************************************************
 * An implementation for the Quick Sort algorithm.
 *
 * This function implements the Quick Sort algorithm to sort an 
 * array of elements whose type is unknown with respect to the total 
 * order implemented by the function `leq`. The resulting permutation 
 * is stored in the input array. The pivot selection is done by using 
 * the function `select` (which takes time O(n)) in order to balance
 * the size of the recursion tree.
 * If the fuction `leq` costs Theta(1), then the execution of this 
 * function takes time \Theta(n \log n) where n is the number of 
 * elements in the array.
 *
 * @param A is the array to be sorted. This array is also used to 
 *          store the output of the function.
 * @param n is the number of element of A.
 * @param elem_size is the type size in bytes of the elements in A.
 * @param leq is the total order to be satisfied by the sorting.
 **********************************************************************/
void quick_sort_select(void *A, const unsigned int n, 
                       const size_t elem_size, 
                       total_order leq);

void quick_sort_select_aux(void *A, const int n, const size_t elem_size, total_order leq, const int l, const int r);
unsigned int select_aux(void *A, const int i, const size_t elem_size, total_order leq, const int l, const int r);
unsigned int naive_select_aux(void *A, const unsigned int i, const size_t elem_size, total_order leq, const unsigned int l, const unsigned int r);
int deterministicPivotPartition(void *A, const size_t elem_size, total_order leq, const int l, const int r, const int p);
int * threeWayPartition(void *A, const size_t elem_size, total_order leq, const int l, const int r, const int p);
int selectPivot(void *A, unsigned const int l, unsigned const int r, const size_t elem_size, total_order leq);
void selectionSortAux(void *A, const unsigned int elem_size, total_order leq, const unsigned int l, const unsigned int r);
#endif // __SELECT__