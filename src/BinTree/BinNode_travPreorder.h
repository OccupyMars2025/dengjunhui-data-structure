/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/#include "Stack/Stack.h" //����ջģ����
/*DSA*/#include "BinNode_travPreorder_R.h"
/*DSA*/#include "BinNode_travPreorder_I1.h"
/*DSA*/#include "BinNode_travPreorder_I2.h"

template <typename T> template <typename VST> //Ԫ�����͡�������
void BinNode <T>::travPre( VST& visit ) { //��������������㷨ͳһ���
   switch ( rand() % 3 ) { //�˴������ѡ���������ԣ�������ѡ��
   // switch(2){
      case 1 : travPre_I1( this, visit ); break; //������#1
      case 2 : travPre_I2( this, visit ); break; //������#2
      default : travPre_R( this, visit ); break; //�ݹ��
   }
}