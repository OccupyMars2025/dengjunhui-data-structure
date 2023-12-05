/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

/**
 * p: the first node of the interval
 * n: the size of the interval
 * 
 * debug: (gdb)b List_sort.h:22
*/
template <typename T> 
void List<T>::sort ( ListNodePosi<T> p, Rank n ) { //�б���������
   /*DSA*/
   // switch ( 3 ) {
   switch ( rand() % 4 ) { //���ѡȡ�����㷨���ɸ��ݾ���������ص����ѡȡ������
      case 1  : insertionSort( p, n ); break; //��������
      case 2  : selectionSort( p, n ); break; //ѡ������
      case 3  :     mergeSort( p, n ); break; //�鲢����
      default :     radixSort( p, n ); break; //��������
   }
}
// 10, 11, 0
