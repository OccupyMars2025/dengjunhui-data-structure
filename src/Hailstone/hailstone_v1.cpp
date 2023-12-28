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
    } else if (n % 2 == 0) {
        return 1 + hailstone_v1(n / 2);
    } else {
        return 1 + hailstone_v1(3 * n + 1);
    }
}