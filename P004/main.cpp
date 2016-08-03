#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

bool isPalindromic(long num) {
    stringstream ss;
    ss << num;
    string numStr = ss.str();

    string::iterator start = numStr.begin();
    string::iterator end = numStr.end()-1;

    while(start<end) {
        if(*start != *end) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

long findLargestPalindrome() {
    long largest = 0;
    int a = 100;

    while(a<1000) {
        int b = a;
        while(b<1000) {
            long temp = a*b;
            if(temp>largest && isPalindromic(temp)) {
                largest = temp;
            }
            //cout << a << "*" << b << endl;
            b++;
        }
        a++;
    }

    return largest;
}

int main(int argc, char**argv) {
    long result = findLargestPalindrome();

    cout << result << endl;
    return 0;
}
