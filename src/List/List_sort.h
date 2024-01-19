/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <cassert>

/**
 * p: the first node of the interval
 * n: the size of the interval
 * 
 * debug: (gdb)b List_sort.h:22
*/
template <typename T> 
void List<T>::sort ( ListNodePosi<T> p, Rank n, int method_id ) { //�б���������
   switch ( method_id ) {
      case 0  : insertionSort( p, n ); break; //��������
      case 1  : selectionSort( p, n ); break; //ѡ������
      case 2  :     mergeSort( p, n ); break; //�鲢����
      case 3  :     radixSort( p, n ); break; //��������
      default :
         assert(0);
   }
}
