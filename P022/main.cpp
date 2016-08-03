#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    if(argc!=2) {
        cout << "INVALID NUMBER OF PARAMETERS" << endl;
        return 1;
    }

    ifstream txt;
    txt.open(argv[1]);
    if(!txt.is_open()) {
        cout << "ERROR----INVALID FILENAME. PLEASE CHECK FOR SPELLING" << endl;
        return 1;
    }

    ofstream out;
    string outFile = "output.txt";
    out.open(outFile.c_str());

    string temp;
    vector<string> collection;
    while(txt >> temp) {
        temp+=",";
        string newTemp = "";
        for(string::iterator i = temp.begin(); i!=temp.end(); i++) {
            if(*i != '"' && *i != ' ' && *i != ',') {
                newTemp += *i;
            }
            else if(*i == ',') {
                transform(newTemp.begin(), newTemp.end(), newTemp.begin(), ::toupper);
                collection.push_back(newTemp);
                newTemp = "";
            }
        }
    }

    sort(collection.begin(), collection.end());

    long total = 0;
    for(unsigned i=0; i<collection.size(); i++) {
        unsigned wordTotal = 0;
        for(char c : collection.at(i)) {
            wordTotal+=static_cast<int>(c)-64;
        }
        total += wordTotal*(i+1);
    }
    cout << "Word Score: " << total << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
