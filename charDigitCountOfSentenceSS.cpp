#include<bits/stdc++.h>
using namespace std;
//hc9Dx XZX41 9HhcC
int main(){
    string sentence;
    getline(cin, sentence);
    string word;
    stringstream ss(sentence);
    while(ss>>word){
        int freq[128]={0};
        for(char c:word){
            freq[c]++;
        }
        for(char c:word){
            if(freq[c]!=0){
                cout<<c<<" : "<<freq[c]<<endl;
            }
            freq[c]=0;
        }
        cout<<"******"<<endl;
    }

    return 0;
}