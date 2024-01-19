/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// //列表的归并排序算法：对起始于位置p的n个元素排序
// // Caution: the argument is "ListNodePosi<T>& p", NOT "ListNodePosi<T> p"
// // After calling mergeSort(), the argument that is passed to "ListNodePosi<T>& p" will
// // still point to the first node of the sorted interval
// template <typename T> 
// void List<T>::mergeSort( ListNodePosi<T>& p, Rank n ) { // valid(p) && Rank(p) + n <= size
//    printf ( "\tmergeSort [%3d]\n", n );
   
//    if ( n < 2 ) return; //若待排序范围已足够小，则直接返回；否则...
//    Rank m = n >> 1; //以中点为界
//    ListNodePosi<T> q = p; 
//    for ( Rank i = 0; i < m; i++ ) 
//       q = q->succ; //找到后子列表起点

//    mergeSort( p, m ); mergeSort( q, n - m ); //前、后子列表各分别排序
//    p = merge( p, m, *this, q, n - m ); //归并
// } //注意：排序后，p依然指向归并后区间的（新）起点






template <typename T> 
void List<T>::mergeSort( ListNodePosi<T>& p, Rank n ) {
   // std::cout << "src/List/List_mergeSort.h  v002   mergeSort(" << n << ")" << std::endl;
   if(n < 2) return;

   ListNodePosi<T> middle = p;
   for(Rank i = 0; i < (n >> 1); ++i) {
      middle = middle->succ;
   }
   mergeSort(p, (n >> 1));
   mergeSort(middle, (n - (n >> 1)));
   /*
   we need to use "p" and "middle" again in merge(), but 
   after the above 2 mergeSort(), the nodes pointed to by "p" and "middle" 
   may not be in the original logical indices of the list, so 
   we need to use "reference" to change the value of "p" and "middle" in the above 2 mergeSort()
   */
   merge_002(p, (n >> 1), middle, (n - (n >> 1)));
   /*
   After merge_002() , we should keep "p" points to the first node of the merged list
   */
}