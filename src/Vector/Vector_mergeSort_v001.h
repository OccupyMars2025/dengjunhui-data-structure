#pragma once

/*
_elem[low, middle) and _elem[middle, high) are both sorted arrays, 
merge these two array into one sorted array _elem[low, high)
*/
template <typename T>
void Vector<T>::merge(Rank low, Rank middle, Rank high) {
   T* a = _elem + low;
   Rank i = 0;

   Rank j = 0, size_b = middle - low;
   T* b = new T[size_b];
   for(Rank i = 0; i < size_b; ++i) {
      b[i] = a[i];
   }

   Rank k = 0, size_c = high - middle;
   T* c = _elem + middle;

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
   
   delete [] b;
}

/**
 * merge sort the array A[low, high)
*/
template <typename T>
void Vector<T>::mergeSort_v001(Rank low, Rank high) {
   // std::cout << "src/Vector/Vector_mergeSort_v001.h  " << std::endl;
   if(high - low < 2) return;

   Rank middle = (low + high) >> 1;
   mergeSort_v001(low, middle);
   mergeSort_v001(middle, high);
   if(_elem[middle - 1] > _elem[middle]) {
      merge(low, middle, high);
   }
}