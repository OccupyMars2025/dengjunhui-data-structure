/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/
#pragma once

/**
 * For a sorted vector "v", you can view v[-1] as "-INF", 
 * view v[size] as "+INF"
 * 
*/
template <typename T> //在有序向量的区间[lo, hi)内，确定不大于e的最后一个节点的秩
Rank Vector<T>::search( T const& e, Rank lo, Rank hi, int method_id ) const { // 0 <= lo < hi <= _size
   // switch(rand() % 3) {
   switch(method_id) {
   case 0:
      return binSearch( _elem, e, lo, hi );
      
   case 1:
      return fibSearch( _elem, e, lo, hi );

   case 2:
      return interpolation_search_v002(_elem, e, lo, hi);

   case 3:
      return interpolation_search_v001(_elem, e, lo, hi);   

   default:
      assert(0);
   }
} //等概率地随机使用二分查找、Fibonacci查找
