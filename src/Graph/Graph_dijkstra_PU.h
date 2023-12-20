/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> 
struct DijkPU { //���Dijkstra�㷨�Ķ������ȼ�������
   virtual void operator()( Graph<Tv, Te>* g, Rank v, Rank u ) {
      if ( UNDISCOVERED == g->status( u ) ) //����vÿһ��δ�����ֵ��ڽӶ���u����Dijkstra����
         if ( g->priority( u ) > g->priority( v ) + g->weight( v, u ) ) { //���ɳ�
            g->priority( u ) = g->priority( v ) + g->weight( v, u ); //�������ȼ�������
            g->parent( u ) = v; //��ͬʱ���¸��ڵ�
         }
   }
};