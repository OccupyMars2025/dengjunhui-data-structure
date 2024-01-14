/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/
#pragma once

template <typename T> 
void Vector<T>::sort( Rank low, Rank high, int method_id ) { //向量区间[low, high)排序
   switch ( method_id ) {
      /*
      mergeSort_v001: test 5000 times, Elapsed seconds: 74.4
      mergeSort_v002: test 5000 times, Elapsed seconds: 73.5577
      */
      case 0 : mergeSort_v001( low, high ); break; //归并排序
      case 1 : mergeSort_v002( low, high ); break; //归并排序
      case 2 : bubbleSort_A( low, high ); break; //bubble sort
      case 3 : bubbleSort_B( low, high ); break; //bubble sort
      case 4 : bubbleSort_C( low, high ); break; //bubble sort
      case 5 : bubbleSort_D( low, high ); break; //bubble sort
      case 6 : bubbleSort_E( low, high ); break; //bubble sort
      case 7 : selectionSort( low, high ); break; //选择排序（习题）
      // case 6 : heapSort( low, high ); break; //堆排序（第12章）
      // case 7 : quickSort( low, high ); break; //快速排序（第14章）
      // default : shellSort( low, high ); break; //希尔排序（第14章）
      default:
         assert(0);
   } //随机选择算法以充分测试。实用时可视具体问题的特点灵活确定或扩充
}
