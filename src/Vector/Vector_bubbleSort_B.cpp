/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Junhui DENG, deng@tsinghua.edu.cn
* Computer Science & Technology, Tsinghua University
* Copyright (c) 2003-2023. All rights reserved.
******************************************************************************************/

#include "Vector/Vector.h"

template <typename T> //向量的起泡排序（提前终止版）
void Vector<T>::bubbleSort_B( Rank lo, Rank hi ) { //assert: 0 <= lo < hi <= size
   printf("Vector<T>::bubbleSort_B\n");
   
   bool sorted = true; 
   do
   {
      sorted = true;
      for( Rank i = lo+1; i < hi; i++ )
      {
         if ( _elem[i - 1] > _elem[i] ) //若逆序，则
         {
            swap( _elem[i - 1], _elem[i] );
            sorted = false; //交换——因此不能判定已经整体有序
         }      
      }
      --hi;
   } while (false == sorted);
}
