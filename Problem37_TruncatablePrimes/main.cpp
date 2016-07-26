#include <iostream>
#include <chrono>
#include <ctime>
#include <math.h>

using namespace std;

bool is_prime(long num) {
    if(num == 1) {
        return false;
    }
    for(long i=2; i<=sqrt(num); i++) {
       if(num%i==0) {
            return false;
       }
    }
    return true;
}

bool isLeftTrunc(long num) {
    while(num > 0) {
        if(!is_prime(num)) {
            return false;
        }
        num/=10;
    }
    return true;
}

bool isRightTrunc(long num) {
    //num = num%(int)pow(10, (int)log10(num));
    while(num > 0) {
        if(!is_prime(num)) {
            return false;
        }
        num = num%(int)pow(10, (int)log10(num));
    }
    return true;
}

bool isTruncatable(long n) {
    long pow = 10;

    while(pow<n) {
        if(is_prime(n%pow) || is_prime(n/pow)) {
            return false;
        }
        pow *= 10;
    }
    return true;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    long total = 0;
    long i = 11;
    long ctr = 0;
    while(ctr<11) {
        if(isLeftTrunc(i) && isRightTrunc(i)) {
            ctr++;
            total += i;
        }
        i++;
    }

    cout << total << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
