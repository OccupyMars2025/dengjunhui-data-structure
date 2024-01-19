/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// //���б�����ʼ��λ��p�����Ϊn��������ѡ������
// template <typename T> 
// void List<T>::selectionSort( ListNodePosi<T> p, Rank n ) { // valid(p) && Rank(p) + n <= size
//    printf ( "selectionSort ...\n" );

//    ListNodePosi<T> head = p->pred, tail = p;
//    for ( Rank i = 0; i < n; i++ ) {
//       tail = tail->succ; 
//       if(tail == nullptr) {
//          printf("List<T>::selectionSort:  error: surpass the trailer\n");
//          exit(1);
//       }
//    }
//    //����������Ϊ(head, tail)

//    while ( 1 < n ) { //�����ٻ�ʣ�����ڵ�֮ǰ���ڴ�����������
//       ListNodePosi<T> max = selectMax ( head->succ, n ); //�ҳ�����ߣ�����ʱ�������ȣ�
//       insertBefore( tail, remove( max )); //����������������ĩβ����Ϊ���������µ���Ԫ�أ�
//       /*DSA*///swap(tail->pred->data, selectMax( head->succ, n )->data );
//       tail = tail->pred; 
//       n--;
//    }
// }



//���б�����ʼ��λ��p�����Ϊn��������ѡ������
template <typename T> 
void List<T>::selectionSort( ListNodePosi<T> p, Rank n ) { // valid(p) && Rank(p) + n <= size
   // std::cout << "src/List/List_selectionSort.h v002" << std::endl;

   while (n > 1)
   {
      ListNodePosi<T> pointer_to_min = selectMin(p, n);
      std::swap(pointer_to_min->data, p->data);
      p = p->succ;
      --n;
   }
}


// template <typename T> 
// void List<T>::selectionSort( ListNodePosi<T> p, Rank n ) { // valid(p) && Rank(p) + n <= size
//    std::cout << "src/List/List_selectionSort.h v003" << std::endl;
   
//    if(n < 2) return;

//    ListNodePosi<T> q = p;
//    for(Rank i = 1; i < n; ++i) {
//       q = q->succ;
//    }
//    while (n > 1)
//    {
//       ListNodePosi<T> pointer_to_max = selectMax(p, n);
//       std::swap(pointer_to_max->data, q->data);
//       q = q->pred;
//       --n;
//    }
// }