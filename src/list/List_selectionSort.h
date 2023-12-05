/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

//���б�����ʼ��λ��p�����Ϊn��������ѡ������
template <typename T> 
void List<T>::selectionSort( ListNodePosi<T> p, Rank n ) { // valid(p) && Rank(p) + n <= size
   /*DSA*/
   printf ( "selectionSort ...\n" );

   ListNodePosi<T> head = p->pred, tail = p;
   for ( Rank i = 0; i < n; i++ ) {
      tail = tail->succ; 
      if(tail == nullptr) {
         printf("List<T>::selectionSort:  error: surpass the trailer\n");
         exit(1);
      }
   }
   //����������Ϊ(head, tail)

   while ( 1 < n ) { //�����ٻ�ʣ�����ڵ�֮ǰ���ڴ�����������
      ListNodePosi<T> max = selectMax ( head->succ, n ); //�ҳ�����ߣ�����ʱ�������ȣ�
      insert( remove( max ), tail ); //����������������ĩβ����Ϊ���������µ���Ԫ�أ�
      /*DSA*///swap(tail->pred->data, selectMax( head->succ, n )->data );
      tail = tail->pred; 
      n--;
   }
}