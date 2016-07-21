#include <iostream>
#include <chrono>
#include <ctime>
#include <algorithm>
using namespace std;

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    int result = 0;

    for(int i=2; i<355000; i++) {
        int sum = 0;
        int tempNum = i;
        while(tempNum > 0) {
            int rightMost = tempNum%10;
            tempNum /= 10;

            int temp = rightMost;
            for(int j=1; j<5; j++) {
                temp *= rightMost;
            }
            sum += temp;
        }

        if(sum == i) {
            result+=i;
        }
    }
    cout << result << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
