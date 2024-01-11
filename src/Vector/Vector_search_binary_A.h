/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

//���ֲ����㷨���汾A��������������������[lo, hi)�ڲ���Ԫ��e��0 <= lo <= hi <= _size
template <typename T> 
static Rank binSearch( T* S, T const& e, Rank lo, Rank hi ) {
   printf ( "BIN search (A)\n" );
   while ( lo < hi ) { //ÿ����������Ҫ�����αȽ��жϣ���������֧
      for ( int i = 0; i < lo; i++ ) 
         printf ( "     " ); 
      if ( lo >= 0 ) {
         for ( int i = lo; i < hi; i++ ) { 
            printf ( "....^" ); 
         }
      }
      printf ( "\n" );

      Rank mi = ( lo + hi ) >> 1; //���е�Ϊ��㣨�������۰룬��Ч������ֵ��ʾ������һλ��
      if ( e < S[mi] ) {
         hi = mi; //����ǰ���[lo, mi)��������
      } else if ( S[mi] < e ) {
         lo = mi + 1; //�������(mi, hi)��������
      } else {
         return mi; //��mi������
      }

      if ( lo >= hi ) { 
         for ( int i = 0; i < mi; i++ ) {
            printf ( "     " ); 
         }
         if ( mi >= 0 ) {
            printf ( "....|\n" );
         } else {
            printf ( "<<<<|\n" ); 
         }
      }
   } //�ɹ����ҿ�����ǰ��ֹ

   return -1; //����ʧ��
} //�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�����ʧ��ʱ���򵥵ط���-1��������ָʾʧ�ܵ�λ��


// #include <cassert>

// /*
// finiteness: hi-lo is strictly monotonically decreasing
// 1. if "e" is in the array, just return one index "i" such that S[i] = e, but "i" is NOT 
// necessarily the largest 
// 2. if "e" is NOT in the array, just return the index suitable to insert, the return value will be in [0, _size] 
// */
// template <typename T> 
// static Rank binSearch( T* S, T const& e, Rank lo, Rank hi ) {
//    printf("src/Vector/Vector_search_binary_A.h   v001\n");

//    assert(lo < hi);
//    Rank middle;
//    while (lo < hi)
//    {
//       middle = (lo + hi) >> 1;
//       if(e < S[middle]) {
//          hi = middle;
//       } else if(e > S[middle]) {
//          lo = middle + 1;
//       } else {
//          return middle;
//       }
//    }
//    
//    return lo;
// }