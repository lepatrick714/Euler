#include <iostream>
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <ctime>

using namespace std;

long numRoutes(const int size) {
    long arr[size][size];
    memset(arr, 0, sizeof(arr));

    /*
    for(unsigned i=0; i<size; i++) {
        for(unsigned j=0; j<size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    */

    int ctr = 2;
    for(unsigned i=0; i<size; i++) {
        arr[i][0] = ctr;
        ctr++;
    }
    ctr = 2;
    for(unsigned j=0; j<size; j++) {
        arr[0][j] = ctr;
        ctr++;
    }


    for(unsigned i=1; i<size; i++) {
        for(unsigned j=1; j<size; j++) {
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    return arr[size-1][size-1];
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    int cube;
    cout << "Please enter the cube size: ";
    cin >> cube;

    cout << "Total number of routes is: " << numRoutes(cube) << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
