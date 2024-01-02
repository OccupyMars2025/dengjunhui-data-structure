/**
 * https://en.wikipedia.org/wiki/Collatz_conjecture
*/

#include <iostream>
#include "Hailstone/hailstone.h"

/*
recursive version.
return the length of the Hailstone sequence
*/
uint64_t hailstone_v1(int n) {
    if (n <= 0) {
        std::cout << "Illegal argument n = " << n << std::endl;
        exit(1);
    }
    if( 1 == n) {
        return 1;
    /* Use gdb to debug step by step, then you can find this bug
    Caution: the calculation order of "1 & n == 0" seems to be "1 & (n == 0)"
    } else if (1 & n == 0) { 
    */
    } else if (1 & n) { 
        return 1 + hailstone_v1(3 * n + 1);
    } else {
        return 1 + hailstone_v1(n / 2);
    }
}