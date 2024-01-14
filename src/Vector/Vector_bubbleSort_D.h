/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

/*
reverse the scanning order: from right to left
increase "low" by more than 1
*/
template <typename T> 
void Vector<T>::bubbleSort_D( Rank low, Rank high ) {
   // std::cout << "src/Vector/Vector_bubbleSort_D.h " << std::endl;

   Rank leftmost_swap_index;
   while (low < high)
   {
      leftmost_swap_index = high;
      for(Rank i = high - 1; i > low; --i) {
         if(_elem[i-1] > _elem[i]) {
            swap(_elem[i-1], _elem[i]);
            leftmost_swap_index = i;
         }
      }
      low = leftmost_swap_index;
   }
}