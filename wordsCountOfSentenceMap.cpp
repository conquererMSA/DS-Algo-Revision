#include<bits/stdc++.h>
using namespace std;
int main(){
    string sentence;
    getline(cin, sentence);
    stringstream ss(sentence);
    string word;
    map<string, int> wordCount;
    while(ss>>word){
        wordCount[word]++;
    }
    // cout<<wordCount["na"]<<endl;
    // If we try to access a key by looping, map give us a pair of key-value.
    for(auto it=wordCount.begin(); it!=wordCount.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}