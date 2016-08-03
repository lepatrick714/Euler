#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

bool is_Prime(int a) {
    for(int i=2; i<=a/2; i++) {
        if(a%i==0) {
            return false;
        }
    }
    return true;
}

string print(vector<int> collection) {
    string result = "";
    for(unsigned i=0; i<collection.size(); i++) {
        result += to_string(collection.at(i));
    }
    return result;
}

bool is_circularPrime(const long a) {
    vector<int> tempCollection;
    long tempA = a;
    string aString = to_string(a);

    while(tempA > 0) {
        tempCollection.push_back(tempA%10);
        tempA/=10;
    }

    vector<int> collection;
    for(int i=tempCollection.size()-1; i>=0; i--) {
        collection.push_back(tempCollection.at(i));
    }

    rotate(collection.begin(), collection.begin()+1, collection.end());
    while(atoi(print(collection).c_str()) != a) {
        if(!is_Prime(atoi(print(collection).c_str()))) {
            return false;
        }
        rotate(collection.begin(), collection.begin()+1, collection.end());
    }
    return true;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    cout << "It works, It just takes 60,000+ milliseconds because I didn't use the list of primes thingy" << endl;
    int ctr = 13;
    for(long i=101; i<1000000; i+=2) {
        if(is_Prime(i)) {
            if(is_circularPrime(i)) {
                ctr++;
            }
        }
    }
    cout << ctr << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
