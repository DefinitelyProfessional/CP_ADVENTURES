#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

inline uint64_t get_max_drop(vector<uint64_t> &arr, uint64_t n_) {
    uint64_t prev = arr[0], max_drop = 0;
        for (uint64_t i_ = 1; i_ < n_; i_++) {
            if (prev > arr[i_]) {
                uint64_t drop = prev - arr[i_];
                if (drop > max_drop) {max_drop = drop;}
            }
            prev = arr[i_];
        }
    return max_drop;
}

inline bool is_possible_fix(vector<uint64_t> &arr, uint64_t n_, uint64_t max_drop) {
    uint64_t prev = arr[0];
    for (uint64_t i_ = 1; i_ < n_; i_++) {
        if (prev > arr[i_]) {
            // if adding the max drop fixes the sequence, change.
            if (prev <= arr[i_] + max_drop) {arr[i_] += max_drop;}
            // if prev > arr[i_] + max_drop, fix is impossible...
            else {return false;}
        }
        prev = arr[i_];
    }
    return true;
}

int main(void) {
    uint64_t testcases, t_, n_, i_; 
    cin >> testcases;
    for (t_ = 0; t_ < testcases; t_++) {
        // load input to variables
        cin >> n_;
        vector<uint64_t> arr(n_);
        for (i_ = 0; i_ < n_; i_++) {cin >> arr[i_];}

        // get the maximum drop in the sequence
        uint64_t max_drop = get_max_drop(arr, n_);

        // max drop is 0 iff the sequence is already sorted
        if (max_drop == 0) {cout << "YES" << endl; continue;}

        // check if it's possible to fix the sequence with the maximum drop
        cout << ((is_possible_fix(arr, n_, max_drop)) ? "YES" : "NO") << endl;
    }
}