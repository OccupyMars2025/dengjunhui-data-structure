/**
 * exercise 2-24, in chapter 2
 * 
 * https://en.wikipedia.org/wiki/Interpolation_search
 * https://csaws.cs.technion.ac.il/~itai/publications/Algorithms/p550-perl.pdf
 * 
 * The analysis is a little different from binary search.
 * You can refer to src/Vector/bisect_from_python.py
*/
#pragma once

#include <cassert>


/*
arr[low, high) is sorted, search the data "key" in this array,
if "key" is found, return the corresponding index (NOT necessarily the highest possible index);
if "key" is not found, just return low - 1

How to verify that the algorithm is correct?
Proof:
(finiteness: after one loop, the width of [low, high] decreases strictly )

Fist, high <--- high - 1
scenario 1. when low = high
scenario 2. when low < high, arr[low] = arr[high]
scenario 3. when low < high, arr[low] < arr[high], key < arr[low] or key > arr[high]
scenario 4. when low < high, arr[low] < arr[high], arr[low] <= key <= arr[high]

Now let's analyze scenario 4:
Once entering the "while" loop,  low <= middle <= high


    let's analyse after one loop(if we don't return), whether "low > high" will occur
    After one loop:
        case a1: "low" branch has been executed in this loop
            arr[middle] < key <= arr[high]
            so we have middle < high
            so after this loop, we have
            low <= high
        case a2: "high" branch has been executed in this loop
            arr[low] <= key < arr[middle]
            so we have low < middle
            so after this loop, we have
            low <= high

    so after one loop(if we don't return), we have "low <= high"


    when we exit the "while" loop:
        case b1: arr[low] >= arr[high]
            In the last loop, if "low" branch is executed, we know
                arr[low - 1] < k <= arr[high]
                arr[low] >= arr[high]
                low <= high
                so we have 
                arr[low - 1] < k <= arr[low] = arr[high]
            In the last loop, if "high" branch is executed, we know
                arr[low] <= key < arr[high + 1]
                arr[low] >= arr[high]
                low <= high
                so we have
                arr[low] = arr[high] <= key < arr[high + 1]

        case b2: (arr[low] < arr[high]) && (arr[low] > key):
            In the last loop, "low" must have been changed
            so we have
            arr[low - 1] < key
            so we have 
            arr[low - 1] < key < arr[low]

        case b3: (arr[low] < arr[high]) && (key > arr[high])
            In the last loop, "high" must have been changed
            so we have
            key < arr[high + 1]
            so we have
            arr[low] < arr[high] < key < arr[high + 1]

*/
template <typename T>
static Rank interpolation_search_v001(T* arr, const T& key, Rank low, Rank high)
{
    // std::cout << "src/Vector/Vector_search_interpolation.h   v001" << std::endl;

    high -= 1;
    int middle;
    int initial_low = low;

    while ((arr[low] < arr[high]) && (arr[low] <= key) && (key <= arr[high])) {
        middle = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        assert((low <= middle) && (middle <= high));

        if (arr[middle] < key)
            low = middle + 1;
        else if (key < arr[middle])
            high = middle - 1;
        else
            return middle;
    }

    if (key == arr[low])
        return low;
    else
        return initial_low - 1;
}


/*
search "key" in the sorted array arr[low, high),
return: the highest index i such that arr[i] <= key

How to verify that the algorithm is correct?
Proof:
finiteness: after one loop, the width of [low, high] decreases strictly 

Fist, high <---- high - 1
scenario 1. when low = high
scenario 2. when low < high, key < arr[low] or arr[high] <= key
scenario 3. when low < high, arr[low] <= key < arr[high]

Now let's analyze scenario 3:
Once entering the "while" loop,  low <= middle < high

when we exit the "while" loop:
    case a1: key < arr[low]
        so "low" is changed in the last loop, we know
        arr[low - 1] <= key < arr[low]
    case a2: arr[high] <= key
        so "high" is changed in the last loop, we know
        key < arr[high], impossible

conclusion: we should return "low - 1"

*/
template <typename T> 
static Rank interpolation_search_v002(T* arr, const T& key, Rank low, Rank high) {
    // std::cout << "src/Vector/Vector_search_interpolation.h  v002" << std::endl;
    
    high -= 1;
    assert(low <= high);
    Rank middle;

    if(key < arr[low]) {
        return low - 1;
    } 
    if(arr[high] <= key) {
        return high;
    }

    // now low < high ,  arr[low] <= key < arr[high]
    while ((arr[low] <= key) && (key < arr[high])) {
        middle = low + ((high - low) * (key - arr[low])) / (arr[high] - arr[low]);

        assert((low <= middle) && (middle < high));

        if(key < arr[middle]) {
            high = middle;
        } else {
            low = middle + 1;
        } 
    }

    return low - 1;
}

