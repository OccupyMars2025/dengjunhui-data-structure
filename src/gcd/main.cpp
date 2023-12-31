/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "_share/util.h"
#include <cassert>

#define ABS(x) ( (0 < (x)) ? (x) : (-(x)) )

int64_t gcdEU_R ( int64_t a, int64_t b );
int64_t gcdEU ( int64_t a, int64_t b );
int64_t gcdCN ( int64_t a, int64_t b );

int64_t gcd ( int64_t a, int64_t b ) {
   switch ( rand() % 3 ) {
      case 0:  return gcdEU_R ( ABS ( a ), ABS ( b ) );
      case 1:  return gcdEU ( ABS ( a ), ABS ( b ) );
      default: return gcdCN ( ABS ( a ), ABS ( b ) );
   }
}

/******************************************************************************************
 * ����GCD
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
// ������
   if ( 3 > argc ) { 
      fprintf ( stderr, "Usage: %s <a> <b>\n", argv[0] ); 
      return 1; 
   }
   srand ( ( unsigned int ) time ( NULL ) );
// ����GCD
   do {
      int64_t a = atol ( argv[1] ), b = atol ( argv[2] );
      int64_t result_1 = gcdCN ( ABS ( a ), ABS ( b ) );
      int64_t result_2 = gcdEU ( ABS ( a ), ABS ( b ) );
      int64_t result_3 = gcdEU_R ( ABS ( a ), ABS ( b ) );
      assert(result_1 == result_2 && result_1 == result_3);

      printf ( "Chinese:   GCD(%ld, %ld) = %ld\n",   a, b,  result_1);
      printf ( "Euclidean: GCD(%ld, %ld) = %ld = %ld\n",   a, b,  result_2, result_3);
      printf ( "Random:    GCD(%ld, %ld) = %ld = %ld\n\n",   a, b, gcd ( a, b ), gcd ( a, b ) );
      argc -= 2; 
      argv += 2;
   } while ( 2 < argc );

// �������GCD
   for ( int i = 0; i < 1000; i++ ) {
      int64_t a = 1, b = 1;
      for ( int k = 0; k < 3; k++ ) { //�������������a��b
         ( rand() & 1 ) ? a *= ( 1 + rand()%100 ) : a += rand()%100;
         ( rand() & 1 ) ? b *= ( 1 + rand()%100 ) : b += rand()%100;
      }
      int64_t result_1 = gcdCN ( ABS ( a ), ABS ( b ) );
      int64_t result_2 = gcdEU ( ABS ( a ), ABS ( b ) );
      int64_t result_3 = gcdEU_R ( ABS ( a ), ABS ( b ) );
      assert(result_1 == result_2 && result_1 == result_3);

      printf ( "Chinese:   GCD(%ld, %ld) = %ld\n",   a, b,  result_1);
      printf ( "Euclidean: GCD(%ld, %ld) = %ld = %ld\n",   a, b,  result_2, result_3);
      printf ( "Random:    GCD(%ld, %ld) = %ld = %ld\n\n",   a, b, gcd ( a, b ), gcd ( a, b ) );
 
   }
   return 0;
}
