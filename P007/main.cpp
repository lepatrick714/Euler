#include <iostream>

using namespace std;

bool isPrime(long n) {
    for(int i=2; i<=n/2; i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

long findPrimeNumber(long pos) {
    long result = 0;
    long ctr = 0;
    long start = 2;

    while(ctr!=pos) {
        if(isPrime(start)) {
            result = start;
            ctr++;
        }
        start++;
    }

    return result;
}

int main(int argc, char**argv) {
    long result = findPrimeNumber(10001);
    cout << result << endl;
    return 0;
}
