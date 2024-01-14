/******************************************************************************************
* Data Structures in C++
* ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
* Junhui DENG, deng@tsinghua.edu.cn
* Computer Science & Technology, Tsinghua University
* Copyright (c) 2003-2023. All rights reserved.
******************************************************************************************/

#pragma once

template <typename T> //�������������򣨻����棩
void Vector<T>::bubbleSort_A( Rank lo, Rank hi ) { //assert: 0 <= lo < hi <= size
   // printf("Vector<T>::bubbleSort_A\n");
   while( lo < --hi ) //��������ɨ��
      for( Rank i = lo; i < hi; i++ ) //����������Ԫ��
         if( _elem[i] > _elem[i + 1] ) //��������
            swap( _elem[i], _elem[i + 1] ); //������ʹ�ֲ�����
}


// template <typename T> 
// void Vector<T>::bubbleSort_A( Rank lo, Rank hi ) {
//    printf("src/Vector/Vector_bubbleSort_A.h v001\n");
//    bool sorted;
//    while (lo < --hi)
//    {
//       sorted = true;
//       for(int i = lo; i < hi; ++i) {
//          if(_elem[i] > _elem[i+1]) {
//             swap(_elem[i], _elem[i+1]);
//             sorted = false;
//          }
//       }
//       if(sorted) break;
//    }
// }