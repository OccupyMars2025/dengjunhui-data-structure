/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/
#include "power/Power.h"

// int64_t power2_I ( int n ) { //�ݺ���2^n�㷨���Ż������棩��n >= 0
//    int64_t pow = 1; //O(1)���ۻ�����ʼ��Ϊ2^0
//    int64_t p = 2; //O(1)���۳����ʼ��Ϊ2
//    while ( 0 < n ) { //O(logn)������log(n)�֣�ÿ�ֶ�
//       if ( n & 1 ) //O(1)�����ݵ�ǰ����λ�Ƿ�Ϊ1�������Ƿ�
//          pow *= p; //O(1)������ǰ�۳�������ۻ���
//       n >>= 1; //O(1)��ָ������
//       p *= p; //O(1)���۳����Գ�
//    }
//    return pow; //O(1)�������ۻ���
// } //O(logn) = O(r)��rΪ����ָ��n�ı���λ��


// ===========just write it again===========
int64_t power2_I ( int n ) {
   assert(n >= 0);
   int64_t pow = 1;
   int64_t item = 2;

   while (n > 0)
   {
      if(1 & n) {
         pow *= item;
      }
      n >>= 1;
      item *= item;
   }

   return pow; 
}
