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
   if ( _size < 2 ) return; //ƽ�����
   ListNodePosi<T> p; ListNodePosi<T> q;
   for ( p = header, q = p->succ; p != trailer; p = q, q = p->succ )
      p->pred = q; //��ǰ������εߵ����ڵ��ǰ��ָ��
   trailer->pred = NULL; //��������β�ڵ��ǰ��ָ��
   for ( p = header, q = p->pred; p != trailer; p = q, q = p->pred )
      q->succ = p; //��ǰ������εߵ����ڵ�ĺ��ָ��
   header->succ = NULL; //��������ͷ�ڵ�ĺ��ָ��
   swap( header, trailer ); //ͷ��β�ڵ㻥��
}



// template <typename T> 
// void List<T>::reverse() { //ǰ����
//    std::cout << "src/List/List_reverse3.h" << std::endl;

//    if(_size < 2) return;

//    ListNodePosi<T> p1, p2;

//    for(p1 = header, p2 = header->succ; p2 != NULL; p1 = p2, p2 = p2->succ) {
//       p1->pred = p2;
//    }
//    trailer->pred = NULL;
//    for(p1 = header, p2 = p1->pred; p2 != NULL; p1 = p2, p2 = p2->pred) {
//       p2->succ = p1;
//    }
//    header->succ = NULL;
//    swap(header, trailer);
// }