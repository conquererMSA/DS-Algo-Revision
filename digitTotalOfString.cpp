#include<bits/stdc++.h>
using namespace std;
int main(){
    string word;
    cin>>word;
    int ans=0;
    for(char c:word){
        if(c>='0' && c<='9'){
            ans+=c-'0';
        }
    }
    cout<<ans<<endl;
    return 0;
}