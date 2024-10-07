#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    list<int> l;
    for(int i=0; i<n; i++){
        int e;
        cin>>e;
        l.push_back(e);
    }
    int num;
    cin>>num;
    //find iterator return kore
    auto it=find(l.begin(), l.end(),num);
    if(it!=l.end()) cout<<distance(l.begin(), it);
    else cout<<num<< " "<<"does not exist"<<endl;
    /*
    8
    1 4 7 3 9 3 0 2
    99
    */
    return 0;
}