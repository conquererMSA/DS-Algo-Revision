#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int marks;
    int roll;
    
    Student(string name, int roll, int marks) 
        : name(move(name)), roll(roll), marks(marks) {}
};

class CompareStudent {
public:
    bool operator()(const Student& a, const Student& b) {
        return a.marks < b.marks;  // Min-heap based on marks
    }
};

int main() {
    priority_queue<Student, vector<Student>, CompareStudent> students;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        students.emplace(name, roll, marks);
    }

    // Output the students' names in order of their marks (lowest to highest)
    while(!students.empty()) {
        cout << students.top().name << endl;
        students.pop();
    }

    return 0;
}
