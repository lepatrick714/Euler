#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

long collatzResult(long num) {
    if(num%2 == 0) {
        return num/2;
    }
    else {
        return (num*3)+1;
    }
}

long burteLongestChain(long limit) {
    long result = 0;
    long resultNumber = 0;
    /*while(temp != 1) {
        cout << temp << " -> ";
        temp = collatzResult(temp);
        ctr++;
    }*/

    for(long i=2; i<=limit; i++) {
        long temp = i;
        long ctr = 1;

        while(temp != 1) {
            //cout << temp << " -> ";
            temp = collatzResult(temp);
            ctr++;
        }
        //cout << 1 << endl;
        if(ctr > result) {
            result = ctr;
            resultNumber = i;
        }
    }

    cout << "The resultNumber is: " << resultNumber << " with ";
    return result;
}

long cachingLongestChain(long limit) {
    long result = 0;
    long resultNumber = 0;

    int cacheArray[limit+5];
    cacheArray[1] = 1;
    for(long i=2; i<=limit; i++) {
        long temp = i;
        long ctr = 1;

        while(temp != 1) {
            temp = collatzResult(temp);
            if(temp < i) {
                ctr += cacheArray[temp];
                break;
            }
            else {
                ctr++;
            }
        }
        cacheArray[i] = ctr;
        if(ctr > result) {
            result = ctr;
            resultNumber = i;
        }
    }
    cout << "The resultNumber is: " << resultNumber << " with ";
    return result;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    long limit = 0;
    cout << "Please enter a limit: ";
    cin >> limit;

    cout << "----Running Brute Force Method----" << endl;
    auto t1 = Clock::now();

    cout << burteLongestChain(limit) << " terms." << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ms.count() << " milliseconds" << endl;
    cout << "----End of Brute Force Method----\n\n" << endl;


    cout << "----Running Caching Method----" << endl;
    t1 = Clock::now();

    cout << cachingLongestChain(limit) << " terms." << endl;

    t2 = Clock::now();
    ms = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ms.count() << " milliseconds" << endl;
    cout << "----End of Caching Method----\n\n" << endl;
    return 0;
}
