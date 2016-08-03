#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

void sumOfDiagonals(const int limita) {
    int result = 1;
    int current = 1;
    int numRows = 1;
    int ctr = 2;
    int times = 0;

    while(numRows != limita) {
        current+=ctr;
        result += current;
        times++;

        if(times == 4) {
            times = 0;
            ctr+=2;
            numRows+=2;
        }
    }

    cout << "The sum of a " << numRows << "x" << numRows << " is: " << result << endl;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;

    int limit = 1;
    cout << "Please enter the number of rows: ";
    cin >> limit;
    cout << endl;

    auto t1 = Clock::now();

    sumOfDiagonals(limit);

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
