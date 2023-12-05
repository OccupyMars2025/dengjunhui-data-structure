/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include "Stack/Stack.h" //ջ
#include "queen.h" //����ʺ���

typedef enum {Continuous, Step} RunMode;

extern RunMode runMode; //����ģʽ
extern int nSolu; //�������
extern int nCheck; //���Ե��ܴ���

void placeQueens ( Rank );
void displayRow ( Queen& q, Rank );
void displayProgress ( Stack<Queen>& S, Rank );