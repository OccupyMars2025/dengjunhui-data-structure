/**
 * exercise 2-24, in chapter 2
 * 
 * https://en.wikipedia.org/wiki/Interpolation_search
 * https://csaws.cs.technion.ac.il/~itai/publications/Algorithms/p550-perl.pdf
 * 
*/
#pragma once

#include <cassert>

/*
search "key" in the sorted array arr[low, high),
return: the highest index i such that arr[i] <= key


How to verify that the algorithm is correct?
Proof:
Fist, high <---- high - 1
scenario 1. when low = high
scenario 2. when low < high, key < arr[low] or arr[high] <= key
scenario 3. when low < high, arr[low] <= key < arr[high]

Now let's analyze scenario 3:
Once entering the "while" loop,  low <= middle < high
(finiteness: after one loop, "low" will increase strictly or "high" will decrease strictly )

we can see that at the end of one loop (if we don't return, 
if the "low" branch and "high" branch have both been executed at least once):
1. arr[0, low-1] <= key < arr[high, n)
(if the "low" branch has NOT been executed, the "high" branch has been executed at least once)
2. arr[low] <= key < arr[high, n)
(...)
3. arr[0, low-1] <= key < arr[high]

Let's see when we exit the "while" loop
case a1: key < arr[low]
    so "low" is changed in the last loop, we know
    arr[low - 1] <= key < arr[low]
case a2: arr[high] <= key
    so "high" is changed in the last loop, we know
    key < arr[high], impossible

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


/*
copied from:
https://en.wikipedia.org/wiki/Interpolation_search

arr[low, high) is sorted, search the data "key" in this array,
if "key" is found, return the corresponding index (NOT necessarily the highest possible index);
if "key" is not found, just return low - 1

How to verify that the algorithm is correct?
Proof:
Fist, high <--- high - 1
scenario 1. when low = high
scenario 2. when low < high, arr[low] = arr[high]
scenario 3. when low < high, arr[low] < arr[high], key < arr[low] or key > arr[high]
scenario 4. when low < high, arr[low] < arr[high], arr[low] <= key <= arr[high]

Now let's analyze scenario 4:
Once entering the "while" loop,  low <= middle <= high
(finiteness: after one loop, "low" will increase strictly or "high" will decrease strictly )
we can see that at the end of one loop (if we don't return, 
if the "low" branch and "high" branch have both been executed at least once):
1. arr[0, low) < key < arr(high, n)
(if the "low" branch has NOT been executed, the "high" branch has been executed at least once)
2. arr[low] <= key < arr(high, n)
(...)
3. arr[0, low) < key <= arr[high]


Let's see when we exit the "while" loop
case a1. low < high, arr[low] = arr[high]
case a2. low < high, arr[low] < arr[high], key < arr[low] or key > arr[high]
case a3. low < high, arr[low] < arr[high], arr[low] <= key <= arr[high]

Let's analyze case a3 :
1. middle = high - 1,  arr[high - 1] < key <= arr[high] , low <---- high
2. middle = high,  arr[high] < key, impossible
3. middle = low + 1, arr[low] <= key < arr[low + 1], high <---- low
4. middle = low, key < arr[low], impossible

*/
template <typename T>
static Rank interpolation_search_v001(T* arr, const T& key, Rank low, Rank high)
{
    // std::cout << "src/Vector/Vector_search_interpolation.h   v001" << std::endl;

    high -= 1;
    int middle;
    int initial_low = low;

    while ((arr[high] != arr[low]) && (key >= arr[low]) && (key <= arr[high])) {
        middle = low + (((key - arr[low]) * (high - low)) / (arr[high] - arr[low]));

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