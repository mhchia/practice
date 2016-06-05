// you can use includes, for example:
// #include <algorithm>
#include <cstdlib>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;



int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    if (A.size() == 0) {
        return -1;
    }
    int sum = 0, M;
    vector<int>::size_type max_index = 0, min_index = 0;
    for (vector<int>::size_type i = 0; i < A.size(); ++i) {
        if (A[i] > A[max_index]) {
            max_index = i;
        }
        if (A[i] < A[min_index]) {
            min_index = i;
        }
        sum += A[i];
    }
    M = sum / A.size();
    if (abs(A[max_index] - M) > abs(A[min_index] - M)) {
        return max_index;
    } else {
        return min_index;
    }
}

