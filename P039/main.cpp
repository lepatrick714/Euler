#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;

class temp {
    public:
        unsigned a;
        unsigned b;

        temp(unsigned a, unsigned b) {
            this->a = a;
            this->b = b;
        }
};


int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    int largestTimes = 0;
    int largestResult = 0;
    vector<temp> biggestCollection;

    //(p^2)/2 == ap + bp - ab
    for(unsigned p=2; p<1001; p+=2) {
        int numTimes = 0;
        vector<temp> numCollection;
        for(unsigned a=2; a<p; a++) {
            for(unsigned b=a; b<p; b++) {
                if( (p*p)/2 == (a*p) + (b*p) - (a*b)) {
                    temp v(a,b);
                    numCollection.push_back(v);
                    numTimes++;
                }
            }
        }
        if(largestTimes < numTimes) {
            largestTimes = numTimes;
            largestResult = p;
            biggestCollection = numCollection;
        }
    }
    cout << largestResult << " with " << largestTimes << endl;
    for(unsigned i=0; i<biggestCollection.size(); i++) {
        cout << biggestCollection.at(i).a << " " << biggestCollection.at(i).b << endl;
    }

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
