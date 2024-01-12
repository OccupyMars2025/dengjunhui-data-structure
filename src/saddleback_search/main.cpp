#include <iostream>
#include "saddleback_search/saddleback_search.h"

int main(int argc, char const *argv[])
{
    // if(argc < 3) {
    //     std::cout << "You should enter: " << argv[0] << " n x" << std::endl;
    // }
    // assert(argc >= 3);
    // int n = atoi(argv[1]);
    // int x = atoi(argv[2]);
    // assert(n >= 1);

    for(int n = 1; n < 100; ++n) {
        std::cout << "n = " << n << std::endl;
        for(int x = 0; x < INT32_MAX / 10000; ++x) {
            int ** A = create_2d_array(n);
            validate_array(A, n);
            // print_2d_array(A, n);

            Vector<std::pair<int, int>> vector_for_matched_indices(3, 0, std::pair(-1, -1));
            saddleback_search(A, n, x, vector_for_matched_indices);

            Vector<std::pair<int, int>> vector_for_matched_indices_v002(3, 0, std::pair(-1, -1));
            brute_force_search(A, n, x, vector_for_matched_indices_v002);

            compare_indices(vector_for_matched_indices, vector_for_matched_indices_v002);
            // print_matched_indices(vector_for_matched_indices);

            delete_2d_array(A, n);           
        }
    }

    return 0;
}
