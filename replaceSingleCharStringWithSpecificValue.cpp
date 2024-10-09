#include<bits/stdc++.h>
using namespace std;
//input: amarXsonar bangla desXbizoy24
//output: amar sonar bangla des bizoy24
int main(){
    string sen;
    getline(cin, sen);
    for(int i=0; i<sen.size(); i++){
        if(sen[i]=='X') sen[i]=' ';
    }
    cout<<sen;
    return 0;
}