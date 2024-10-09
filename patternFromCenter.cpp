#include <bits/stdc++.h>
using namespace std;
/*
9 9
3

output:
#########
#*******#
#*******#
#*******#
#***X***#
#*******#
#*******#
#*******#
#########

*/
int main() {
    int row, col, distance;
    cin >> row >> col >> distance;
    
    int midR = row / 2, midC = col / 2;
    int starStartR = midR - distance;
    int starEndR = midR + distance;
    int starStartC = midC - distance;
    int starEndC = midC + distance;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == midR && j == midC) {
                cout << 'X';
            } else if (i >= starStartR && i <= starEndR && j >= starStartC && j <= starEndC) {
                cout << '*';
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }
    
    return 0;
}