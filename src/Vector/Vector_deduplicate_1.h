/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

// template <typename T> 
// int Vector<T>::dedup() { //ɾ�������������ظ�Ԫ�أ������棩
//    int oldSize = _size; //��¼ԭ��ģ
//    int i = -1; //����ǰ�˿�ʼ
//    while ( ++i < _size - 1 ) { //��ǰ�����һ
//       int j = i + 1; //assert: _elem[0, i]�в����ظ�Ԫ��
//       while ( j < _size )
//          if ( _elem[i] == _elem[j] ) remove ( j ); //����ͬ����ɾ������
//          else j++; //������ɨ��
//    }
//    return oldSize - _size; //������ģ�仯��������ɾ��Ԫ������
// }


template <typename T> 
int Vector<T>::dedup() {
   printf("src/Vector/Vector_deduplicate_1.h\n");
   
   Rank oldSize = _size;
   Rank j;
   for(Rank i=0; i < _size; ++i) {
      j = i + 1;
      while (j < _size)
      {
         if(_elem[j] == _elem[i]) {
            remove(j);
         } else {
            ++j;
         }
      }   
   }

   return oldSize - _size;
}