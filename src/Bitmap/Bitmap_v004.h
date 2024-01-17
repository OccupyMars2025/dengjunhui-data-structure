#pragma once

#include <cstdint>
#include <cassert>
#include <cstring>
#include <iostream>
using Rank = int32_t;


/**
I recommend using Bitmap_v004 (it's the best):
reason 1: complete initialization and reset in constant time
reason 2: present_elements[] records the elements' insertion order
reason 3: You can tell whether one element was previously set but then cleared


when initializing and reseting, you don't need to set all bytes to 0 byte by byte
support set(), clear() and test()

key point: you need to effectively distinguish between these 3 situations:
1. k has never been set:
    Rank i = the_whole_range[k];
    i is not in the range [0, top)

2. k is set:
    Rank i = the_whole_range[k];
    i is in the range [0, top)
    present_elements[i] == k

3. k was previously set but then cleared:
    Rank i = the_whole_range[k]
    i is in the range [0, top)
    present_elements[i] == -k-1

*/
class Bitmap_v004
{
private:
    Rank *the_whole_range;
    Rank n;
    Rank *present_elements;
    Rank top;

protected:
    bool has_ever_been_set(Rank k) {
        Rank i = the_whole_range[k];
        return (0 <= i) && (i < top);
    }
    bool is_erased(Rank k) {
        Rank i = the_whole_range[k];
        return (0 <= i) && (i < top) && (present_elements[i] == -k - 1);
    }
public:

    void init(Rank n) {
        if(n < 3) n = 3;
        this->n = n;
        the_whole_range = new Rank[n];
        present_elements = new Rank[n];
        top = 0;
    }

    Bitmap_v004(Rank n) {
        init(n);
    }

    ~Bitmap_v004(){
        delete [] the_whole_range;
        delete [] present_elements;
    }

    Rank size() {
        return top;
    }
    
    void expand(Rank k) {
        if(k < n) return;

        Rank *old_the_whole_range = the_whole_range;
        Rank old_n = n;
        Rank *old_present_elements = present_elements;
        Rank old_top = top;
        init(2 * k);

        memcpy(the_whole_range, old_the_whole_range, old_n * sizeof(Rank));
        memcpy(present_elements, old_present_elements, old_top * sizeof(Rank));
        top = old_top;

        delete [] old_the_whole_range;
        delete [] old_present_elements;
    }

    bool test(Rank k) {
        assert(k >= 0);
        expand(k);

        Rank i = the_whole_range[k];
        bool is_present = (0 <= i) && (i < top) && (present_elements[i] == k);
        return is_present;
    }

    void set(Rank k) {
        assert(k >= 0);
        expand(k);

        // // method 1: 
        // Rank i = the_whole_range[k];
        // if((0 <= i) && (i < top)) {
        //     if(present_elements[i] == k) { // k is set
        //         return;
        //     } else if(present_elements[i] == -k - 1) { // k is set but then cleared
        //         present_elements[i] = k;
        //     } else { // k is not set
        //         the_whole_range[k] = top;
        //         present_elements[top] = k;
        //         ++top;                
        //     }
        // } else { // k is not set
        //     the_whole_range[k] = top;
        //     present_elements[top] = k;
        //     ++top;
        // }

        // method 2:
        if(test(k)) return;

        if(!is_erased(k)) {
            the_whole_range[k] = top++;
        }
        present_elements[the_whole_range[k]] = k;
    }

    void clear(Rank k) {
        assert(k >= 0);
        expand(k);

        if(test(k)) {
            present_elements[the_whole_range[k]] = -k - 1;
        }
    }

    void reset() {
        top = 0;
    }

    void print(Rank n) {
        expand(n - 1);

        for(Rank i = 0; i < n; ++i) {
            std::cout << (test(i) ? "1" : "0");
        }
        std::cout << std::endl;
    }
};
