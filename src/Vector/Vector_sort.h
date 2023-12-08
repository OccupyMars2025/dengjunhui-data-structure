/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> 
void Vector<T>::sort( Rank lo, Rank hi ) { //向量区间[lo, hi)排序
   /*DSA*/
   // switch ( 5 ) {
   switch ( rand() % 5 ) {
      case 1 : bubbleSort_A( lo, hi ); break; //起泡排序
      case 2 : bubbleSort_B( lo, hi ); break; //起泡排序
      case 3 : bubbleSort_C( lo, hi ); break; //起泡排序
      case 4 : selectionSort( lo, hi ); break; //选择排序（习题）
      default : mergeSort( lo, hi ); break; //归并排序
      // case 6 : heapSort( lo, hi ); break; //堆排序（第12章）
      // case 7 : quickSort( lo, hi ); break; //快速排序（第14章）
      // default : shellSort( lo, hi ); break; //希尔排序（第14章）
   } //随机选择算法以充分测试。实用时可视具体问题的特点灵活确定或扩充
}
