/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

//�������б��ڽڵ�p��������trailer����n����ǰ���У��ҵ�������e�������
template <typename T> 
ListNodePosi<T> List<T>::search( T const& e, Rank n, ListNodePosi<T> p ) const {
   for(int count=1; count <= n; ++count) {
      p = p->pred;
      if(p == header) {
         return header;
      }
      if(p->data <= e) {
         return p;
      }
   }
   return p->pred;  //��������ֹͣ��λ��
} //ʧ��ʱ����������߽��ǰ����������header�����������߿ɾݴ��жϲ����Ƿ�ɹ�