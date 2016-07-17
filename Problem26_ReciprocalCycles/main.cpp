#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

//Returns the longest recurring cycles
void longestCycles(int limit) {
    int result = 0; //holds the length of longest recurring cycles
    int numberResult = 0;

    for(unsigned i=limit; i>1; i--) {
        if(result >= i) { //if the longest recurring cycles is >= i then we've reach the limit
            break;
        }

        int remainders[i] = {0};
        int value = 1;
        int position = 0;

        while(remainders[value] == 0 && value != 0) {
            remainders[value] = position;
            value *= 10;
            value %= i;
            position++;
        }

        if(position - remainders[value] > result) {
            result = position - remainders[value];
            numberResult = i;
        }
    }
    cout << "The answer is: " << numberResult << " with the number of cycles of: " << result << endl;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;

    int limit = 1;
    cout << "Please enter the limit: ";
    cin >> limit;
    cout << endl;

    auto t1 = Clock::now();

    longestCycles(limit);

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
