#include<bits/stdc++.h>
using namespace std;
int main(){
    int testCases; cin>>testCases;
    while(testCases--){
        int solvedNumber; cin>>solvedNumber;
        string s; cin>>s; //kun kun problem solve koreche ta string a capital letter e ache, tobekuno letter zodi duibar take ekbar count korbo.
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()),s.end());
        int totalEarnedBallons=solvedNumber+s.size();
        cout<<totalEarnedBallons<<endl;
    }
    return 0;
}