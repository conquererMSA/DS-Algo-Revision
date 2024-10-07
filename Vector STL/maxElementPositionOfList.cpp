#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    list<int> myList;
    for(int i=0; i<n; i++){
        int e;
        cin>>e;
        myList.push_back(e);
    }
    //max_element function max umber er pointer retur kore.
    auto maxNum=max_element(myList.begin(), myList.end());
    cout<<*maxNum<<endl;
    //position of maxNum
    cout<<distance(myList.begin(), maxNum)+1;
    return 0;
}