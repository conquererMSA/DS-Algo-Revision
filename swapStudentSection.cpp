#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    string name;
    int clss;
    char section;
    int id;
};

int main(){
    int arraySize;
    cin>>arraySize;
    Student array[arraySize];
    for(int i=0; i<arraySize; i++){
        cin>>array[i].name>>array[i].clss>>array[i].section>>array[i].id;
    }
    for(int i=0, j=arraySize-1; i<j; i++, j--){
        swap(array[j].section, array[i].section);
    }
    for(int i=0; i<arraySize; i++){
        cout<<array[i].name<<" "<<array[i].clss<<" "<<array[i].section<<" "<<array[i].id<<endl;
    }

    return 0;
}