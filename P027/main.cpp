#include <iostream>
#include <chrono>
#include <ctime>
#include <math.h>

using namespace std;

bool is_prime(const int n) {
    for(unsigned i=2; i<=sqrt(n); i++)
        if(n%i==0)
            return false;
    return true;
}

int numberOfPrimes(const int a, const int b) {
    int ctr = 0;
    int n = 0;

    while(true) {
        int result = abs((n*n) + a*n + b);
        if(!is_prime(result)) {
            break;
        }
        ctr++;
        n++;
    }

    return ctr-1;
}

void burteForce(const int limita, const int limitb) {
    int a = 0;
    int b = 0;
    int numPrimes = 0;


    for(int i=limita-1; abs(i)<limita; i--) {
        for(int j=limitb-1; abs(j)<limitb; j--) {
            if(numPrimes < numberOfPrimes(i, j)) {
                numPrimes = numberOfPrimes(i,j);
                a = i;
                b = j;
            }
        }
    }

    cout << "n^2 + " << a << "n + " << b << endl;
    cout << "The range is 0 -> " << numPrimes << endl;
    cout << "Product of the coefficient is: " << a*b << endl;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    burteForce(1000, 1000);

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
