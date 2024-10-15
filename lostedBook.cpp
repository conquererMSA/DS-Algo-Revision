#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> books;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        books.push_back(x);
    }
    int targetBook; cin>>targetBook;
    int foundIndex=-1;
    for(int i=0; i<n; i++){
        if(books[i]==targetBook){
            foundIndex=i;
            break;
        }
    }
    cout<<foundIndex<<endl;
    return 0;
}