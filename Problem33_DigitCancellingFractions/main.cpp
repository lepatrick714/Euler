#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

bool isCurious(int num, int den) {


}


int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
