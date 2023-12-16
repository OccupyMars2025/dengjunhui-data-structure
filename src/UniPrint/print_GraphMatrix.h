/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * 图Graph
 ******************************************************************************************/
template <typename Tv, typename Te> //顶点类型、边类型
void UniPrint::p ( GraphMatrix<Tv, Te>& graph_matrix ) { //引用
   Rank inD = 0; 
   for ( Rank i = 0; i < graph_matrix.n; i++ ) 
      inD += graph_matrix.inDegree ( i );
   Rank outD = 0; 
   for ( Rank i = 0; i < graph_matrix.n; i++ ) 
      outD += graph_matrix.outDegree ( i );
   printf ( "[name]%s  [address]%p  (vertex num:%d, edge num:%d) (total inDegree:%d, total outDegree:%d):\n", 
      typeid ( graph_matrix ).name(), (void*) &graph_matrix, graph_matrix.n, graph_matrix.e, inD, outD
   ); //基本信息
// 标题行
   printf ( "           " ); printf ( "|" );
   for ( Rank i = 0; i < graph_matrix.n; i++ ) 
   { 
      print ( graph_matrix.vertex ( i ) ); 
      printf ( "[" ); 
      print ( graph_matrix.status ( i ) ); 
      printf ( "] " ); 
   }
   printf ( "\n" );
// 标题行（续）
   printf ( "           " ); printf ( "|" );
   for ( Rank i = 0; i < graph_matrix.n; i++ ) 
   { 
      print ( graph_matrix.inDegree ( i ) ); 
      printf ( " " ); 
   }
   printf ( "| dTime fTime parent priority\n" );
// 水平分隔线
   printf ( "-----------+" ); 
   for ( Rank i = 0; i < graph_matrix.n; i++ ) 
      printf ( "------" );
   printf ( "+-----------------------------\n" );
// 逐行输出各顶点
   for ( Rank i = 0; i < graph_matrix.n; i++ ) {
      print ( graph_matrix.vertex ( i ) ); printf ( "[" ); print ( graph_matrix.status ( i ) ); printf ( "] " ); print ( graph_matrix.outDegree ( i ) ); printf ( "|" );
      for ( Rank j = 0; j < graph_matrix.n; j++ ) {
         if ( graph_matrix.exists ( i, j ) ) 
         { 
            print ( graph_matrix.edge ( i, j ) ); 
            print ( graph_matrix.type ( i, j ) ); 
         }
         else 
            printf ( "     ." );
      }
      printf ( "| " ); print ( graph_matrix.dTime ( i ) ); printf ( " " ); print ( graph_matrix.fTime ( i ) );
      printf ( "     " ); 
      if ( -1 == graph_matrix.parent ( i ) ) 
         print ( "^" ); 
      else 
         print ( graph_matrix.vertex ( graph_matrix.parent ( i ) ) );
      printf ( "  " ); 
      if ( INT_MAX > graph_matrix.priority ( i ) ) 
         print ( graph_matrix.priority ( i ) ); 
      else 
         print ( " INF" );
      printf ( "\n" );
   }
   printf ( "\n" );
}