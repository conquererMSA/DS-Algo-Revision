#include <bits/stdc++.h>
using namespace std;
//h!c9!D*x% X#Z+-@X41 9H^^*$h$cC
int main() {
    string sentence;
    getline(cin, sentence);

    // 128 is used because ASCII values range from 0 to 127.
    int frequency[128] = {0};

    for (char ch : sentence) {
        // Check if the character is a special character.
        if ((ch >= 33 && ch <= 47) || 
            (ch >= 58 && ch <= 64) || 
            (ch >= 91 && ch <= 96) || 
            (ch >= 123 && ch <= 126)) {
            frequency[ch]++;
        }
    }
    for (char ch : sentence) {
        if (frequency[ch] > 0) {
            cout << ch <<" : "<< frequency[ch]<< endl;
            frequency[ch] = 0;
        }
    }
    return 0;
}
