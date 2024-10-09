#include <bits/stdc++.h>
using namespace std;
/*
input: 5
output:
        __
        |
      __
      |
    __
    |
  __
  |
__
|

*/
int main() {
    int n;
    cin>>n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << "  ";
        }
        cout << "__\n";
        for (int j = 0; j < n - i - 1; j++) {
            cout << "  ";
        }
        cout << "|\n";
    }

    return 0;
}
/*
down stairs code 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int size = 5;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        cout << "__\n";
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        cout << "|\n";
    }
    return 0;
}


*/
