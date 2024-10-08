#include<bits/stdc++.h>
using namespace std;
int main(){
    int sz, delPosition;
    cin>>sz>>delPosition;
    queue<int> q;
    for(int i=1; i<=sz; i++){
        q.push(i);
    }
    int delCount=0;
    while(q.size()>1){
       int v=q.front();
       q.pop();
       delCount++;
       if(delCount==delPosition){
           delCount=0;
       } else {
        q.push(v);
       }
    }
    cout<<q.front()<<endl;
    return 0;
}