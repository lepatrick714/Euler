#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int returnNthTerm(int pos) {
    return (pos*(pos+1))/2;
}

bool binarySearch(const vector<int> collection, const int totalValue) {
    unsigned low = 0, high = collection.size()-1;

    while(high >= low) {
        int mid = (low+high)/2;

        if(totalValue < collection.at(mid))
            high = mid-1;
        else if(totalValue > collection.at(mid))
            low = mid+1;
        else
            return true;
    }
    return false;
}

bool is_triangle(const string temp, vector<int> &collection) {
    int totalValue = 0;

    for(unsigned i=0; i<temp.size(); i++) {
        totalValue += temp[i]-64;
    }

    if(totalValue > collection.at(collection.size()-1)) {
        while(totalValue > collection.at(collection.size()-1)) {
            unsigned currentPos = collection.size();
            collection.push_back(returnNthTerm(currentPos+1));
        }

        if(totalValue == collection.at(collection.size()-1))
            return true;
        return false;
    }
    else {
        return binarySearch(collection, totalValue);
    }
}

int main(int argc, const char**argv)  {
    if(argc != 2) {
        cout << "Not enough arguments!" << endl;
        return -1;
    }

    ifstream input;
    input.open(argv[1]);
    if(!input.is_open()) {
        cout << "ERROR ---- INVALID FILENAME. PLEASE CHECK INPUT" << endl;
        return -1;
    }

    typedef chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();

    vector<int> collection = {1,3,6,10,15,21,28,36,45,55};

    string temp = "";
    unsigned ctr = 0;

    while(getline(input, temp, ',')) {
        temp = temp.substr(1, temp.size()-2);
        if(is_triangle(temp, collection))
            ctr++;
    }

    cout << "Total triangle words: " << ctr << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
