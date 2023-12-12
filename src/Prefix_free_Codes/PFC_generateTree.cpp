/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "PFC.h"

PFCTree* generateTree ( PFCForest* forest ) { //����PFC��
   srand ( ( unsigned int ) time ( NULL ) ); //���ｫ���ȡ���ϲ������������������
   while ( 1 < forest->size() ) { //����|forest|-1�κϲ�
      PFCTree* s = new PFCTree; 
      s->insert ( '^' ); //���������������Ϊ"^"��
      
      Rank r1 = rand() % forest->size(); //���ѡȡr1����
      s->attach ( ( *forest ) [r1], s->root() ); //��Ϊ�����������
      forest->remove ( r1 ); //�漴�޳�

      Rank r2 = rand() % forest->size(); //���ѡȡr2����
      s->attach ( s->root(), ( *forest ) [r2] ); //��Ϊ�����������
      forest->remove ( r2 ); //�漴�޳�

      forest->insert ( forest->size(), s ); //�ϲ����PFC������ֲ��PFCɭ��
      printf ( "%c and %c merged\n", s->root()->lc->data, s->root()->rc->data );
   }
   return ( *forest ) [0]; //���ˣ�ɭ�����д�����һ��������ȫ��PFC������
}