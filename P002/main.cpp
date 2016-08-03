#include <iostream>
#include <stack>

using namespace std;

long evenFib() {
    long totalEven = 2;
    stack<long> holdingStack;
    holdingStack.push(1);
    holdingStack.push(2);

    for(;;) {
        long top = holdingStack.top();
        holdingStack.pop();
        long bottom = holdingStack.top();
        holdingStack.pop();

        if(top >= 4000000) {
            break;
        }

        long resultFib = top+bottom;
        if(resultFib%2==0) {
            totalEven += resultFib;
        }

        holdingStack.push(top);
        holdingStack.push(resultFib);
    }
    return totalEven;
}

int main(int argc, char**argv) {
    cout << "Even Fib: " << evenFib() << endl;
    return 0;
}
