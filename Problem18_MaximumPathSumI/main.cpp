#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int returnLargest(vector<vector<int> > a) {
    int result = 0;

    for(int i=a.size()-2; i>=0; i--) {
        for(int j=0; j<a.at(i).size(); j++) {
            int temp1 = a.at(i).at(j) + a.at(i+1).at(j);
            int temp2 = a.at(i).at(j) + a.at(i+1).at(j+1);

            if(temp1>temp2) {
                a.at(i).at(j) = temp1;
            }
            else {
                a.at(i).at(j) = temp2;
            }
        }
    }

    /*
    for(int i=a.size()-2; i>=0; i--) {
        for(int j=0; j<a.at(i).size(); j++) {
            cout << a.at(i).at(j) << " ";
        }
        cout << endl;
    }
    */
    result = a.at(0).at(0);
    return result;
}

int main(int argc, const char**argv)  {
    typedef chrono::high_resolution_clock Clock;

    auto t1 = Clock::now();
    if(argc != 2) {
        cout << "Invalid number of args in command line" << endl;
        return 1;
    }

    ifstream file;
    file.open(argv[1]);

    if(!file.is_open()) {
        cout << "ERROR----Invalid File Name" << endl;
        return 1;
    }

    string temp = "";
    vector<vector<int> > vectorTree;

    while(getline(file, temp)) {
        stringstream convert(temp);
        int number = 0;
        vector<int> tempVec;
        while(convert >> number) {
            tempVec.push_back(number);
        }
        vectorTree.push_back(tempVec);
    }

    /*
    for(unsigned i=0; i<vectorTree.size(); i++) {
        for(unsigned j=0; j<vectorTree.at(i).size(); j++) {
            cout << vectorTree.at(i).at(j) << " ";
        }
        cout << endl;
    }
    */
    cout << "The sum of the largest path is: " << returnLargest(vectorTree) << endl;

    auto t2 = Clock::now();
    chrono::milliseconds ns = chrono::duration_cast<chrono::milliseconds>(t2-t1);
    cout << ns.count() << " milliseconds" << endl;
    return 0;
}
