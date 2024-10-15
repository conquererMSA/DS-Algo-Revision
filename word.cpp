#include <bits/stdc++.h>
using namespace std;

int main() {
    string Word1, Word2;
    while (cin >> Word1 >> Word2) {
        auto it = Word1.begin();
        bool isPossible = true;

        for (char ch : Word2) {
            it = find(it, Word1.end(), ch);
            if (it == Word1.end()) {
                isPossible = false;
                break;
            }
            ++it;
        }

        if (isPossible) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
