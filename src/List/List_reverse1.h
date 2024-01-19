/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> 
void List<T>::reverse() { //ǰ����
   ListNodePosi<T> p = header; ListNodePosi<T> q = trailer; //ͷ��β�ڵ�
   for ( Rank i = 2; i <= _size; i += 2 ) //�����ס�ĩ�ڵ㿪ʼ��������ڣ�׽�Ե�
      swap( ( p = p->succ )->data, ( q = q->pred )->data ); //�����Գƽڵ��������
}



// template <typename T> 
// void List<T>::reverse() { //ǰ����
//    if(_size < 2) return;

//    for(ListNodePosi<T> p1 = header->succ, p2 = trailer->pred;  p1 != p2; p1 = p1->succ, p2 = p2->pred) {
//       swap(p1->data, p2->data);
//    }
// }