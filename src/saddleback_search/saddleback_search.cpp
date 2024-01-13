/*
 exercise 2-22, in chapter 2: Vector
*/

#include "saddleback_search/saddleback_search.h"

int** create_2d_array(int n) {
    /**
     * https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
    */
    // int ** A = (int**)malloc(n * n * sizeof(int));
    // // int ** A = new int[n][n];

    // srand((unsigned int)time(nullptr));

    int ** A = new int*[n];
    for(int i = 0; i < n; ++i) {
        A[i] = new int[n];
    }

    A[0][0] = rand() % 3;
    for(int i = 1; i < n; ++i) {
        A[0][i] = A[0][i-1] + 1 + rand() % 3;
        A[i][0] = A[i-1][0] + 1 + rand() % 3;
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < n; ++j) {
            A[i][j] = max(A[i-1][j], A[i][j-1]) + 1 + rand() % 3;
        }
    }

    return A;
}

void delete_2d_array(int **A, int n) {
    /**
     * https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
     * 
     */
    for(int i=0; i < n; ++i) {
        delete [] A[i];
    }
    delete [] A;
}

void print_2d_array(int **A, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cout << std::setw(4) << A[i][j] << " ";
        }
        std::cout <<  std::endl;
    }
}

// This is the core function
void saddleback_search(int **A, int n, int x, Vector<std::pair<int, int>>& vector_for_matched_indices) {
    int i = 0;
    int j = binSearch<int>(A[0], x, 0, n);

    while ((i < n) && (j >= 0))
    {
        if(A[i][j] < x) {
            ++i;
        } else if(x < A[i][j]) {
            --j;
        } else {
            vector_for_matched_indices.insert(std::pair(i, j));
            ++i; 
            --j;
        }
    }   
}

void brute_force_search(int **A, int n, int x, Vector<std::pair<int, int>>& vector_for_matched_indices) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(A[i][j] == x) {
                vector_for_matched_indices.insert(std::pair(i, j));
                break;
            }
        }
    }
}

void validate_array(int **A, int n) {
    for(int i = 0; i <= n - 2; ++i) {
        for(int j = 0; j <= n - 2; ++j) {
            assert(A[i][j] < A[i][j+1]);
            assert(A[i][j] < A[i+1][j]);
        }
    }  
    for(int i = 0; i <= n - 2; ++i) {
        assert(A[n-1][i] < A[n-1][i+1]);
        assert(A[i][n-1] < A[i+1][n-1]);
    }
}

void compare_indices(Vector<std::pair<int, int>>& v1, Vector<std::pair<int, int>>& v2) {
    assert(v1.size() == v2.size());
    for(int i = 0; i < v1.size(); ++i) {
        assert(v1[i].first == v2[i].first);
        assert(v1[i].second == v2[i].second);
    }
}

void print_matched_indices(Vector<std::pair<int, int>>& v) {
    std::cout << "The matched indices are as follows:" << std::endl;
    for(int i = 0; i < v.size(); ++i) {
        std::cout << "(" << (v[i].first) << ", " << (v[i].second) << ")" << std::endl;
    }
}