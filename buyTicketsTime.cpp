#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int index;
    int numOfTicket;
    Node(int index, int numOfTicket) {
        this->index = index;
        this->numOfTicket = numOfTicket;
    }
};

int main() {
    int n;
    cin >> n;
    queue<Node> qu;
    for (int i = 0; i < n; i++) {
        int numOfTicket;
        cin >> numOfTicket;
        qu.push(Node(i, numOfTicket));
    }

    int indexPerson;
    cin >> indexPerson;
    int needTime = 0;

    while (!qu.empty()) {
        Node person = qu.front();
        qu.pop();
        person.numOfTicket--;
        needTime++;

        if (person.index == indexPerson && person.numOfTicket == 0) {
            break;
        }

        if (person.numOfTicket > 0) {
            qu.push(person);
        }
    }

    cout << needTime << endl;
    return 0;
}
