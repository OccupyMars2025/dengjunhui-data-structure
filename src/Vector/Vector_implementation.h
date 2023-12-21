/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * ��vector��������ʵ�ֲ��֣���������vector.h
 * Ч����ͬ�ڽ���Щʵ��ֱ�ӻ���vector.h
 * ��export��δ��������֧��ǰ����˿ɽ�������ʵ�ַ��룬�Ա�γ̽���
 ******************************************************************************************/
#include "_share/release.h"
#include "_share/util.h"

#include "Vector/permute.h"

#include "Vector_bracket.h"
#include "Vector_assignment.h"

#include "Vector_constructor_by_copying.h"

#include "Vector_expand.h"
#include "Vector_shrink.h"

#include "Vector_insert.h"
#include "Vector_remove.h"
#include "Vector_removeInterval.h"

#include "Vector_find.h"
#include "Vector_search_binary_C.h" //��A��B��C���ְ汾��C������
//#include "Vector_search_fibonaccian_A.h" //ʵ�ð棨������ֵ�д���ӿ�ͳһ��
#include "Vector_search_fibonaccian_B.h" //������
#include "Vector_search.h"

#include "Vector_traverse.h"

#include "Vector_unsort.h"
#include "Vector_sort.h"
#include "Vector_bubbleSort_A.h"
#include "Vector_bubbleSort_B.h"
#include "Vector_bubbleSort_C.h"
#include "Vector_selectionSort.h"
#include "Vector_merge.h"
#include "Vector_mergeSort.h"
#include "Vector_partition_LUG.h"
//#include "Vector_partition_DUP.h"
//#include "Vector_partition_LGU.h"
#include "Vector_heapSort.h"
//#include "Vector_quickSort_recursive.h"
#include "Vector_quickSort_iterative.h"
#include "Vector_shellSort.h"

#include "Vector_uniquify.h" //����Vector_uniquify_slow.h
#include "Vector_deduplicate.h"
