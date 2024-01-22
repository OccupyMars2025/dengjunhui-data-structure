/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "rpn.h"

char* removeSpace ( char* s ) { //�޳�s[]�еİ׿ո�
   // the condition: check (*p) has been assigned '\0'
   for ( char *p = s-1, *q = s; (p < s) || *p; ++q) {
      // isspace('\0') is 0
      while ( isspace( *q ) ) q++;
      *++p = *q;
   }

   // // the condition: check if q has reached '\0'
   // char *p = s;
   // for(char *q = s; *q ; ++q) {
   //    while (isspace(*q))
   //    {
   //       ++q;
   //    }
   //    *p++ = *q;
   // }
   // *p = '\0';

   return s;
}

//���ʽ��ֵ����ڣ�
int main ( int argc, char* argv[] ) { 
   if (argc < 2) {
      printf("Error: usage: %s \"<arithmetic-expression1>\" \"<arithmetic-expression1>\" ...\n", argv[0]);
      return 1;
   }
   for ( int i = 1; i < argc; i++ ) { //��һ����������в��������ʽ��
      // system ( "clear" ); 
      printf ( "\nPress Enter key to evaluate: %s\n", argv[i] ); 
      getchar();
      char* rpn = new char[10 + strlen( argv[i] ) * 4];   
      // put '\0' at the beginning as some kind of sentinel, a special operator
      rpn[0] = '\0'; //�沨�����ʽ��4��ԭ������ͨ�����������
      double value = evaluate ( removeSpace ( argv[i] ), rpn ); //��ֵ
      printf ( "EXPR\t: %s\n", argv[i] ); //���ԭ���ʽ
      printf ( "RPN\t: [ %s]\n", rpn ); //���RPN
      printf ( "Value\t= %f = %d\n\n", value, ( int ) round(value) ); //������ʽ��ֵ
      delete [] rpn;
   }
   return 0;
}
