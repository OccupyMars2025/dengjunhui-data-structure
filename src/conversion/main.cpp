/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "conversion/convert.h"

/******************************************************************************************
 * ����ת��
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( (argc < 3) || (argc % 2 != 1)) //�������
   { 
      cout << "Usage: " << argv[0] << " <integer> <base>" << endl; 
      return -1; 
   }

   for ( int i = 1; i < argc; i += 2 ) {
      int64_t n = atol ( argv[i] ); //��ת����ʮ������
      if ( 0 >= n ) //�������
      { 
         cout << "But " << n << " is not a positive integer" << endl;   
         return -2; 
      }

      int base = atoi ( argv[i+1] ); //Ŀ�����
      if ( 2 > base || base > 16 ) //�������
      { 
         cout << "But " << base << " is not between 2 and 16" << endl; 
         return -2; 
      }

      Stack<char> S; //��ջ��¼ת���õ��ĸ���λ
      convert_Iterative ( S, n, base ); //����ת��
      printf ( "%ld_(10) = ", n );
      while ( !S.empty() ) 
         printf ( "%c", ( S.pop() ) ); //�������ջ����λ������ȷ���
      printf ( "_(%d)\n", base ); 
      
      convert_Recursive(S, n, base);
      printf ( "%ld_(10) = ", n );
      while ( !S.empty() ) 
         printf ( "%c", ( S.pop() ) ); //�������ջ����λ������ȷ���
      printf ( "_(%d)\n", base ); 
   }

   return 0;
}