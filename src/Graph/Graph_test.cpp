/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

/******************************************************************************************
 * Test of Graph
 ******************************************************************************************/
#include "Graph_test.h"
#include <cassert>

/******************************************************************************************
 * ������v�����㡢e���߹��ɵ����ͼ
 ******************************************************************************************/
template <typename Tv, typename Te> //�������͡�������
void randomGraph ( GraphMatrix<Tv, Te> & g, Rank n, Rank e ) { //assert: 0 <= e <= n(n-1) 
   assert(n > 0 && e >= 0 && (e <= n*(n-1)));

   while ( ( g.n < n ) || ( g.e < e ) ) { //�������
      if ( g.n < n ) { //����
         if ( dice ( 100 ) < 65 ) { //65%���ʲ��붥��
            Tv vertex = ( Tv ) ( 'A' + dice ( 26 ) );      
            printf ( "Inserting vertex " ); 
            print ( vertex ); 
            printf ( " ..." );
            g.insert ( vertex );               
            printf ( "done\n" );
         } else { //35%����ɾ������
            if ( 1 > g.n ) 
               continue;
            int v = dice ( g.n );       
            printf ( "Removing vertex %d ...", v );
            Tv x = g.remove ( v );        
            printf ( "done with" ); 
            print ( x ); 
            printf ( "\n" );
         }
         print ( g );
      }

      if ( ( 1 < g.n ) && ( g.e < e ) ) { //��
         if ( dice ( 100 ) < 65 ) { //65%���ʲ����
            int v = dice ( g.n ), j = dice ( g.n ); 
            // Don't insert self-loops
            while (j == v)
            {
               j = dice ( g.n );
            }
            
            Te e = dice ( ( Te ) 3 * n );
            printf ( "Inserting edge (%d, %d) = ", v, j ); 
            print ( e ); 
            printf ( " ..." );
            if ( g.exists ( v, j ) ) {
               printf ( "already exists\n" );
            } else {
               g.insert ( e, e, v, j );     
               printf ( "done\n" );
            }
         } else { //35%����ɾ����
            int v = dice ( g.n ), j = dice ( g.n );
            printf ( "Removing edge (%d, %d) ...", v, j );
            if ( g.exists ( v, j ) ) {
               Te e = g.remove ( v, j );  
               printf ( "done with" ); 
               print ( e ); 
               printf ( "\n" );
            } else {
               printf ( "not exists\n" );
            }
         }
         print ( g );
      }
   }

   for ( Rank v = 0; v < n; v++ ) 
      g.vertex ( v ) = 'A' + (Tv) v;
   print ( g );
}

/******************************************************************************************
 * �������У��ļ��ض����е���ͼ
 ******************************************************************************************/
void importGraph ( GraphMatrix<char, int> & g ) {
   int n; scanf ( "%d\n", &n ); printf ( "%d vertices\n", n );
   for ( int v = 0; v < n; v++ ) { //����v������
      char vertex; scanf ( "%c", &vertex );  printf ( "Inserting vertex" ); print ( vertex ); printf ( " ..." );
      g.insert ( vertex );                  printf ( "done\n" ); print ( g );
   }
   for ( int v = 0; v < n; v++ )
      for ( int j = 0; j < n; j++ ) { //�����
         int edge; scanf ( "%d", &edge );
         if ( 0 > edge ) continue;             printf ( "Inserting edge (%d, %d) = ", v, j ); print ( edge ); printf ( " ..." );
         g.insert ( edge, edge, v, j );        printf ( "done\n" );
      }
}

/******************************************************************************************
 * ͼ�ṹ��ͳһ����
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) 
   { 
      printf ( "Usage: %s -random <n> <e> | -import <n> <e> < <path>\a\a\n", argv[0] ); 
      return -1; 
   }
   // -import < ..\..\_input\graph.prim.0009+0028.txt  ..\..\_output\Graph_Matrix\graph.prim.0009+0028.txt
   // -random 67 543 > ..\..\_output\Graph_Matrix\graph.random.0067+0543.txt
   
   srand((unsigned int)time(NULL)); //�������
   //srand( 31415926 ); //�̶����ӣ������ӣ������ã�
   
   GraphMatrix<char, int> g;
   if ( !strcmp ( "-random", argv[1] ) )
      randomGraph<char, int> ( g, atoi ( argv[2] ), atoi ( argv[3] ) ); //�������ַ���ţ���Ϊ����Ȩ��
   else if ( !strcmp ( "-import", argv[1] ) )
      importGraph ( g ); //�������У��ļ��ض����е���ͼ
   else 
      return -1;

   printf ( "\n" ); 
   print ( g );

   printf ( "=== BFS\n" );
   g.bfs ( 0 ); 
   print ( g );

   printf ( "=== BFS (PFS)\n" );
   g.pfs ( 0, BfsPU<char, int>() ); 
   print ( g );

   printf ( "=== DFS\n" );
   g.dfs ( 0 ); 
   print ( g );

   printf ( "=== DFS (PFS)\n" );
   g.pfs ( 0, DfsPU<char, int>() ); 
   print ( g );

   // printf ( "=== Topological sorting\n" );
   // Stack<char>* ts = g.tSort ( 0 );  
   // print ( ts ); 
   // print ( g ); 
   // release ( ts );
   












   // printf ( "=== BCC\n" );
   // g.bcc ( 0 ); print ( g );
   printf ( "=== Prim\n" );
   g.prim ( 0 ); print ( g );
   printf ( "=== Prim (PFS)\n" );
   g.pfs ( 0, PrimPU<char, int>() ); print ( g );
   printf ( "=== Dijkstra\n" );
   g.dijkstra ( 0 ); print ( g );
   printf ( "=== Dijkstra (PFS)\n" );
   g.pfs ( 0, DijkPU<char, int>() ); print ( g );
   return 0;
}