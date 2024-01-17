/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "_share/util.h"
#include "Bitmap/Bitmap.h"
#include "Bitmap/Bitmap_v002.h"
#include "Bitmap/Bitmap_v003.h"
#include "Bitmap/Bitmap_v004.h"

/******************************************************************************************
 * ����λͼ
 * n: size of bitmap
 * t: number of round of test
 ******************************************************************************************/
int test_Bitmap( int n, int t ) {
   assert((n > 0) && (t > 0));

   bool* B = new bool[n]; //����λͼ
   Bitmap M ( n ); //��Чλͼ
   while ( t-- > 0 ) { //�ظ�ʹ��λͼ���
      memset ( B, 0, n * sizeof ( bool ) ); //��λ���㣬O(n)
      M.reset(); //�߼����㣬O(1)
      for ( int i = 0; i < 3 * n; i++ ) { //������
         Rank k = dice ( n ); //�����λ����
         if ( dice ( 2 ) ) { //��50%�ĸ��ʲ���
            B[k] = true; M.set ( k );
         } else { //��50%�ĸ������
            B[k] = false; M.clear ( k );
         }
      }
      // M.set( 20 ); //��ʱ�������������Է�����Ա����Գ���
      int k;
      for ( k = 0; k < n; k++ ) //��λ�ضԱ�
         if ( B[k] != M.test ( k ) ) //һ�����ֲ���
            break; //�漴�˳�
      if ( k < n ) { //�����棨assert:: k == n+1��
         printf ( "\n B[]:" );
         for ( int j = 0; j <= k; j++ ) { 
            printf ( "%c", B[j] ? '1' : '0' );
         }
         printf ( "\n M[]:" );
         M.print(k+1);
         printf ( "\n" );
         exit(1);
      }
   }
   delete [] B;
   return 0;
}

/*
Bitmap_v002 doesn't support clear()
*/
int test_Bitmap_v002( int n, int t ) {
   assert((n > 0) && (t > 0));

   Bitmap bitmap(n);
   Bitmap_v002 bitmap_v002( n ); //��Чλͼ
   while ( t-- > 0 ) { //�ظ�ʹ��λͼ���
      bitmap.reset();
      bitmap_v002.reset(); //�߼����㣬O(1)
      for ( int i = 1; i < 4 * n; i++ ) { //������
         Rank k = dice ( i ); //�����λ����
         bitmap.set(k);
         bitmap_v002.set(k);
      }
      // bitmap_v002.set( 19 ); //��ʱ�������������Է�����Ա����Գ���
      int k;
      for ( k = 0; k < 4 * n; k++ ) //��λ�ضԱ�
         if ( bitmap.test(k) != bitmap_v002.test(k) ) //һ�����ֲ���
            break; //�漴�˳�
      if ( k < 4 * n ) { //�����棨assert:: k == n+1��
         printf("the mismatch index: %d\n", k);
         printf ( "\n      bitmap[]:" );
         bitmap.print(k+1);
         printf ( "\n bitmap_v002[]:" );
         bitmap_v002.print(k+1);
         printf ( "\n" );
         exit(1);
      }
   }
   return 0;
}


int test_Bitmap_v003_and_v004( int n, int t ) {
   assert((n > 0) && (t > 0));

   Bitmap bitmap(n);
   Bitmap_v003 bitmap_v003( n ); 
   Bitmap_v004 bitmap_v004( n ); 
   while ( t-- > 0 ) { //�ظ�ʹ��λͼ���
      bitmap.reset();
      bitmap_v003.reset();
      bitmap_v004.reset(); //�߼����㣬O(1)
      for ( int i = 1; i < 4 * n; i++ ) { //������
         Rank k = dice ( i ); //�����λ����
         // std::cout << " set(" << k << ")" << std::endl;
         if(dice(2)) {
            bitmap.set(k);
            // bitmap.print(k+1);
            bitmap_v003.set(k);
            bitmap_v004.set(k);
            // bitmap_v004.print(k+1);
         } else {
            bitmap.clear(k);
            bitmap_v003.clear(k);
            bitmap_v004.clear(k);
         }
      }
      // bitmap_v003.set(28); //��ʱ�������������Է�����Ա����Գ���
      int k;
      for ( k = 0; k < 4 * n; k++ ) //��λ�ضԱ�
         if (!((bitmap.test(k) == bitmap_v003.test(k)) && (bitmap.test(k) == bitmap_v004.test(k)))) //һ�����ֲ���
            break; //�漴�˳�
      if ( k < 4 * n ) { 
         printf("the mismatch index: %d\n", k);
         printf ( "\n      bitmap[]:" );
         bitmap.print(k+1);
         printf ( "\n bitmap_v003[]:" );
         bitmap_v003.print(k+1);
         printf ( "\n bitmap_v004[]:" );
         bitmap_v004.print(k+1);
         printf ( "\n" );
         exit(1);
      }
   }
   return 0;
}


/******************************************************************************************
 * ����λͼ
 ******************************************************************************************/
int main( int argc, char* argv[] ) {
   //  unsigned char c = 1;
   //  std::cout <<  (c & 1) << ", " << (c & 0x80) << std::endl;

   //  uint16_t n = 0x0102;
   //  unsigned char *char_array = (unsigned char*)(&n);
   //  std::cout << (int)char_array[0] << ", " << (int)char_array[1] << std::endl;
   //  return 0;

   // if ( 3 > argc ) { 
   //    printf( "Usage: %s <bitmap size> <#test>\n", argv[0] ); 
   //    return 1; 
   // }
   // srand((unsigned int)time(NULL)); //�������
   // //srand( 31415926 ); //�̶����ӣ������ӣ������ã�
   // return testBitmap(atoi(argv[1]), atoi(argv[2])); //��������
   
   srand((unsigned int)time(NULL)); 
   for(int n = 1; n < 100; ++n) {
      test_Bitmap(n, 100);
      test_Bitmap_v002(n, 100);
      test_Bitmap_v003_and_v004(n, 100);
      std::cout << "n = "<< n << std::endl;
   }
   std::cout << "test ok!" << std::endl;
}