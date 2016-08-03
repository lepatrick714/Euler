#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

void simplify(int &top, int &bottom) {
    for(int i=bottom*top; i>1; i--) {
       if((bottom%i==0) && (top%i==0)) {
            bottom/=i;
            top/=i;
       }
    }
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    int top = 1;
    int bottom = 1;

    int ctr = 0;
    for(int a=10; a<=99; a++) {
        for(int b=a+1; b<=99; b++) {
            if(a%10 != 0 || b%10 != 0) {

                double orignalValue = (double)(a)/(b);
                int tempA = a;
                int tempB = b;

                int topb = tempA%10;
                tempA/=10;
                int topa = tempA%10;

                int botb = tempB%10;
                tempB/=10;
                int bota = tempB%10;

                if(topa == bota) {
                    double tempValue = (double)(topb)/(botb);
                    if(orignalValue == tempValue) {
                        cout << a << "/" << b << " == " << topb << "/" << botb << endl;
                        top*=a;
                        bottom*=b;
                        simplify(top, bottom);
                    }
                }
                else if(topa == botb) {
                    double tempValue = (double)(topb)/(bota);
                    if(orignalValue == tempValue) {
                        cout << a << "/" << b << " == " << topb << "/" << bota << endl;
                        top*=a;
                        bottom*=b;
                        simplify(top, bottom);
                    }
                }
                else if(topb == bota) {
                    double tempValue = (double)(topa)/(botb);
                    if(orignalValue == tempValue) {
                        cout << a << "/" << b << " == " << topa << "/" << bota << endl;
                        top*=a;
                        bottom*=b;
                        simplify(top, bottom);
                    }
                }
                else if(topb == botb) {
                    double tempValue = (double)(topa)/(bota);
                    if(orignalValue == tempValue) {
                        cout << a << "/" << b << " == " << topa << "/" << bota << endl;
                        top*=a;
                        bottom*=b;
                        simplify(top, bottom);
                    }
                }
            }
        }
    }

    cout << top << "/" << bottom << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
