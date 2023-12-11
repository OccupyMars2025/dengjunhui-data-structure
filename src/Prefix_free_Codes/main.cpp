/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "PFC_test.h"
#include "UniPrint/print_implementation.h"

int main ( int argc, char* argv[] ) { //PFC���롢�����㷨ͳһ�������
   if ( 2 > argc ) 
   { 
      printf ( "Usage: %s <message#1> [message#2] ...\a\n", argv[0] ); 
      return -1; 
   }
   for(int i=0; i<N_CHAR; ++i) {
      printf("%c ", 0x20 + i);
   }
   printf("\n");

   PFCForest* forest = initForest(); //��ʼ��PFCɭ��
   PFCTree* tree = generateTree ( forest ); 
   release ( forest ); //����PFC������
   print ( tree );

   PFCTable* table = generateTable ( tree ); //��PFC������ת��Ϊ�����
   
   for ( int i = 0; i < N_CHAR; i++ ) 
      printf ( " %c: %s\n", i + 0x20, * ( table->get ( i + 0x20 ) ) ); //��������
   
   for ( int i = 1; i < argc; i++ ) { //���������д����ÿһ���Ĵ�
      printf ("\nEncoding: %s\n", argv[i] ); //��ʼ����
      Bitmap codeString; //�����Ʊ��봮
      int n = encode ( table, codeString, argv[i] ); //�����ݱ�������ɣ�����Ϊn��

      printf ( "%s\n", codeString.bits2string ( n ) ); //�����ǰ�ı��ı��봮
      printf ( "Decoding: " ); //��ʼ����
      decode ( tree, codeString, n ); //���ñ��������Գ���Ϊn�Ķ����Ʊ��봮���루ֱ�������
   }

   release ( table ); 
   release ( tree ); 
   return 0; //�ͷű����������
} //release()�����ͷŸ��ӽṹ�����㷨��ֱ�ӹ�ϵ������ʵ����������