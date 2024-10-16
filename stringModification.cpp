#include<bits/stdc++.h>
using namespace std;

bool sortByCountThenAlphabetic(pair<char,int> a, pair<char,int> b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int frequencyArray[26] = {0};
    for (char c : str) {
        frequencyArray[c - 'a']++;
    }

    vector<pair<char, int>> countedChar;
    for (char c : str) {
        if (frequencyArray[c - 'a'] > 0) {
            countedChar.push_back({c, frequencyArray[c - 'a']});
            frequencyArray[c - 'a'] = 0; // Remove this line if you want to keep the frequency information
        }
    }

    sort(countedChar.begin(), countedChar.end(), sortByCountThenAlphabetic);

    for (pair<char, int> p : countedChar) {
        cout << p.first << " " << p.second << endl;
    }
    string modifiedStr="";
    for(int i=0; i<countedChar.size(); i++){
       for(int j=1; j<=countedChar[i].second; j++){
             modifiedStr+=countedChar[i].first;
       }
    }
    cout<<modifiedStr<<endl;
    return 0;
}