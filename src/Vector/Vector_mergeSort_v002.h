#pragma once

#include <cassert>

/*
a[low, middle) and a[middle, high) are both sorted arrays, 
merge these two array into one sorted array a[low, high)
*/
template <typename T>
static void merge_v002(T* array, Rank low, Rank middle, Rank high, T* empty_array) {
   T* a = array + low;
   Rank i = 0;

   Rank j = 0, size_b = middle - low;
   T* b = empty_array;
   for(Rank i = 0; i < size_b; ++i) {
      b[i] = a[i];
   }

   Rank k = 0, size_c = high - middle;
   T* c = array + middle;

   while ((j < size_b) && (k < size_c))
   {
      if(b[j] <= c[k]) {
         a[i++] = b[j++];
      } else {
         a[i++] = c[k++];
      }
   }

   while (j < size_b)
   {
      a[i++] = b[j++];
   }   
}

/**
 * merge sort the array A[low, high)
*/
template <typename T>
static void merge_sort_v002_internal(T* a, Rank low, Rank high, T* empty_array) {
   if(high - low < 2) return;

   Rank middle = (low + high) >> 1;
   merge_sort_v002_internal(a, low, middle, empty_array);
   merge_sort_v002_internal(a, middle, high, empty_array);
   if(a[middle - 1] > a[middle]) {
      merge_v002(a, low, middle, high, empty_array);
   }
}


template <typename T>
void Vector<T>::mergeSort_v002(Rank low, Rank high) {
   // std::cout << "src/Vector/Vector_mergeSort_v002.h" << std::endl;

   assert(low < high);

   Rank allocated_size = ((high - low) >> 1) + 5; 
   T* empty_array = new T[allocated_size];

   merge_sort_v002_internal(_elem, low, high, empty_array);

   delete [] empty_array;
}