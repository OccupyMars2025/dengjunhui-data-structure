/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

// int shift ( int* A, int n, int s, int k ) { //��A[s]��������kΪ���ѭ�����ƣ�O(n / GCD(n, k))
//    int bak = A[s]; //������ʼԪ��
//    int i = s, j = ( s + k ) % n; //�Ӹ�Ԫ�س���
//    int mov = 0; //�ƶ�����
//    while ( s != j ) { //��kΪ���
//       A[i] = A[j]; //��������kλ
//       i = j; 
//       j = ( j + k ) % n; 
//       mov++;
//    }
//    A[i] = bak; //����ʼԪ��ת���Ӧλ��
//    return mov + 1;
// }

#include <cassert>

int shift(int* A, int length, int start, int interval) {
   interval = interval % length;

   assert(start >= 0 && start < length);

   int move = 0;
   int backup = A[start];
   int i = start;
   int j = (start + interval) % length;
   while (j != start)
   {
      A[i] = A[j];
      ++move;
      i = j;
      j = (j + interval) % length;
   }
   A[i] = backup;

   return move + 1;
}