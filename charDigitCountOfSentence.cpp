#include<bits/stdc++.h>
using namespace std;
int main(){
    string sen;
    getline(cin,sen);
    // cout<<sen<<endl;
    int freq[128]={0};
    // cout<<int(' ')<<endl;
    for(char c: sen){
        if(c!=' ') freq[c]++;
    }
    for(char c:sen){
        if(c!=' '&& freq[c]!=0){
            cout<<c<<" : "<<freq[c]<<endl;
        }
        freq[c]=0;
    }
    return 0;
}