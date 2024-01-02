/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "UniPrint/print_int_array.h"
#include "shiftK/shift.h"

// int shift ( int* A, int n, int s, int t ); //��A[s]��������tΪ���ѭ�����ƣ�O(3n)

// int shift0 ( int* A, int n, int k ) { //�����ؽ�����ѭ������kλ��O(nk)
//    if ( k < 1 ) return 0; 
//    int mov = 0;
//    while ( k-- ) { //������1Ϊ���ѭ�����ƣ�������k��
//       mov += shift ( A, n, 0, 1 );                                       
//       printf ( "== move *%3d\n", mov ); 
//       print ( A, n );
//    }
//    return mov;
// }

int shift0(int* A, int n, int k) {
   if(k < 1) {
      return 0;
   }
   int move = 0;
   while (k--)
   {
      move += shift(A, n, 0, 1);
      printf("==move %d\n", move);
      print(A, n);
   }
   
   return move;
}