#include <iostream>
#include <vector>

using namespace std;

long getMultiples(int mu) {
    long total = 0;                                             //O(1)
    int numberLoops = 0;
    unsigned multipl = 1;                                       //O(1)
    for(;;) {                                                   //Infinte LOOP Undermined
        long resultNumber = multipl*mu;                         //O(1)
        if(resultNumber >= 1000) {                              //O(1)
            break;                                              //O(1)
        }
        else if(resultNumber % 5==0 && mu == 3) {
        }
        else {
            total += resultNumber;
        }
        numberLoops++;
        multipl++;
    }
    return total;
}

int main(int argc, char**argv) {
    long total3 = getMultiples(3);
    long total5 = getMultiples(5);
    cout << "total3 + total5 = " << total3 + total5 << endl;
    return 0;
}
