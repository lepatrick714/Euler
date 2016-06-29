#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int numAllDivisor(long num) {
    int result = 0;
    for(int i=1; i<num; i++) {
        if(num%i == 0) {
            result++;
        }
    }
    return result;
}

void printAllDivisor(long num) {
    for(int i=1; i<num; i++) {
        if(num%i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

long valueTriangle(long numDiv) {
    long divisorCtr = 0;
    long x = 1;
    long currentTriangle = 1;
    while(divisorCtr != numDiv) {
        if(numDiv == numAllDivisor(currentTriangle) ){
            break;
        }
        x++;
        currentTriangle += x;
    }
    return currentTriangle;
}

int main(int argc, char**argv) {
    long num = valueTriangle(10)
    cout << num << endl;
    printAllDivisor(num);
    return 0;
}
