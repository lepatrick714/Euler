#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

long factorial(int num) {
    if(num==0 || num==1) {
        return 1;
    }
    else if(num == 2) {
        return 2;
    }
    else {
        return num*factorial(num-1);
    }
}

bool isCurious(int num) {
    int total = 0;
    int temp = num;

    while(num != 0) {
        int rightMost = num%10;
        num/=10;

        total+=factorial(rightMost);
    }

    if(total == temp) {
        return true;
    }
    else {
        return false;
    }
}


int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    int total = 0;
    for(int i=3; i<400000; i++) {
        if(isCurious(i)) {
            total += i;
        }
    }

    cout << total << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
