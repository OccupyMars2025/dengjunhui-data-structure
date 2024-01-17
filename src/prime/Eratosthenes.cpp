/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "Bitmap/Bitmap.h" //引入Bitmap结构
#include <cmath>

// /******************************************************************************************
//  * I still cannot understand this proof
//  * 筛法求素数：找出小于n的所有素数
//  * 内循环每趟迭代O(n/i)步，外循环由素数定理至多n/ln(n)趟，累计耗时不过
//  *       n/2 + n/3 + n/5 + n/7 + n/11 + ...
//  *    <  n/2 + n/3 + n/4 + n/6 + n/7 + ... + n/(n/ln(n))
//  *    =  O(n(ln(n/ln(n)) - 1))
//  *    =  O(nln(n) - nln(ln(n)) - 1)
//  *    =  O(nlog(n))
//  * 如下实现中，内循环的起点、外循环的终点都了优化
//  ******************************************************************************************/
// // #include "_share/util.h"

// void Eratosthenes( Rank n, const char* file ) {
//    Bitmap B( n ); B.set( 0 ); B.set( 1 ); // 0和1都不是素数
//    for ( Rank i = 2; i * i < n; i++ ) //逐个地
//       if ( !B.test( i ) ) //确认下一个素数i
//          for ( Rank j = i * i; j < n; j += i ) //并将一系列能被i整除的
//             B.set( j ); // j标记为合数（小于i*i的合数，必在此之前已被标记）
//    B.dump( file ); //将筛选标记统一存入指定文件，以便日后直接导入
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
