#include <bits/stdc++.h>
using namespace std;
int main() {
    int len = 100001;
    char s[len];
    while (cin.getline(s, len)) {
        int frArr[26] = {0};
        for (int i = 0; s[i] != '\0'; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                frArr[s[i] - 'a']++;
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < frArr[i]; ++j) {
                cout << (char)('a' + i); 
            }
        }
        cout << '\n';
    }

    return 0;
}