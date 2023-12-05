/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once


// ============== start: To be deleted later ==================


template <typename T> static bool lt( T* a, T* b ) { return lt( *a, *b ); } // less than
template <typename T> static bool lt( T& a, T& b ) { return a < b; } // less than
template <typename T> static bool eq( T* a, T* b ) { return eq( *a, *b ); } // equal
template <typename T> static bool eq( T& a, T& b ) { return a == b; } // equal


// ============== end: To be deleted later ==================


//����ʼ��λ��p��n��Ԫ����ѡ�������
template <typename T> 
ListNodePosi<T> List<T>::selectMax( ListNodePosi<T> p, Rank n ) {
   ListNodePosi<T> max = p; //������ݶ�Ϊ�׽ڵ�p
   for ( ListNodePosi<T> cur = p; 1 < n; n-- ) //���׽ڵ�p�������������ڵ���һ��max�Ƚ�
   {
      if(cur == trailer || cur->succ == trailer) {
         printf("List<T>::selectMax: error: surpass list bound\n");
         exit(1);
      }
      if ( !lt( ( cur = cur->succ )->data, max->data ) ) //����ǰԪ�ز�С��max����
         max = cur; //�������Ԫ��λ�ü�¼
   }

   return max; //�������ڵ�λ��
}