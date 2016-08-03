#include <iostream>
#include <math.h>
using namespace std;

unsigned long primeFactors(unsigned long n) {
    while(n%2==0) {
        cout << "2 ";
        n = n/2;
    }

    for(int i=3; i<=sqrt(n); i=i+2) {
        while(n%i == 0) {
            cout << i << " ";
            n = n/i;
        }
    }

    if(n>2) {
        cout << n << endl;
        return n;
    }
}

int main(int argc, char**argv) {
    cout << "Largest Prime: " << primeFactors(600851475143) << endl;
    return 0;
}
