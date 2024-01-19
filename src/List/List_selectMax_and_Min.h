/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

//����ʼ��λ��p��n��Ԫ����ѡ�������
// if there are multiple maximum elements, choose that with the largest index,
// so that the selection sort which uses selectMax() is stable 
template <typename T> 
ListNodePosi<T> List<T>::selectMax( ListNodePosi<T> p, Rank n ) {
   ListNodePosi<T> max = p; //������ݶ�Ϊ�׽ڵ�p
   for ( ListNodePosi<T> cur = p; 1 < n; n-- ) //���׽ڵ�p�������������ڵ���һ��max�Ƚ�
   {
      if(cur == trailer || cur->succ == trailer) {
         printf("List<T>::selectMax: error: surpass list bound\n");
         exit(1);
      }
      // Caution: pay attention to the "equality" situation
      if ( !lt( ( cur = cur->succ )->data, max->data ) ) //����ǰԪ�ز�С��max����
         max = cur; //�������Ԫ��λ�ü�¼
   }

   return max; //�������ڵ�λ��
}


//����ʼ��λ��p��n��Ԫ����ѡ����С��
// if there are multiple minimum elements, choose that with the smallest index,
// so that the selection sort which uses selectMin() is stable 
template <typename T> 
ListNodePosi<T> List<T>::selectMin( ListNodePosi<T> p, Rank n ) {
   ListNodePosi<T> pointer_to_min = p;

   for(Rank i = 1; i < n; ++i) {
      p = p->succ;
      // don't use "<="
      if(p->data < pointer_to_min->data) {
         pointer_to_min = p;
      }
   }

   return pointer_to_min;
}