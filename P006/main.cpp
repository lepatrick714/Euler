#include <iostream>
#include <math.h>

using namespace std;

//1^2 + 2^2 + 3^2 + ... + n^2 = n(n+1)(2n+1)/6
//(1 + 2 + 3 + ... + n)^2 = (n(n+1)/2)^2

void findDifference(int n) {
    long result=0;

    long squared = (2*pow(n, 3) + 3*pow(n, 2) + n)/6;
    long addSquared = pow((n*(n+1))/2, 2);

    result = addSquared-squared;
    cout << addSquared << "-" << squared << "=" << result << endl;
}

int main(int argc, char**argv) {
    findDifference(100);
    return 0;
}
