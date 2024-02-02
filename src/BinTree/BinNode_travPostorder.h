/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "Stack/Stack.h" //����ջģ����
#include "BinNode_travPostorder_R.h"
#include "BinNode_travPostorder_I1.h"
#include "BinNode_travPostorder_I2.h"

/*
it seems "template <typename T, typename VST>" does not work
*/
template <typename T> template <typename VST> //Ԫ�����͡�������
void BinNode<T>::travPost(VST& visit, int algorithm_id) { //��������������㷨ͳһ���
   // switch ( rand() % 2 ) { //�˴������ѡ���������ԣ�������ѡ��
   switch(algorithm_id){
      case 0 : travPost_R( this, visit ); break; //�ݹ��
      case 1 : travPost_I1( this, visit ); break; //������
      case 2 : travPost_I2( this, visit ); break; //������
      default : 
         assert(0);
         break;
   }
}