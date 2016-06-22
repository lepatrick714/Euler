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
    cout << *start << endl;
    cout << *end << endl;
    return false;
}

int main(int argc, char**argv) {
    cout << isPalindromic(63736) << endl;

    return 0;
}
