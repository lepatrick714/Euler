#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

int Calc_Fib(int numA[], int numB[], int temp[], int index) {
    int i = 0;

    if(numB[999] != 0) return index;

    for(i=0; i<1000; i++) {
        temp[i] += (numA[i] + numB[i]);

        if(temp[i] > 9) {
            temp[i+1] = temp[i]/10;
            temp[i]%=10;
        }

        numA[i] = numB[i];
        numB[i] = temp[i];
        temp[i] = 0;
    }

    Calc_Fib(numA, numB, temp, index++);
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    int i = 0;
    int numA[1000];
    int numB[1000];
    int temp[1000];
    int indexVal = 2;

    for(i=0; i<1000; i++) {
        numA[i] = 0;
        numB[i] = 0;
        temp[i] = 0;
    }

    numA[0] = (numB[0] = 1);
    indexVal = Calc_Fib(numA, numB, temp, indexVal);

    cout << "Answer: " << indexVal << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
