/*********************************************************************
** Program Filename: pattern.cpp
** Author: Martin Hill
** Date: 12/4/22
** Description: prints out a fractal using a recursive function call
** Input: n stars and column col
** Output: asterisk fractal
*********************************************************************/

#include <iostream>
#include <string>

using namespace std;

void pattern(int n, int col){ //n stars   col spaces before largest line

    if (n > 0){

        //call first half
        pattern(n-2, col + 2);

        // A loop to print exactly col columns
        for (int i = 0; i < col; i++) {cout << " ";}

        // A loop to print n asterisks, each one followed by a space:
        for (int i = 0; i < n; i++) {cout << "* ";}

        cout << endl;
        
        //call second half
        pattern(n-2, col + 2);
    }
}

int main(){
    cout << "Enter the number of asterisks, n: ";
    int n;
    cin >> n;
    cout << "Enter the number of columns, c: ";
    int col;
    cin >> col;
    pattern(n,col);
}