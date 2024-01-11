/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once


// template <typename T> 
// int Vector<T>::dedup() { //ɾ�������������ظ�Ԫ�أ�����棩
//    int oldSize = _size; //��¼ԭ��ģ
//    for ( Rank i = 1; i < _size; i++ ) { //��һ����_elem[i]
//       Rank j = find ( _elem[i], 0, i ); //��_elem[i]��ǰ����Ѱ����֮��ͬ�ߣ�����һ����
//       if ( 0 <= j ) remove ( j ); //�����ڣ���ɾ��֮�����ڴ����������һ����������i++��
//    }
//    return oldSize - _size; //������ģ�仯��������ɾ��Ԫ������
// }



template <typename T> 
int Vector<T>::dedup() {
    printf("src/Vector/Vector_deduplicate_2.h\n");
    
    Rank oldSize = _size;
    for(Rank i = 1; i < _size;) {
        int index_of_duplicate = find(_elem[i], 0, i);
        if(index_of_duplicate >= 0) {
            remove(index_of_duplicate);
        } else {
            ++i;
        }
    }

    return oldSize - _size;
}