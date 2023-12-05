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
void checkOrder ( Vector<T> & V ) { //�ж������Ƿ���������
   int unsorted = 0; //���������
   CheckOrder<T> *visitor = new CheckOrder<T> ( unsorted, V[0] );
   V.traverse ( *visitor ); //���б���
   if ( 0 < unsorted )
      printf ( "Unsorted with %d adjacent inversion(s)\n", unsorted );
   else
      printf ( "Sorted\n" );
}
