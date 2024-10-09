// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     string word;
//     cin>>word;
//     vector<int> frequency(26, 0);

//     for (char c : word) {
//         frequency[c - 'a']++;
//     }
//     //alphabeticOrder;
//     // for (int i = 0; i < 26; i++) {
//     //     if (frequency[i] > 0) {
//     //         cout << char(i + 'a') << " : " << frequency[i] << endl;
//     //     }
//     // }
//     for(int i=0; i<word.size(); i++){

//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
//mdatzikkhanz , without space
int main() {
    string s;
    cin>>s;
    int freq[26] = {0};

    for(char c : s) {
        freq[c - 'a']++;
    }

    for(char c : s) {
        if(freq[c - 'a'] != 0) {
            cout << c << " -> " << freq[c - 'a'] << endl;
            freq[c - 'a'] = 0;
        }
    }

    return 0;
}


