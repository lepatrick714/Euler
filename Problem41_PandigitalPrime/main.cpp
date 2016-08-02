#include <iostream>
#include <chrono>
#include <ctime>
#include <math.h>

using namespace std;

bool is_prime(const int a) {
    if(a == 1) return false;

    for(long i=2; i<=sqrt(a); i++)
        if(a%i==0)
           return false;
    return true;
}



bool isPandigital(const int a) {
    string stringTemp = to_string(a);
    int temp[stringTemp.size()] = {0};

    for(unsigned i=0; i<stringTemp.size(); i++) {
        int yes = stringTemp[i]-48;
        if(temp[yes] == 1) {
            return false;
        }
        else {
            temp[yes] = 1;
        }
    }

    return true;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    long temp = 0;

    for(long i=8000001; i>=2143; i-=2) {
        if(is_prime(i)) {
            if(isPandigital(i)) {
                if(temp < i) {
                    temp = i;
                }
            }
        }
        cout << i << endl;
    }

    cout << temp << endl;



    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
