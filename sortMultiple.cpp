#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    string name;
    int clss;
    char section;
    int id;
    int mathMarks;
    int engMarks;
    int totalMarks;
};

bool sortByMarksThenId(Student a, Student b){
    if(a.totalMarks==b.totalMarks){
        return a.id<b.id;
    }else{
        return a.totalMarks>b.totalMarks;
    }
}

int main(){
    int arraySize;
    cin>>arraySize;
    Student array[arraySize];
    for(int i=0; i<arraySize; i++){
        cin>>array[i].name>>array[i].clss>>array[i].section>>array[i].id>>array[i].mathMarks>>array[i].engMarks;
        array[i].totalMarks=array[i].mathMarks+array[i].engMarks;
    }
    sort(array, array+arraySize, sortByMarksThenId);
    for(int i=0; i<arraySize; i++){
        cout<<array[i].name<<" "<<array[i].clss<<" "<<array[i].section<<" "<<array[i].id<<" "<<array[i].mathMarks<<" "<<array[i].engMarks<<endl;
    }

    return 0;
}