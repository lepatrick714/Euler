#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;

const vector<string> oneToTenCollection = {"one", "two", "three", "four", "five", "six", "seven", "eight",
                                        "nine", "ten"};
const vector<string> eleventToNineteenCollection = {"eleven", "twelve", "thirteen", "fourteen", "fifteen",
                                                        "sixteen", "seventeen", "eighteen", "nineteen"};
const vector<string> regulartwoDigitStart = {"twenty", "thirty", "forty", "fifty",
                                                "sixty", "seventy", "eighty", "ninety"};
const string hundred = "hundred";
const string thousand = "thousand";
const string And = "and";

long returnNumWords(int limit) {
    long result = 0;
    int ctr = 0;
    int tempCtr = -1;
    int temptempCtr = 0;
    for(unsigned i=0; i<=limit; i++) {
        if(i<10) {
            //cout << "Adding: " << oneToTenCollection.at(i) << endl;
            result+=oneToTenCollection.at(i).size();
        }
        else if(i>10 && i<20) {
            //cout << "Adding: " << eleventToNineteenCollection.at(ctr) << endl;
            result+=eleventToNineteenCollection.at(ctr).size();
            ctr++;
            if(ctr >= 9) {
                ctr = 0;
            }
        }
        else if(i>=20 && i<100) {
            if(tempCtr < 0) {
                //cout << "Adding: " << regulartwoDigitStart.at(ctr) << endl;
                result+=regulartwoDigitStart.at(ctr).size();
                tempCtr++;
            }
            else {
                //cout << "Adding: " << regulartwoDigitStart.at(ctr) << oneToTenCollection.at(tempCtr) << endl;
                result+=regulartwoDigitStart.at(ctr).size();
                result+=oneToTenCollection.at(tempCtr).size();
                tempCtr++;

                if(tempCtr >= 9) {
                    tempCtr = -1;
                    ctr++;
                }
                if(ctr >= 9) {
                    ctr = 0;
                }
            }
            if(ctr >= 8) {
                ctr = 0;
                tempCtr=0;
            }
        }
        else if(i>=100 && i<1000) {
            if(i%100 == 0) {
                //cout << "Adding: " << oneToTenCollection.at(ctr) << hundred << endl;
                result+=oneToTenCollection.at(ctr).size();
                result+=hundred.size();
            }
            else if(i%100<11) {
                //cout << "Adding: " << oneToTenCollection.at(ctr) << hundred << And << oneToTenCollection.at(tempCtr) << endl;
                result+=oneToTenCollection.at(ctr).size();
                result+=hundred.size();
                result+=And.size();
                result+=oneToTenCollection.at(tempCtr).size();
                tempCtr++;
                if(tempCtr>=10) {
                    tempCtr=0;
                }
            }
            else if(i%100>=11 && i%100<20) {
                //cout << "Adding: " << oneToTenCollection.at(ctr) << hundred << And << eleventToNineteenCollection.at(tempCtr) << endl;

                result+=oneToTenCollection.at(ctr).size();
                result+=hundred.size();
                result+=And.size();
                result+=eleventToNineteenCollection.at(tempCtr).size();
                tempCtr++;
                if(tempCtr>=9) {
                    tempCtr=0;
                }
            }
            else if(i%100>=20 && i%100<100) {
                int temp = i%100;
                if(temp%10 == 0) {
                    //cout << "Adding: " << oneToTenCollection.at(ctr) << hundred << And << regulartwoDigitStart.at(tempCtr) << endl;
                    result+=oneToTenCollection.at(ctr).size();
                    result+=hundred.size();
                    result+=And.size();
                    result+=regulartwoDigitStart.at(tempCtr).size();
                }
                else {
                    //cout << "Adding: " << oneToTenCollection.at(ctr) << hundred << And << regulartwoDigitStart.at(tempCtr) << oneToTenCollection.at(temptempCtr) << endl;
                    result+=oneToTenCollection.at(ctr).size();
                    result+=hundred.size();
                    result+=And.size();
                    result+=regulartwoDigitStart.at(tempCtr).size();
                    result+=oneToTenCollection.at(temptempCtr).size();

                    temptempCtr++;
                    if(temptempCtr>=9) {
                        tempCtr++;
                        temptempCtr = 0;
                    }
                }

                if(tempCtr >= 8) {
                    tempCtr = 0;
                    ctr++;
                }
            }
        }
    }
    if(limit == 1000) {
        result += 11;
    }

    return result;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;

    int limit = 1;
    cout << "Please enter the limit: ";
    cin >> limit;

    auto t1 = Clock::now();
    cout << "The total number words from 1 to " << limit << " is: " << returnNumWords(limit) << endl;


    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
