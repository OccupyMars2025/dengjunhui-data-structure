#pragma once


// return the number of adjacent inversion pairs
template <typename T>
int Vector<T>::disordered() const {
    int num_of_adjacent_inversion_pairs = 0;
    for(Rank i = 1; i < _size; ++i) {
        if(_elem[i-1] > _elem[i]) {
            ++num_of_adjacent_inversion_pairs;
        }
    }

    return num_of_adjacent_inversion_pairs;
}