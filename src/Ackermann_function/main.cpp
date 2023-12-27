#include "Ackermann_function/ackermann.h"

#include <iostream>
#include <chrono>

using namespace std;

/**
running result:

(0, 0): 1  (0 seconds)
(0, 1): 2  (0 seconds)
(0, 2): 3  (0 seconds)
(0, 3): 4  (0 seconds)
(0, 4): 5  (0 seconds)
(1, 0): 2  (0 seconds)
(1, 1): 3  (0 seconds)
(1, 2): 4  (0 seconds)
(1, 3): 5  (0 seconds)
(1, 4): 6  (0 seconds)
(2, 0): 3  (0 seconds)
(2, 1): 5  (0 seconds)
(2, 2): 7  (0 seconds)
(2, 3): 9  (0 seconds)
(2, 4): 11  (0 seconds)
(3, 0): 5  (0 seconds)
(3, 1): 13  (0 seconds)
(3, 2): 29  (0 seconds)
(3, 3): 61  (0 seconds)
(3, 4): 125  (0 seconds)
(4, 0): 13  (0 seconds)
(4, 1): 65533  (23 seconds)
Segmentation fault (core dumped)

*/
int main(int argc, char const *argv[])
{
    for(uint64_t m = 0; m <= 4; ++m) {
        for(uint64_t n = 0; n <= 4; ++n) {
            // Get starting timepoint
            auto start = chrono::high_resolution_clock::now();
        
            uint64_t result = ackermann(m, n);

            // Get ending timepoint
            auto stop = chrono::high_resolution_clock::now();
        
            // To cast it to proper unit
            // use duration cast method
            auto duration = chrono::duration_cast<chrono::seconds>(stop - start);
            
            cout << "(" << m << ", " << n << "): " << result;
            cout << "  (" << duration.count() << " seconds)" << endl;
        }
    }
    return 0;
}
