/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "Bitmap/Bitmap.h" //����Bitmap�ṹ
#include <cmath>

// /******************************************************************************************
//  * I still cannot understand this proof
//  * ɸ�����������ҳ�С��n����������
//  * ��ѭ��ÿ�˵���O(n/i)������ѭ����������������n/ln(n)�ˣ��ۼƺ�ʱ����
//  *       n/2 + n/3 + n/5 + n/7 + n/11 + ...
//  *    <  n/2 + n/3 + n/4 + n/6 + n/7 + ... + n/(n/ln(n))
//  *    =  O(n(ln(n/ln(n)) - 1))
//  *    =  O(nln(n) - nln(ln(n)) - 1)
//  *    =  O(nlog(n))
//  * ����ʵ���У���ѭ������㡢��ѭ�����յ㶼���Ż�
//  ******************************************************************************************/
// // #include "_share/util.h"

// void Eratosthenes( Rank n, const char* file ) {
//    Bitmap B( n ); B.set( 0 ); B.set( 1 ); // 0��1����������
//    for ( Rank i = 2; i * i < n; i++ ) //�����
//       if ( !B.test( i ) ) //ȷ����һ������i
//          for ( Rank j = i * i; j < n; j += i ) //����һϵ���ܱ�i������
//             B.set( j ); // j���Ϊ������С��i*i�ĺ��������ڴ�֮ǰ�ѱ���ǣ�
//    B.dump( file ); //��ɸѡ���ͳһ����ָ���ļ����Ա��պ�ֱ�ӵ���
// }



/**
 * https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Algorithmic_complexity
 * https://en.wikipedia.org/wiki/Divergence_of_the_sum_of_the_reciprocals_of_the_primes
 * https://en.wikipedia.org/wiki/Meissel%E2%80%93Mertens_constant
 * 
 * According to wikipedia, it's time complexity is:
 * O(n^0.5) + n/2 + n/3 + n/5 + n/7 + n/11 + ...  = O(n log log n) 
*/
void Eratosthenes ( Rank n, const char* file ) {
   Bitmap bitmap(n);
   bitmap.set(0);
   bitmap.set(1);
   Rank k = 2;
   // for(Rank k = 2; k < n; ++k)
   // for(Rank k = 2; (k * k) < n; ++k)
   for(Rank k = 2; k < ceil(sqrt(n)) + 2; ++k)
   {
      if(!bitmap.test(k)) {
         // for(Rank i = 2 * k; i < n; i += k) {
         for(Rank i = k * k; i < n; i += k) {
            bitmap.set(i);
         }
      }
   }
   // now, "bitmap.test(k) is false" means k is a prime
   // bitmap.print(n);
   bitmap.dump(file);  
}
