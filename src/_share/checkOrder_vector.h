/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "Vector/Vector.h"

template <typename T> 
void checkOrder ( Vector<T> & V ) { //判断向量是否整体有序
   int unsorted = 0; //逆序计数器
   CheckOrder<T> *visitor = new CheckOrder<T> ( unsorted, V[0] );
   V.traverse ( *visitor ); //进行遍历
   if ( 0 < unsorted )
      printf ( "Unsorted with %d adjacent inversion(s)\n", unsorted );
   else
      printf ( "Sorted\n" );
}
