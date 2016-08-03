#include <iostream>
#include <math.h>

using namespace std;

int findProduct() {
    int a;

    const int sum = 1000;
    for(a=1; a<=sum/3; a++) {
        int b;
        for(b=a+1; b<sum/2; b++) {
            int c = sum-a-b;
            if(a*a + b*b == c*c) {
                return a*b*c;
            }
        }
    }

    return -1;
}


int main(int argc, char**argv) {
    cout << findProduct() << endl;
    return 0;
}
