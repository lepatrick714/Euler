#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;





int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    long total = 1;
    long position = 0;
    for(long i=1; i<=1000000; i++) {
        string temp = to_string(i);

        for(unsigned i=0; i<temp.size(); i++) {
            position++;
            if(position == 1 || position == 10 || position == 100 || position == 1000 || position == 10000 ||
                position == 100000 || position == 1000000) {
                cout << temp[i] << endl;
                total *= temp[i]-48;
            }
        }
    }

    cout << total << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
