/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// //向量的起泡排序（跳跃版）reduce "hi" by more than 1
// template <typename T> 
// void Vector<T>::bubbleSort_C( Rank lo, Rank hi ) { //assert: 0 <= lo < hi <= size
//    printf("Vector<T>::bubbleSort_C\n");

//    Rank last_swap_index;
   
//    while (hi - lo >= 2)
//    {
//       last_swap_index = lo;
//       for(Rank i = lo + 1; i < hi; ++i) {
//          if(_elem[i-1] > _elem[i]) {
//             swap(_elem[i-1], _elem[i]);
//             last_swap_index = i;
//          }
//       }
//       hi = last_swap_index;
//    }
// }


//向量的起泡排序（跳跃版）reduce "hi" by more than 1
template <typename T> 
void Vector<T>::bubbleSort_C( Rank lo, Rank hi ) {
   // printf("src/Vector/Vector_bubbleSort_C.h  v001\n");

   Rank last_swap_index;
   while (hi - lo >= 2)
   {
      last_swap_index = lo;
      for(Rank i = lo+1; i < hi; ++i) {
         if(_elem[i-1] > _elem[i]) {
            swap(_elem[i-1], _elem[i]);
            last_swap_index = i;
         }
      }
      hi = last_swap_index;
   }
}