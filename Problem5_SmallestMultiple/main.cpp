#include <iostream>

using namespace std;

bool isDivis(long in) {
    for(unsigned i=2; i<20; i++) {
        if(in%i != 0) {
            return false;
        }
    }
    return true;
}

long findSmallestMult() {
    long result = 0;
    long start = 20;
    for(;;) {
        if(isDivis(start)) {
            result = start;
            break;
        }
        start+=20;
    }
    return result;
}

int main(int argc, char**argv) {
    long result = findSmallestMult();

    cout << result << endl;
    return 0;
}
