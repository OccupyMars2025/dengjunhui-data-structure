/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// //对列表中起始于位置p、宽度为n的区间做选择排序
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
//    //待排序区间为(head, tail)

//    while ( 1 < n ) { //在至少还剩两个节点之前，在待排序区间内
//       ListNodePosi<T> max = selectMax ( head->succ, n ); //找出最大者（歧义时后者优先）
//       insertBefore( tail, remove( max )); //将其移至无序区间末尾（作为有序区间新的首元素）
//       /*DSA*///swap(tail->pred->data, selectMax( head->succ, n )->data );
//       tail = tail->pred; 
//       n--;
//    }
// }



//对列表中起始于位置p、宽度为n的区间做选择排序
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