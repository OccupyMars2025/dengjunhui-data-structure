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
//二分查找算法（版本B）：在有序向量的区间[lo, hi)内查找元素e，0 <= lo < hi <= _size
template <typename T> 
static Rank binSearch( T* S, T const& e, Rank lo, Rank hi ) {
   printf ( "BIN search (B)\n" );
   while ( 1 < hi - lo ) { //每步迭代仅需做一次比较判断，有两个分支；成功查找不能提前终止
      for ( int i = 0; i < lo; i++ ) {
         printf ( "     " ); 
      }
      if ( lo >= 0 ) {
         for ( int i = lo; i < hi; i++ ) {
            printf ( "....^" );
         } 
      }
      printf ( "\n" );

      Rank mi = ( lo + hi ) >> 1; //以中点为轴点（区间宽度折半，等效于其数值表示的右移一位）
      ( e < S[mi] ) ? hi = mi : lo = mi; //经比较后确定深入[lo, mi)或[mi, hi)
   } //出口时hi = lo + 1，查找区间仅含一个元素A[lo]
    //for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" );
   return e < S[lo] ? lo - 1 : lo; //返回位置，总是不超过e的最大者
} //有多个命中元素时，返回秩最大者；





// #include <cassert>

// /*
// 1. if found, return the largest possible index
// 2. if not found, return the index where you can insert "e" after which the vector is still sorted
// */
// template <typename T> 
// static Rank binSearch( T* S, T const& e, Rank lo, Rank hi ) {
//    printf("src/Vector/Vector_search_binary_B.h   v001\n");

//    assert(lo < hi);
//    Rank middle;
//    while (hi - lo > 1)
//    {
//       middle = (lo + hi) >> 1;
//       if(e < S[middle]) {
//          hi = middle;
//       } else {
//          lo = middle;
//       }
//    }
//    // now hi - lo = 1
//    if(S[lo] < e) {
//       return lo + 1;
//    } else {
//       return lo;
//    }
// }