#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

void distinctPowers(const int a, const int b) {
    set<double> yes;

    for(unsigned i=2; i<=a; i++) {
        for(unsigned j=2; j<=b; j++) {
            double temp = pow(i, j);
            yes.insert(temp);
        }
    }
    cout << yes.size() << endl;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;

    int a = 2;
    int b = 2;

    cout << "Please enter A limit: ";
    cin >> a;
    cout << endl;
    cout << "Please enter B limit: ";
    cin >> b;
    cout << endl;

    auto t1 = Clock::now();

    distinctPowers(a, b);

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
