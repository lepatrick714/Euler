#include <stdio.h>

int Calc_Fib (int numA[], int numB[], int temp[], int index) {
    int i = 0;

    //Check 1000th digit for non-zero value.
    if (numB[999] != 0) return index;

    //Add arrays A and B vertically.
    for (i = 0; i < 1000; ++i)   {
        temp[i] += (numA[i] + numB[i]);

        if (temp[i] > 9)   {
            temp[i + 1] = temp[i] / 10;
            temp[i] %= 10;
        }

        numA[i] = numB[i];
        numB[i] = temp[i];
        temp[i] = 0;
    }
    Calc_Fib(numA, numB, temp, ++index);
}

int main()  {
    int numA[1000];   //Holds previous term.
    int numB[1000];   //Holds current term.
    int temp[1000];   //Holds temporary number for vertical addition.
    int i        = 0;
    int indexVal = 2;

    for (i = 0; i < 1000; ++i)  {
        numA[i] = 0;
        numB[i] = 0;
        temp[i] = 0;
    }

    //Initialize first two terms.
    numA[0] = (numB[0] = 1);

    indexVal = Calc_Fib(numA, numB, temp, indexVal);

    printf("Tada: %d\n", indexVal);

    return 0;
}
