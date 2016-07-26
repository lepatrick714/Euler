#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

using namespace std;

bool is_Pandigital(const string num) {
    bool check[11] = {0};
    for(unsigned i=0; i<num.size(); i++) {
        int x = (int)num[i] - 48;
        if(check[x] != 0) {
            return false;
        }
        else {
            check[num[i]] = 1;
        }
    }
    return true;
}

string PandigitalMultiples() {
    int currentNum = 9;
    int multiplier = 1;
    string currentResult = "";

    for(;;) {
        int tempValue = currentNum*multiplier;
        currentResult += to_string(tempValue);

        multiplier++;

        if(currentResult.size() == 9 && is_Pandigital(currentResult)) {
            cout << currentResult << endl;
            break;
        }

    }

    return currentResult;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    cout << PandigitalMultiples() << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
