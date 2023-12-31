#include <cstdint>
/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

// int64_t gcdCN ( int64_t a, int64_t b ) { //assert: 0 < min(a, b)
//    int r = 0; //a��b��2^r��ʽ�Ĺ�����
//    while ( ! ( ( a & 1 ) || ( b & 1 ) ) ) { //��a��b����ż��
//       a >>= 1; b >>= 1; r ++; //��ͬʱ��2�����ƣ������ۼ���r
//    } //���£�a��b������һΪż
//    while ( 1 ) {
//       while ( ! ( a & 1 ) ) a >>= 1; //��aż��b�棩�����޳�a����������2
//       while ( ! ( b & 1 ) ) b >>= 1; //��bż��a�棩�����޳�b����������2
//       ( a > b ) ? a = a - b : b = b - a; //��Ϊ��gcd(max(a, b) - min(a, b), min(a, b))
//       if ( 0 == a ) return b << r; //����ƽ�������gcd(0, b) = b
//       if ( 0 == b ) return a << r; //����ƽ�������gcd(a, 0) = a
//    }
// }


int64_t gcdCN ( int64_t a, int64_t b ) {
   int64_t r = 0; // the common divisor 2^r of "a" and "b"
   while ((1 & a == 0) && (1 & b == 0))
   {
      a >>= 1;
      b >>= 1;
      ++r;
   }
   
   while (true)
   {
      while (1 & a == 0)
      {
         a >>= 1;
      }
      while (1 & b == 0)
      {
         b >>= 1;
      }
      if (a > b) {
         a = a - b;
      } else {
         b = b - a;
      }
      if(0 == a) {
         return b << r;
      }
      if(0 == b) {
         return a << r;
      }  
   }  
}