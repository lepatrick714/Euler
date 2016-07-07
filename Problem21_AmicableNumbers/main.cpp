#include <iostream>
#include <chrono>
#include <ctime>
#include <math.h>

using namespace std;

long d(int num) {
    long result = 0;

    for(unsigned i=1; i<=num/2; i++)
        if(num%i == 0)
            result += i;

    return result;
}

bool isAmicable(int a) {
    return a == d(d(a)) && a!=d(a);
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;

    unsigned limit = 1;
    cout << "Enter the limit: ";
    cin >> limit;

    auto t1 = Clock::now();

    unsigned ctr = 0;
    for(unsigned i=1; i<limit; i++) {
        if(isAmicable(i)){
            //cout << i << " " << d(i) << endl;
            ctr+=i;
        }
    }

    cout << "Sum of all Amicable Numbers under " << limit << ": " << ctr << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
