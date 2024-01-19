#pragma once


template <typename T>
void Vector<T>::insertionSort(Rank low, Rank high) {
    // std::cout << "src/Vector/Vector_insertionSort.h" << std::endl;

    if(high - low < 2) return;

    Rank insertion_index;
    for(Rank i = low + 1; i < high; ++i) {
        insertion_index = 1 + search(_elem[i], low, i, 0);
        T insertion_element = _elem[i];
        for(Rank  j = i; j > insertion_index; --j) {
            _elem[j] = _elem[j-1];
        }
        _elem[insertion_index] = insertion_element;
    }
}
