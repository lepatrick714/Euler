#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

bool isPrime(long n) {
    for(unsigned i=2; i<=sqrt(n); i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

long sumOfPrimes(long n) {
    long result = 0;
    for(int i = 2; i<n; i++) {
        if(isPrime(i)) {
            result += i;
        }
    }
    return result;
}

int main(int argc, char**argv) {
    cout << sumOfPrimes(2000000) << endl;

    return 0;
}
