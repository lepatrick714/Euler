#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char**argv) {
    if(argc != 2) {
        cout << "Not enough arguments!" << endl;
        return 1;
    }

    int row;
    int col;
    ifstream file;
    file.open(argv[1]);
    if(!file.is_open()) {
        cout << "ERROR----INVALID FILENAME. PLEASE CHECK FOR SPELLING" << endl;
        return 1;
    }

    //Grabbing rows and cols
    string temp;
    getline(file, temp);
    stringstream c(temp);
    c >> row;
    getline(file, temp);
    stringstream d(temp);
    d >> col;
    //End of grabbing rows and cols

    int arr[row][col];
    int rowCtr = 0;
    int colCtr = 0;
    while(getline(file, temp)) {
        int number;
        stringstream convert(temp);
        while(convert >> number) {
            arr[rowCtr][colCtr] = number;
            colCtr++;
        }
        rowCtr++;
        colCtr = 0;
    }

    //Finding the best Right
    long BestRight = 0;
    for(unsigned i=0; i<row; i++) {
        for(unsigned j=0; j<col-3; j++) {
            int tempNumber = arr[i][j] * arr[i][j+1] * arr[i][j+2] * arr[i][j+3];
            if(tempNumber > BestRight) {
                //cout << arr[i][j] << " " << arr[i][j+1] << " " << arr[i][j+2] << " " << arr[i][j+3] << endl;;
                BestRight = tempNumber;
            }
        }
    }
    cout << "Printing Right: " <<  BestRight << endl;
    //End of Finding the Best Right

    //Finding the Best down
    long BestDown = 0;
    for(unsigned i=0; i<row-3; i++) {
        for(unsigned j=0; j<col; j++) {
            int tempNumber = arr[i][j] * arr[i+1][j] * arr[i+2][j] * arr[i+3][j];
            if(tempNumber > BestDown) {
                //cout << arr[i][j] << " " << arr[i+1][j] << " " << arr[i+2][j] << " " << arr[i+3][j] << endl;;
                BestDown = tempNumber;
            }
        }
    }
    cout << "Printing Down: " << BestDown << endl;
    //End of Finding the Best Down

    //Finding the Best RightDiagonal
    long BestRightDia = 0;
    for(unsigned i=0; i<row-3; i++) {
        for(unsigned j=0; j<col-3; j++) {
            int tempNumber = arr[i][j] * arr[i+1][j+1] * arr[i+2][j+2] * arr[i+3][j+3];
            if(tempNumber > BestRightDia) {
                //cout << arr[i][j] << " " << arr[i+1][j+1] << " " << arr[i+2][j+2] << " " << arr[i+3][j+3] << endl;
                BestRightDia = tempNumber;
            }
        }
    }
    cout << "Printing BestRightDia: " << BestRightDia << endl;
    //End of Finding the Best RightDiagonala

    //Finding the BestLeftDiagonal
    long BestLeftDia = 0;
    for(unsigned i=0; i<row-3; i++) {
        for(unsigned j=3; j<col; j++) {
            int tempNumber = arr[i][j] * arr[i+1][j-1] * arr[i+2][j-2] * arr[i+3][j-3];
            if(tempNumber > BestLeftDia) {
                //cout << arr[i][j] << " " << arr[i+1][j-1] << " " << arr[i+2][j-2] << " " << arr[i+3][j-3] << endl;
                BestLeftDia = tempNumber;
            }
        }
    }
    cout << "Printing BestLeftDia: " << BestLeftDia << endl;
    //End of Finding the Best LeftDiagonal

    int BestOverall = BestRight;
    if(BestOverall < BestDown) {
        BestOverall = BestDown;
    }
    if(BestOverall < BestRightDia) {
        BestOverall = BestRightDia;
    }
    if(BestOverall < BestLeftDia) {
        BestOverall = BestLeftDia;
    }
    cout << "Printing BestOverall: " << BestOverall << endl;
    return 0;
}
