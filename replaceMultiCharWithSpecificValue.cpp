#include <bits/stdc++.h>
using namespace std;
//input:amarXXXsonar banXXXgla desXXXamar bizoyXXX24
//output: amarCCCsonar banCCCgla desCCCamar bizoyCCC24

int main() {
    string sen;
    getline(cin, sen);
    string toFind = "XXX";
    int replaceCount = toFind.size();

    while (true) {
        int startIndex = sen.find(toFind);
        if (startIndex == string::npos) break;
        sen.replace(startIndex, replaceCount, "CCC"); 
    }

    cout << sen << endl;
    return 0;
}
