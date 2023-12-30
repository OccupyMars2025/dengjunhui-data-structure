/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include<ctime>
#include<iostream>
using namespace std;

#include "fibonacci/Fib.h"


int main ( int argc, char* argv[] ) { //测试FIB
// 检查参数
   if ( 2 > argc ) { 
      fprintf ( stderr, "Usage: %s <Rank>\n", argv[0] ); 
      return 1; 
   }
   int n = atoi ( argv[1] );
   assert(n > 0);

// 依次计算Fibonacci数列各项
   printf ( "\n------------- class Fib -------------\n" );
   Fib f ( 0 );
   for ( int i = 0; i < n; i++, f.next() )
      printf ( "fib(%2d) = %d\n", i, f.get() );
   for ( int i = 0; i <= n; i++, f.prev() )
      printf ( "fib(%2d) = %d\n", n - i, f.get() );

   printf ( "\n------------- Iteration -------------\n" );
   for ( int i = 0; i <= n; i++ )
      printf ( "fib(%2d) = %ld\n", i, fibI ( i ) );

   printf ( "\n------------- Linear Recursion -------------\n" );
   for ( int i = 0; i <= n; i++ ) {
      int64_t f;
      printf ( "fib(%2d) = %ld\n", i, fib ( i, f ) );
   }

   printf ( "\n------------- Binary Recursion -------------\n" );
   for ( int i = 0; i <= n; i++ )
      printf ( "fib(%2d) = %ld\n", i, fib ( i ) );
   return 0;
}
