/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "BinNode.h" //����������ڵ���

template <typename T> 
class BinTree { //������ģ����
protected:
   Rank _size; BinNodePosi<T> _root; //��ģ�����ڵ�
   virtual Rank updateHeight( BinNodePosi<T> x ); //���½ڵ�x�ĸ߶�
   void updateHeightAbove( BinNodePosi<T> x ); //���½ڵ�x�������ȵĸ߶�
public:
   BinTree() : _size( 0 ), _root( NULL ) {} //���캯��
   ~BinTree() { if ( 0 < _size ) remove( _root ); } //��������
   Rank size() const { return _size; } //��ģ
   bool empty() const { return !_root; } //�п�
   BinNodePosi<T> root() const { return _root; } //����
   BinNodePosi<T> insertAsRoot( T const& ); //������ڵ�
   BinNodePosi<T> insertAsLC( BinNodePosi<T>, T const& ); //��������
   BinNodePosi<T> insertAsRC( BinNodePosi<T>, T const& ); //�����Һ���
   BinNodePosi<T> attachAsLeftSubtree( BinNodePosi<T>, BinTree<T>*& ); //����������
   BinNodePosi<T> attachAsRightSubtree( BinNodePosi<T>, BinTree<T>*& ); //����������
   Rank remove ( BinNodePosi<T> ); //����ɾ��
   BinTree<T>* secede ( BinNodePosi<T> ); //��������
   
   template <typename VST> //������
   void travLevel( VST& visit ) 
   { 
      if ( _root ) _root->travLevel( visit ); 
   } //��α���
   
   template <typename VST> //������
   void travPre( VST& visit, int algorithm_id ) 
   { 
      if ( _root ) _root->travPre( visit, algorithm_id ); 
   } //�������
   
   template <typename VST> //������
   void travIn( VST& visit, int algorithm_id ) 
   { 
      if ( _root ) _root->travIn( visit, algorithm_id ); 
   } //�������
   
   template <typename VST> //������
   void travPost(VST& visit, int algorithm_id) 
   { 
      if ( _root ) _root->travPost( visit, algorithm_id ); 
   } //�������

   template <typename VST> //������
   void traverse ( VST& ); //�Զ������
   bool operator<( BinTree<T> const& t ) //�Ƚ������������в��䣩
      { return _root && t._root && lt( _root, t._root ); }
   bool operator==( BinTree<T> const& t ) //�е���
      { return _root && t._root && ( _root == t._root ); }
}; //BinTree

#include "BinTree_implementation.h"
