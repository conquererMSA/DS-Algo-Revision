#include <bits/stdc++.h>
using namespace std;
bool valid(int r, int c, int row, int col) {
    return (r >= 0 && c >= 0 && r < row && c < col);
}

int main() {
    int row, col;
    cin >> row >> col;
    int d2Grid[row][col];
    int midR=row/2, midC=col/2;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i==midR && j==midC) cout<<'X';
            else if((i==midR && (j==midC-2 || j==midC+2)) || j==midC && (i==midR-2 || i==midR+2)) cout<<'*';
            else cout<<'#';
        }
        cout<<endl;
    }
    return 0;
}
