#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_Pandigital(const string num) {
    bool check[11] = {0};

    for(int i=0; i<num.size(); i++) {
        //cout << "Testing num[i] " << "check[num[i]-48] = " << check[num[i]-48] << endl;
        if(num[i]-48 == 0) {
            return false;
        }
        else if(check[num[i]-48] != 0) {
            return false;
        }
        else {
            check[num[i]-48] = 1;
        }
    }

    return true;
}

void PandigitalMultiples() {
    int currentNum = 1;
    int multiplier = 1;
    string currentResult = "";
    vector<int> collection;

    for(;;) {
        int tempValue = currentNum*multiplier;
        currentResult += to_string(tempValue);

        if(currentResult.size() == 9 && is_Pandigital(currentResult)) {
            collection.push_back(atoi(currentResult.c_str()));

            currentNum++;
            multiplier = 1;
            currentResult = "";
        }
        else if(currentResult.size() > 9) {
            currentNum++;
            multiplier = 1;
            currentResult = "";
        }
        else if(currentNum > 10000) {
            break;
        }
        else {
            multiplier++;
        }
    }
    cout << collection.at(collection.size()-1) << endl;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    PandigitalMultiples();

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
