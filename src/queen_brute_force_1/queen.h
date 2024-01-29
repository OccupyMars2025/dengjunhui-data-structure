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
#include <cstring>

/*
workaround: just include this header to remove some 
"Stack not declared in this scope" errors
*/
#include "UniPrint/print.h"


#include "Stack/Stack.h"

#define QUEEN_MAX 20

typedef enum {Continuous, Step} RunMode;

// these 3 variables are declared in main.cpp
extern RunMode runMode; //����ģʽ
extern int nSolu; //�������
extern int nCheck; //���Ե��ܴ���

void place5Queens_BruteForce();
void displaySolution ( int* solu, int n );
bool collide ( int* solu, int k );

void placeQueens ( int n, int k );

void place2Queens();
void place3Queens();
void place4Queens();
void place5Queens();