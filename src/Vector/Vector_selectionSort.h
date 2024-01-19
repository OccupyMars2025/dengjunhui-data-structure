/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/
#pragma once


//����ѡ������ [lo, hi)
template <typename T> 
void Vector<T>::selectionSort( Rank lo, Rank hi ) { // 0 <= lo < hi <= size
   printf( "Vector<T>::selectionSort  [%3d, %3d)\n", lo, hi );
   while ( lo + 1 < hi ) {
      swap( _elem[maxItem( lo, hi )], _elem[hi-1] ); //��[hi]��[lo, hi]�е�����߽���
      --hi;
   }
}

template <typename T> 
Rank Vector<T>::maxItem( Rank lo, Rank hi ) { //��[lo, hi)���ҳ������
   Rank mx = --hi;
   while ( lo <= hi ) //����ɨ��
   {
     if ( _elem[hi] > _elem[mx] ) //���ϸ�Ƚ�
     {
         mx = hi; //������max�ж��ʱ��֤�������ȣ�������֤selectionSort�ȶ�      
     }
     --hi;
   }
   return mx;
}
