/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// template <typename T> 
// Rank List<T>::uniquify() { //�����޳��ظ�Ԫ�أ�Ч�ʸ���
//    if ( _size < 2 ) return 0; //ƽ���б���Ȼ���ظ�
//    Rank oldSize = _size; //��¼ԭ��ģ
//    ListNodePosi<T> p = first(); ListNodePosi<T> q; //pΪ��������㣬qΪ����
//    while ( trailer != ( q = p->succ ) ) //����������ڵĽڵ��(p, q)
//       if ( p->data != q->data ) p = q; //�����죬��ת����һ����
//       else remove( q ); //������ͬ��ֱ��ɾ�����ߣ�����������������ӵ����ɾ��
//    return oldSize - _size; //�б��ģ�仯��������ɾ��Ԫ������
// }



// // the p3 is not necessary
// template <typename T> 
// Rank List<T>::uniquify() { 
//    if(_size < 2) return 0;

//    Rank old_size = _size;
//    ListNodePosi<T> p1 = header->succ, p2 = p1->succ, p3; 
//    while(p2 != trailer) {
//       if(p1->data == p2->data) {
//          p3 = p2->succ;
//          remove(p2);
//          p2 = p3;
//       } else {
//          p1 = p2;
//          p2 = p2->succ;
//       }
//    }

//    return old_size - _size;
// }


template <typename T> 
Rank List<T>::uniquify() {
   // std::cout << "src/List/List_uniquify.h " << std::endl;
   if(_size < 2) return 0;

   Rank old_size = _size;

   ListNodePosi<T> p1 = header->succ, p2 = p1->succ;
   while (p2 != trailer)
   {
      if(p1->data == p2->data) {
         remove(p2);
      } else {
         p1 = p2;
      }
      p2 = p1->succ;
   }
   
   return old_size - _size;
}