/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/
#include "fibonacci/Fib.h"

int64_t fib ( int n ) { //����Fibonacci���еĵ�n����ֵݹ�棩��O(2^n)
   return ( 2 > n ) ?
          ( int64_t ) n //������ݹ����ֱ��ȡֵ
          : fib ( n - 1 ) + fib ( n - 2 ); //���򣬵ݹ����ǰ�����ͼ�Ϊ����
}