#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int freq[128] = {0};

    for(char c : s) {
        freq[c]++;
    }

    for(char c : s) {
        if(freq[c] != 0) {
            cout << c << " -> " << freq[c] << endl;
            freq[c] = 0;
        }
    }

    return 0;
}
