/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include "Bitmap/Bitmap.h"
#include <cassert>

Rank primeNLT( Rank low, Rank n, const char* file ) { //����file�ļ��еļ�¼����[low, n)��ȡ��С������
   assert((low >= 0));
   Bitmap B( file, n ); // file�Ѿ���λͼ��ʽ��¼��[0, n)���������������ֻҪ
   while ( low < n ) {//�� low ��ʼ����λ��
      if ( B.test( low ) ) low++; //���ԣ�����
      else return low; //�����׸����ֵ�����
   }
   return -1;
   // return low; //��û������������������n��ʵ���в�����˼򻯴���
}
