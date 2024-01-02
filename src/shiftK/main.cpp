/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include <iostream>
#include <cassert>

#include "UniPrint/print_int_array.h"
#include "shiftK/shift.h"


int main ( int argc, char* argv[] ) {
   if ( argc < 3 ) { 
      printf ( "Usage: %s <array_length> <shift>\n", argv[0] ); 
      return 1;
   }
   int n = atoi ( argv[1] );   
   assert(n > 0);
   int k = atoi ( argv[2] );   
   assert(k > 0);
   printf ( "Shift A[%d] with k = %d ...\n", n, k );
   
   int* A = ( int* ) malloc ( sizeof ( int ) * n );

   printf ( "\n== shift algorithm #0 ========\n" );
   for ( int i = 0; i < n; i++ ) 
      A[i] = i; 
   print ( A, n );
   printf ( "== move *%3d\n", shift0 ( A, n, k ) ); 
   print ( A, n ); 
   printf ( "\n" );

   printf ( "\n== shift algorithm #1 ========\n" );
   for ( int i = 0; i < n; i++ ) 
      A[i] = i; 
   print ( A, n );
   printf ( "== move *%3d\n", shift1 ( A, n, k ) ); 
   print ( A, n ); 
   printf ( "\n" );

   printf ( "\n== shift algorithm #2 ========\n" );
   for ( int i = 0; i < n; i++ ) 
      A[i] = i; 
   print ( A, n );
   printf ( "== move *%3d\n", shift2 ( A, n, k ) ); 
   print ( A, n ); 
   printf ( "\n" );

   free ( A );
   
   return 0;
}