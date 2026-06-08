#include <iostream>
#include <stdint.h>

using namespace std;

inline bool is_prime(uint64_t x_){
    if (x_ == 2 || x_ == 3) {return true;}
    if (x_ < 2 || x_ % 2 == 0 || x_ % 3 == 0) {return false;}
    uint64_t div_ = 5;
    while (div_ * div_ <= x_) {
        if (x_ % div_ == 0 || x_ % (div_ + 2) == 0) {return false;}
        div_ += 6;
    }
    return true;
}

int main(void){
    uint64_t n_, m_;
    cin >> n_ >> m_;
    if (is_prime(n_) && is_prime(m_)) {
        for (uint64_t i = n_ + ((n_ != 2) ? 2 : 1); i < m_; i += 2) {
            if (is_prime(i)) {cout << "NO"; return 0;}
        }
        cout << "YES"; return 0;
    }
    else {
        cout << "NO"; return 0;
    }
}