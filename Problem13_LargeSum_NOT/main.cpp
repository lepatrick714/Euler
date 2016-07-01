#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char**argv) {
    if(argc != 2) {
        cout << "Not enough arguments!" << endl;
        return 1;
    }
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();


    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
