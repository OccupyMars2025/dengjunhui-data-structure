/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "rpn.h"

char* removeSpace ( char* s ) { //�޳�s[]�еİ׿ո�
   for ( char *p = s-1, *q = s; (p < s) || *p; ++q) {
      while ( isspace( *q ) ) q++;
      *++p = *q;
   }
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
      rpn[0] = '\0'; //�沨�����ʽ��4��ԭ������ͨ�����������

      double value = evaluate ( removeSpace ( argv[i] ), rpn ); //��ֵ
      printf ( "EXPR\t: %s\n", argv[i] ); //���ԭ���ʽ
      printf ( "RPN\t: [ %s]\n", rpn ); //���RPN
      printf ( "Value\t= %f = %d\n\n", value, ( int ) round(value) ); //������ʽ��ֵ
      delete rpn;
   }
   return 0;
}
