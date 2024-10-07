#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    string add;
    Node* prev;
    Node* next;
    Node(string add) {
        this->add = add;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, string add) {
    Node* newNode = new Node(add);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void visitChecking(Node* &current, Node* head, string add) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->add == add) {
            current = temp;
            cout << temp->add << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not Available" << endl;
}

void traverseAndCheck(Node* &current, string cmd) {
    if (cmd == "next") {
        if (current->next == NULL) {
            cout << "Not Available" << endl;
        } else {
            current = current->next;
            cout << current->add << endl;
        }
    } else if (cmd == "prev") {
        if (current->prev == NULL) {
            cout << "Not Available" << endl;
        } else {
            current = current->prev;
            cout << current->add << endl;
        }
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    string add;
    
    while (true) {
        cin >> add;
        if (add == "end") break;
        insertAtTail(head, tail, add);
    }

    int query;
    cin >> query;
    Node* current = head;
    while (query--) {
        string cmd;
        cin >> cmd;
        if (cmd == "visit") {
            cin >> add;
            visitChecking(current, head, add);
        } else {
            traverseAndCheck(current, cmd);
        }
    }
    return 0;
}
