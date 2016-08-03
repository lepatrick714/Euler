#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

bool isLeap(int year) {
    return year%4 == 0 && (year%100 != 0 || year%400 == 0);
}

long sundayCtr(unsigned day, unsigned month, unsigned year, unsigned endYear) {
    unsigned tempDay = day;
    unsigned tempMonth = month;
    unsigned tempYear = year;
    unsigned ctr = 0;

    while(tempYear < endYear+1) {
        unsigned daysMonth;
        if(tempDay == 0) {
            ctr++;
        }
        switch (tempMonth) {
            case 4:
            case 6:
            case 9:
            case 11:
                daysMonth = 30;
                break;
            case 2:
                if(isLeap(tempYear))
                    daysMonth = 29;
                else
                    daysMonth = 28;
                break;
            default:
                daysMonth = 31;
        }
        tempDay = (tempDay + daysMonth)%7;
        tempMonth++;
        if(tempMonth > 12) {
            tempMonth = 1;
            tempYear++;
        }
    }
    return ctr;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    cout << -1+sundayCtr(1, 1, 1901, 2000) << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
