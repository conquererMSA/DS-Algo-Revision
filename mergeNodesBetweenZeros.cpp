#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    list<int> l;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        l.push_back(x);
    }
    list<int> mergedList;
    int total=0; //duito zer er moddhyekar total elem value;
    auto it=next(l.begin(), 1);
    for(it; it!=l.end(); it++){
         if(*it==0){
            mergedList.push_back(total);
            total=0;
         } 
         total+=*it;
    }
    for(int v:mergedList) cout<<v<<" ";
    return 0;
}
/*
15
0 1 4 0 6 3 9 0 3 7 0 4 6 8 0
output:5 18 10 18 
*/