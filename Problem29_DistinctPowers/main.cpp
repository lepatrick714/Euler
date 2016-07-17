#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void distinctPowers(const int a, const int b) {
    vector<long long unsigned> v;

    for(unsigned i=2; i<=a; i++) {
        for(unsigned j=2; j<=b; j++) {
            v.push_back(pow(i,j));
        }
    }

    sort(v.begin(), v.end());
    int ctr = 0;
    long long unsigned curr = 0;
    for(unsigned i=0; i<v.size(); i++) {
        if(v.at(i) != curr) {
            ctr++;
            curr = v.at(i);
        }
        cout << v.at(i) << endl;
    }
    cout << endl;
    cout << "Number of distinct terms: " << ctr << endl;
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
