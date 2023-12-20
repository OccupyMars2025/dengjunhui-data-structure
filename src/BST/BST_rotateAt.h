/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * BST�ڵ���ת�任ͳһ�㷨��3�ڵ� + 4�����������ص���֮��ֲ��������ڵ��λ��
 * ע�⣺��������������ȷָ���ϲ�ڵ㣨������ڣ�������������������ϲ㺯�����
 ******************************************************************************************/
template <typename T> 
BinNodePosi<T> BST<T>::rotateAt( BinNodePosi<T> v ) { //vΪ�ǿ��ﱲ�ڵ�
   if ( !v ) 
   { 
      printf ( "\a\nFail to rotate a null node\n" ); 
      exit ( -1 ); 
   }

   BinNodePosi<T> p = v->parent; 
   BinNodePosi<T> g = p->parent; //��v��p��g���λ�÷��������
   if ( IsLChild( *p ) ) // zig
      if ( IsLChild( *v ) ) { /* zig-zig */  // printf("\tzIg-zIg: ");
         p->parent = g->parent; //��������
         return connect34( v, p, g, v->lc, v->rc, p->rc, g->rc );
      } else { /* zig-zag */  // printf("\tzIg-zAg: ");
         v->parent = g->parent; //��������
         return connect34( p, v, g, p->lc, v->lc, v->rc, g->rc );
      }
   else // zag
      if ( IsRChild( *v ) ) { /* zag-zag */  // printf("\tzAg-zAg: ");
         p->parent = g->parent; //��������
         return connect34( g, p, v, g->lc, p->lc, v->lc, v->rc );
      } else { /* zag-zig */  //printf("\tzAg-zIg: ");
         v->parent = g->parent; //��������
         return connect34( g, v, p, g->lc, v->lc, v->rc, p->rc );
      }
}