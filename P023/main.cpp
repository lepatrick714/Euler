#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;

//Perfect Num is the 'sum of all proper divisors == num
//Deficient is proper div < num
//Abundant is proper div > num

//create an array of 0 and populate it based on whether the index is abundant
//create a vector<int> that contains all positive integers that cannot be sum of two abundant nums

bool isAbundantNums(long num) {
    long ctr = 0;
    for(unsigned i=1; i<=num/2; i++) {
        if(num%i == 0) {
            ctr += i;
        }
    }
    return ctr>num;
}

long returnSum() {
    long limit = 28123; //Anything greater can be expressed by two abundant nums
    long start = 12;
    vector<long> abundantNumbers;

    while(start!=limit+1) {
        if(isAbundantNums(start)) {
            abundantNumbers.push_back(start);
        }
        start++;
    }

    int arr[limit+1] = {0};
    long ctr = 0;
    for(unsigned i=0; i<abundantNumbers.size(); i++) {
        for(unsigned j=i; j<abundantNumbers.size(); j++) {
            long temp = abundantNumbers.at(i)+abundantNumbers.at(j);
            if(temp <= limit) {
                arr[temp] = 1;
            }
            else {
                break;
            }
        }
    }

    for(unsigned i=1; i<=limit; i++) {
        if(arr[i] == 0) {
            ctr+=i;
        }
    }
    return ctr;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    cout << "Total of positive integers that cannot be written as the sum of two abundant numbers is: ";
    cout << returnSum() << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
