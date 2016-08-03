#include <iostream>
#include <chrono>
#include <ctime>
#include <math.h>
#include <vector>

using namespace std;

long returnPowerSum(long limit) {
    long result = 0;
    vector<unsigned> v;
    v.push_back(1);

    for(int i=0; i!=limit; i++) {
        unsigned carry = 0;
        for(vector<unsigned>::iterator it = v.begin(); it != v.end(); it++) {
            unsigned temp = *it;
            temp = 2*temp+carry;
            carry = temp/10;
            temp = temp%10;
            *it = temp;
        }
        if(carry!=0) {
            v.push_back(carry);
        }
    }

    for(unsigned i=0; i<v.size(); i++) {
        result+= v.at(i);
    }
    return result;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;

    long expo;
    cout << "Please input the expo: ";
    cin >> expo;

    auto t1 = Clock::now();
    cout << "2^" << expo << " = " << returnPowerSum(expo) << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
