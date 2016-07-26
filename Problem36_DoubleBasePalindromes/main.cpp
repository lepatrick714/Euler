#include <iostream>
#include <chrono>
#include <ctime>
#include <iterator>
#include <vector>

using namespace std;

bool isPalindromic(string ss) {
    string::iterator start = ss.begin();
    string::iterator end = ss.end()-1;

    while(start<end) {
        if(*start != *end) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

string convertBinary(long input) {
    vector<int> temp;
    string result = "";
    while(input > 0) {
        if(input%2 != 0) {
            temp.push_back(1);
        }
        else {
            temp.push_back(0);
        }
        input/=2;
    }

    for(int i=temp.size()-1; i>=0; i--) {
        result += to_string(temp.at(i));
    }
    return result;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    long result = 0;
    for(long i=1; i<1000000; i+=2) {
        if(isPalindromic(to_string(i))) {
            string binary = convertBinary(i);
            if(isPalindromic(binary)) {
                result += i;
            }
        }
    }

    cout << result << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
