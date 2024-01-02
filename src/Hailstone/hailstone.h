#pragma once

#include <iostream>

uint64_t hailstone_v1(int n);
uint64_t hailstone_v2(int n);

template<typename T> 
struct Hailstone{
    virtual uint64_t operator()(T e) {
        uint64_t length = 0;
        while (e >= 1)
        {
            ++length;
            if(1 == e) {
                break;
            } else if(1 & e){
                e = 3 * e + 1;
            } else {
                e >>= 1;
            }
        }
        return length;
    }
};
