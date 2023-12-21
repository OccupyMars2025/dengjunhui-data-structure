/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> bool RedBlack<T>::remove( const T& e ) { //�Ӻ������ɾ���ؼ���e
   BinNodePosi<T>& x = this->search( e ); if ( !x ) return false; //ȷ��Ŀ����ڣ�����this->_hot�����ã�
   BinNodePosi<T> r = removeAt( x, this->_hot ); if ( !( --this->_size ) ) return true; //ʵʩɾ��
// assert: this->_hotĳһ���Ӹձ�ɾ�����ұ�r��ָ�ڵ㣨������NULL�����档���¼���Ƿ�ʧ�⣬������Ҫ����
   if ( !this->_hot ) //���ձ�ɾ�����Ǹ��ڵ㣬�����úڣ������ºڸ߶�
      { this->_root->color = RB_BLACK; this->updateHeight( this->_root ); return true; }
// assert: ���£�ԭx����r���طǸ���this->_hot�طǿ�
   if ( BlackHeightUpdated( *this->_hot ) ) return true; //���������ȵĺ������Ȼƽ�⣬���������
   if ( IsRed( r ) ) //������rΪ�죬��ֻ������ת��
      { r->color = RB_BLACK; r->height++; return true; }
// assert: ���£�ԭx����r����Ϊ��ɫ
   /*DSA*///printBinTree(this->_hot, 0, 0);
   solveDoubleBlack( r ); return true; //��˫�ڵ����󷵻�
} //��Ŀ��ڵ�����ұ�ɾ��������true�����򷵻�false
