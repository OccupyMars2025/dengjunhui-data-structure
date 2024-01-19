/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// //���б�����ʼ��λ��p�����Ϊn����������������
// template <typename T> 
// void List<T>::insertionSort( ListNodePosi<T> p, Rank n ) { // valid(p) && Rank(p) + n <= size
//    printf ( "src/List/List_insertionSort.h \n" );
//    for ( int count = 0; count < n; count++ ) { //��һΪ���ڵ�
//       insertAfter( search( p->data, count, p ), p->data ); //�����ʵ���λ�ò�����
//       p = p->succ; 
//       remove( p->pred ); //ת����һ�ڵ�
//    }
// }


// //���б�����ʼ��λ��p�����Ϊn����������������
// template <typename T> 
// void List<T>::insertionSort( ListNodePosi<T> p, Rank n ) {
//    std::cout << "src/List/List_insertionSort.h v002" << std::endl;
//    if(n < 2) return;

//    ListNodePosi<T> p2, p3;
//    p = p->succ;
//    for(Rank i = 1; i < n; ++i) {
//       p2 = p->succ;
//       p3 = search(p->data, i, p);
//       insertAfter(p3, remove(p));
//       p = p2;
//    }
// }



//���б�����ʼ��λ��p�����Ϊn����������������
template <typename T> 
void List<T>::insertionSort( ListNodePosi<T> p, Rank n ) {
   // std::cout << "src/List/List_insertionSort.h v003" << std::endl;
   if(n < 2) return;

   p = p->succ;
   for(Rank i = 1; i < n; ++i) {
      insertAfter(search(p->data, i, p), p->data);
      p = p->succ;

      // using this trick, you need only one pointer variable
      remove(p->pred);
   }
}