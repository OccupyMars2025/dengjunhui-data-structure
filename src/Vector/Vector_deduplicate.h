/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// template <typename T> 
// Rank Vector<T>::dedup() { //删除无序向量中重复元素（高效版）
//    Rank oldSize = _size; //记录原规模
//    for ( Rank i = 1; i < _size; ) //自前向后逐个考查_elem[1,_size)
//       if ( -1 == find(_elem[i], 0, i) ) //在前缀[0,i)中寻找与[i]雷同者（至多一个），O(i)
//          i++; //若无雷同，则继续考查其后继
//       else
//          remove(i); //否则删除[i]，O(_size-i)
//    return oldSize - _size; //被删除元素总数
// }



// template <typename T> 
// Rank Vector<T>::dedup() {
//    Rank oldSize = _size;

//    for (Rank i = 1; i < _size; )
//    {
//       if(find(_elem[i], 0, i) == -1) {
//          ++i;
//       } else {
//          remove(i);
//       }
//    } 

//    return oldSize - _size;
// }


#include "Bitmap/Bitmap.h"

/*
use Bitmap to record the indices of duplicates,
so I can delete those duplicates just once
*/
template <typename T> 
Rank Vector<T>::dedup() {
   printf("======new dedup()\n");
   Rank oldSize = _size;
   Bitmap bitmap_for_duplicates(_size);
   for(Rank i = 1; i < _size; ++i)
   {
      if(find(_elem[i], 0, i) >= 0) {
         bitmap_for_duplicates.set(i);
      }
   }

   Rank i = 0, j = 0;
   while (j < _size)
   {
      if(bitmap_for_duplicates.test(j) == false) {
         _elem[i] = _elem[j];
         ++i;
      }
      ++j;
   }
   _size = i;   

   return oldSize - _size;

}