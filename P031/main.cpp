#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    int ctr = 0;
    for(int i=200; i>=0; i-=200) {
        for(int j=i; j>=0; j-=100) {
            for(int z=j; z>=0; z-=50) {
                for(int a=z; a>=0; a-=20) {
                    for(int b=a; b>=0; b-=10) {
                        for(int c=b; c>=0; c-=5) {
                            for(int d=c; d>=0; d-=2) {
                                ctr++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ctr << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
