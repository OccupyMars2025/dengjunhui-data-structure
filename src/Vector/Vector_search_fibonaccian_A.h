/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once
#include "fibonacci/Fib.h" //����Fib������

//Fibonacci�����㷨���汾A��������������������[lo, hi)�ڲ���Ԫ��e��0 <= lo <= hi <= _size
template <typename T> 
static Rank fibSearch( T* S, T const& e, Rank lo, Rank hi ) {
   printf ( "FIB search (A)\n" );
   //��O(log_phi(n = hi - lo)ʱ�䴴��Fib����
   for ( Fib fib( hi - lo ); lo < hi; ) { //Fib�Ʊ��飻�˺�ÿ��������һ�αȽϡ�������֧
      for ( Rank i = 0; i < lo; i++ ) {
         printf ( "     " ); 
      }
      if ( lo >= 0 ) {
         for ( Rank i = lo; i < hi; i++ ) {
            printf ( "....^" );
         } 
      }
      // printf ( "<<<<|" ); 
      printf ( "\n" );
      
      //key point: make sure (fib(k)-1)+1 <= vector size
      while ( hi - lo < fib.get() ) fib.prev(); //�Ժ���ǰ˳����ң���̯O(1)��
      Rank mi = lo + fib.get() - 1; //ȷ������Fib(k)-1�����
      if      ( e < S[mi] ) hi = mi; //����ǰ���[lo, mi)��������
      else if ( S[mi] < e ) lo = mi + 1; //�������(mi, hi)��������
      else                  return mi; //��mi������
      
      if ( lo >= hi ) { 
         for ( int i = 0; i < mi; i++ ) {
            printf ( "     " );
         } 
         if ( mi >= 0 ) printf ( "....|\n" ); 
         else printf ( "<<<<|\n" ); 
      }
   } //һ���ҵ����漴��ֹ

   return -1; //����ʧ��
} //�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�ʧ��ʱ���򵥵ط���-1��������ָʾʧ�ܵ�λ��


// template <typename T> 
// static Rank fibSearch( T* S, T const& e, Rank lo, Rank hi ) {
//    printf("src/Vector/Vector_search_fibonaccian_A.h  v001\n");

//    Fib fibonacci(hi - lo);

//    while (lo < hi)
//    {
//       while (hi - lo < fibonacci.get())
//       {
//          fibonacci.prev();
//       }
//       Rank middle = lo + fibonacci.get() - 1;
//       if (e < S[middle]) {
//          hi = middle;
//       } else if (S[middle] < e) {
//          lo = middle + 1;
//       } else {
//          return middle;
//       }
//    }
   
//    return -1;
// }