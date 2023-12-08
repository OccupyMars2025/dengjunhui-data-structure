/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> 
void Vector<T>::sort( Rank lo, Rank hi ) { //��������[lo, hi)����
   /*DSA*/
   // switch ( 5 ) {
   switch ( rand() % 5 ) {
      case 1 : bubbleSort_A( lo, hi ); break; //��������
      case 2 : bubbleSort_B( lo, hi ); break; //��������
      case 3 : bubbleSort_C( lo, hi ); break; //��������
      case 4 : selectionSort( lo, hi ); break; //ѡ������ϰ�⣩
      default : mergeSort( lo, hi ); break; //�鲢����
      // case 6 : heapSort( lo, hi ); break; //�����򣨵�12�£�
      // case 7 : quickSort( lo, hi ); break; //�������򣨵�14�£�
      // default : shellSort( lo, hi ); break; //ϣ�����򣨵�14�£�
   } //���ѡ���㷨�Գ�ֲ��ԡ�ʵ��ʱ���Ӿ���������ص����ȷ��������
}
