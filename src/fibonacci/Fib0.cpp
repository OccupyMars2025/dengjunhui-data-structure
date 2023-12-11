/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#include <cstdint>
int64_t fibI ( int n ) { //����Fibonacci���еĵ�n������棩��O(n)
   int64_t f = 1, g = 0; //��ʼ����fib(-1)��fib(0)
   while ( 0 < n-- ) { g += f; f = g - f; } //����ԭʼ���壬ͨ��n�μӷ��ͼ�������fib(n)
   return g; //����
}