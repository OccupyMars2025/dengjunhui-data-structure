/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once
#include <cstdint>
#include <cassert>
#include <iostream>

using Rank = int32_t; //��
#define DEFAULT_CAPACITY  3 //Ĭ�ϵĳ�ʼ������ʵ��Ӧ���п�����Ϊ����

template <typename T> 
class Vector { //����ģ����
protected:
   Rank _size; Rank _capacity;  T* _elem; //��ģ��������������
   void copyFrom ( T const* A, Rank lo, Rank hi ); //������������A[lo, hi)
   void expand(); //�ռ䲻��ʱ����
   void shrink(); //װ�����ӹ�Сʱѹ��
   bool bubble ( Rank lo, Rank hi ); //ɨ�轻��
   void bubbleSort_A ( Rank lo, Rank hi ); //���������㷨
   void bubbleSort_B ( Rank lo, Rank hi ); //���������㷨
   void bubbleSort_C ( Rank lo, Rank hi ); //���������㷨
   void bubbleSort_D ( Rank low, Rank high ); //���������㷨
   void bubbleSort_E ( Rank low, Rank high ); //���������㷨
   Rank maxItem ( Rank lo, Rank hi ); //ѡȡ���Ԫ��
   void selectionSort ( Rank low, Rank high ); //ѡ�������㷨
   void merge ( Rank low, Rank middle, Rank high ); //�鲢�㷨
   void mergeSort_v001 ( Rank low, Rank high ); //�鲢�����㷨
   void mergeSort_v002 ( Rank low, Rank high ); //�鲢�����㷨
   void heapSort ( Rank lo, Rank hi ); //�������Ժ�����ȫ�ѽ��⣩
   Rank partition ( Rank lo, Rank hi ); //��㹹���㷨
   void quickSort ( Rank lo, Rank hi ); //���������㷨
   void shellSort ( Rank lo, Rank hi ); //ϣ�������㷨
   void insertionSort(Rank low, Rank high);
public:
// ���캯��
   Vector ( Rank c = DEFAULT_CAPACITY, Rank s = 0, T v = 0 ) //����Ϊc����ģΪs������Ԫ�س�ʼΪv
   { 
      assert((s <= c) && (s >= 0));
      _elem = new T[_capacity = c]; 
      for ( _size = 0; _size < s; _size++) {
         _elem[_size] = v;
      }
   } //s<=c
   Vector ( T const* A, Rank n ) { copyFrom ( A, 0, n ); } //�������帴��
   Vector ( T const* A, Rank lo, Rank hi ) { copyFrom ( A, lo, hi ); } //����
   Vector ( Vector<T> const& V ) { copyFrom ( V._elem, 0, V._size ); } //�������帴��
   Vector ( Vector<T> const& V, Rank lo, Rank hi ) { copyFrom ( V._elem, lo, hi ); } //����
// ��������
   ~Vector() { delete [] _elem; } //�ͷ��ڲ��ռ�
// ֻ�����ʽӿ�
   Rank size() const { return _size; } //��ģ
   bool empty() const { return !_size; } //�п�
   Rank find ( T const& e ) const { return find ( e, 0, _size ); } //���������������
   Rank find ( T const& e, Rank lo, Rank hi ) const; //���������������
   Rank search ( T const& e, int method_id ) const //���������������
   { return ( 0 >= _size ) ? -1 : search ( e, 0, _size , method_id); }
   Rank search ( T const& e, Rank lo, Rank hi, int method_id) const; //���������������
// ��д���ʽӿ�
   T& operator[] ( Rank r ); //�����±������������������������ʽ���ø�Ԫ��
   const T& operator[] ( Rank r ) const; //����������ֵ�����ذ汾
   Vector<T> & operator= ( Vector<T> const& ); //���ظ�ֵ���������Ա�ֱ�ӿ�¡����
   T remove ( Rank r ); //ɾ����Ϊr��Ԫ��
   Rank remove ( Rank lo, Rank hi ); //ɾ����������[lo, hi)֮�ڵ�Ԫ��
   Rank insert ( Rank r, T const& e ); //����Ԫ��
   Rank insert ( T const& e ) { return insert ( _size, e ); } //Ĭ����ΪĩԪ�ز���
   void sort ( Rank low, Rank high, int method_id); //��[lo, hi)����
   void sort(int method_id) { sort ( 0, _size, method_id ); } //��������
   void unsort ( Rank lo, Rank hi ); //��[lo, hi)����
   void unsort() { unsort ( 0, _size ); } //��������
   int disordered() const; // return the number of adjacent inversion pairs
   Rank dedup(); //����ȥ��
   Rank uniquify(); //����ȥ��
// ����
   void traverse ( void (* ) ( T& ) ); //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
   template <typename VST> void traverse ( VST& ); //������ʹ�ú������󣬿�ȫ�����޸ģ�
}; //Vector


#include "Vector/Vector_implementation.h"
